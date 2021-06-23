#include "mainwindow.h"

#include <QApplication>
#include <QVector>
#include <QString>
#include "user.h"
#include <inputdialog.h>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>

void saveUsers(QVector<User> usersList);
void loadUsers(QVector<User> &usersList);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QVector<User> users;
    User currentUser;
    loadUsers(users);

    MainWindow w(currentUser,users);
    w.show();

    int exit = a.exec();
    saveUsers(w.getUsers());
    return exit;
}

void saveUsers(QVector<User> usersList)
{
    QJsonObject saveObject;
    saveObject;

    QJsonArray usersArray;

    for(int i = 0; i < usersList.size();i++)
    {
        User userToSave = usersList[i];
        QJsonObject userJsonObject;

        userJsonObject.insert("login",userToSave.getLogin());
        userJsonObject.insert("password",userToSave.getPassword());

        QVector<Message> messages = userToSave.getMessages();
        QJsonArray messagesArray;
        for(int j = 0; j < messages.size();j++)
        {
            Message messageToSave = messages[j];
            QJsonObject messageJsonObject;

            messageJsonObject.insert("text",messageToSave.getText());
            messageJsonObject.insert("time",messageToSave.getSendTime().toString("yyyy-MM-dd  HH:mm:ss"));
            messageJsonObject.insert("subject",messageToSave.getSubject());
            messageJsonObject.insert("senderLogin",messageToSave.getSenderLogin());
            messageJsonObject.insert("receiverLogin",messageToSave.getReceiverLogin());

            messagesArray.push_back(messageJsonObject);
        }
        userJsonObject.insert("messages", messagesArray);

        usersArray.push_back(userJsonObject);
    }

    saveObject.insert("users",usersArray);

    QJsonDocument doc(saveObject);
    QString jsonString = doc.toJson(QJsonDocument::Indented);

    QFile file;
    file.setFileName("save.json");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
          QTextStream stream( &file );
          stream << jsonString;
                file.close();
}
void loadUsers(QVector<User> &usersList)
{
    if(QFile("save.json").exists())
    {
        QString val;
        QFile file;
        file.setFileName("save.json");
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        val = file.readAll();
        file.close();

        QJsonDocument doc = QJsonDocument::fromJson(val.toUtf8());
        QJsonObject json = doc.object();

        QJsonArray usersArray = json["users"].toArray();
        for(int i = 0; i < usersArray.size();i++)
        {
            QJsonObject userJsonObject = usersArray[i].toObject();

            QString login = userJsonObject["login"].toString();
            QString password = userJsonObject["password"].toString();

            QVector<Message> messages;
            QJsonArray messagesArray = userJsonObject["messages"].toArray();
            for(int j = 0;j < messagesArray.size();j++)
            {
                QJsonObject messageJsonObject = messagesArray[j].toObject();

                QString text = messageJsonObject["text"].toString();
                QDateTime time = QDateTime::fromString(messageJsonObject["time"].toString(),"yyyy-MM-dd  HH:mm:ss");
                QString subject = messageJsonObject["subject"].toString();
                QString senderLogin = messageJsonObject["senderLogin"].toString();
                QString receiverLogin = messageJsonObject["receiverLogin"].toString();

                Message loadedMessage(text,time,subject,senderLogin,receiverLogin);
                messages.push_back(loadedMessage);
            }

            User loadedUser(login,password,messages);
            usersList.push_back(loadedUser);
        }
    }
}


