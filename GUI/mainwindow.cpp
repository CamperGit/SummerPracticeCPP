#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QDialog>
#include <QFormLayout>
#include <QDialogButtonBox>
#include <inputdialog.h>
#include <user.h>
#include <message.h>
#include <QtGui>
#include <QErrorMessage>
#include <QMessageBox>

QVector<User> MainWindow::getUsers()
{
    return users;
}

MainWindow::MainWindow(User& currentUser,QVector<User>& users,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->currentUser = currentUser;
    this->users = users;
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_comboBox_activated(const QString &arg1)
{

}


void MainWindow::on_registrationButton_clicked()
{
    bool ok;
    QStringList list = InputDialog::getStrings(this, &ok);
    if (ok) {
        QString username = list[0];
        QString password = list[1];
        if (password.isEmpty() || username.isEmpty())
        {
            QMessageBox::warning(this,"Ошибка регистрации","Пароль и логин не могут быть пустыми!",0,1);
            return;
        } else {
            for(int i = 0; i < users.size();i++)
            {
                if(users[i].getLogin() == username)
                {
                    QMessageBox::warning(this,"Ошибка регистрации","Пользователь с таким логином уже существует!",0,1);
                    return;
                }
            }
            User newUser(username,password);
            users.push_back(newUser);
            currentUser = newUser;
            ui->comboBox->addItem(username);

            ui->comboBox->setEnabled(true);
            ui->subjectLineEdit->setEnabled(true);
            ui->messageTextArea->setEnabled(true);
            ui->sendButton->setEnabled(true);
        }
    }
}


void MainWindow::on_sendButton_clicked()
{
    QString messageText = ui->messageTextArea->toPlainText();
    if (messageText.isEmpty())
    {
        QMessageBox::warning(this,"Ошибка отправки сообщения","Текст сообщения не может быть пустым!",0,1);
        return;
    } else {
        messageText.replace("\n"," ");
    }


    QDateTime currentTime = QDateTime::currentDateTime();


    QString subjectText = ui->subjectLineEdit->text();
    if (subjectText.isEmpty())
    {
        QMessageBox::warning(this,"Ошибка отправки сообщения","Тема сообщения не может быть пустой!",0,1);
        return;
    }


    QString toLoginText = ui->comboBox->currentText();
    if (toLoginText == currentUser.getLogin())
    {
        QMessageBox::warning(this,"Ошибка отправки сообщения","Нельзя отправить сообщение самому себе!",0,1);
        return;
    }


    QString fromLoginText = currentUser.getLogin();
    if (fromLoginText.isEmpty())
    {
        QMessageBox::warning(this,"Ошибка отправки сообщения","Войдите или зарегестрируйтесь, чтобы отправлять сообщения!",0,1);
        return;
    }

    Message newMessage(messageText,currentTime,subjectText,fromLoginText,toLoginText);
    for(int i = 0; i< users.size();i++)
    {
        if (users[i].getLogin() == toLoginText)
        {
            users[i].addMessage(newMessage);
        }
    }

    /*ui->messageTextArea->append("\n\n");
    ui->messageTextArea->append(messageText);
    ui->messageTextArea->append(currentTime.toString("yyyy-MM-dd  HH:mm:ss"));
    ui->messageTextArea->append(subjectText);
    ui->messageTextArea->append(fromLoginText);
    ui->messageTextArea->append(toLoginText);*/

}


void MainWindow::on_loginButton_clicked()
{
    bool ok;
    QStringList list = InputDialog::getStrings(this, &ok);
    if (ok) {
        QString username = list[0];
        QString password = list[1];
        if (password.isEmpty() || username.isEmpty())
        {
            QMessageBox::warning(this,"Ошибка авторизации","Пароль и логин не могут быть пустыми!",0,1);
            return;
        } else if(User::verification(users,username,password)){
            for (int i = 0; i < users.size();i++)
            {
                if(users[i].getLogin() == username && users[i].getPassword() == password)
                {
                    currentUser = users[i];
                    ui->comboBox->setEnabled(true);
                    ui->subjectLineEdit->setEnabled(true);
                    ui->messageTextArea->setEnabled(true);
                    ui->sendButton->setEnabled(true);

                    //QWidget *widget = new QWidget;
                    QHBoxLayout *lineHBox = new QHBoxLayout(ui->messageList);
                    QLabel *userLabel = new QLabel(currentUser.getLogin());
                    QVector<Message> messages = currentUser.getMessages();
                    for(int j = 0; j < messages.size();j++)
                    {
                        QLabel *messageTimeLabel = new QLabel(messages[j].getSendTime().toString("yyyy-MM-dd  HH:mm:ss"));
                        lineHBox->addWidget(userLabel);
                        lineHBox->addWidget(messageTimeLabel);

                        QListWidgetItem *itm = new QListWidgetItem;
                        //QVariant line  = QVariant::fromValue(messages[j]);
                        itm->setData(0,QVariant::fromValue(lineHBox));
                        ui->messageList->addItem(itm);
                        //ui->messageList->addItem()
                        //ui->messageList->addItem(messages[i].getSubject());
                    }
                    return;
                }
            }
        } else {
            QMessageBox::warning(this,"Ошибка авторизации","Неверное имя пользователя или пароль!",0,1);
        }
    }
}

