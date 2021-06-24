#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QDialog>
#include <QFormLayout>
#include <QDialogButtonBox>
#include <inputdialog.h>
#include <user.h>
#include <message.h>
#include "messagefilter.h"
#include "messagereader.h"
#include <QtGui>
#include <QErrorMessage>
#include <QMessageBox>
#include <QVariant>

int MainWindow::addMessagesToMessageList(QVector<Message> messagesToAdd)
{
    int counter = 0;
    ui->messageList->clear();

    for(int j = 0; j< messagesToAdd.size(); j++)
    {
        Message messageToShow = messagesToAdd[j];
        QWidget *line = new QWidget;
        QLayout *vbox = new QVBoxLayout;
        vbox->setSpacing(0);

        QLabel *senderLogin = new QLabel(messageToShow.getSenderLogin());
        QLabel *timeLabel = new QLabel(messageToShow.getSendTime().toString("yyyy-MM-dd  HH:mm"));
        QLabel *subjectLabel = new QLabel(messageToShow.getSubject());

        QWidget *hboxWidget = new QWidget;
        QLayout *hbox = new QHBoxLayout;
        hbox->addWidget(senderLogin);
        hbox->addWidget(timeLabel);
        hboxWidget->setLayout(hbox);

        vbox->addWidget(hboxWidget);
        vbox->addWidget(subjectLabel);

        QFrame *separatorLine = new QFrame(this);
        separatorLine->setFrameShape(QFrame::HLine);
        separatorLine->setFrameShadow(QFrame::Sunken);
        separatorLine->setLineWidth(2);
        vbox->addWidget(separatorLine);

        line->setLayout(vbox);
        line->setProperty("message",QVariant::fromValue(messageToShow));
        QListWidgetItem *item = new QListWidgetItem(ui->messageList);
        item->setSizeHint(line->sizeHint());
        ui->messageList->setItemWidget(item,line);
        counter++;
    }
    return counter;
}

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
    int size;
    if((size = users.size()) != 0)
    {
        for(int i = 0; i < size; i++)
        {
            ui->comboBox->addItem(users[i].getLogin());
        }
    }
    ui->usernameLabel->setVisible(false);
    ui->logoutButton->setVisible(false);
    ui->loginButton->setVisible(true);
    ui->registrationButton->setVisible(true);
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
                QString forbidden = "-&=+,<>'";
                if(username.size()>18)
                {
                    QMessageBox::warning(this,"Ошибка регистрации","Слишком длинное имя пользователя!",0,1);
                    return;
                }
                if(users[i].getLogin() == username)
                {
                    QMessageBox::warning(this,"Ошибка регистрации","Пользователь с таким логином уже существует!",0,1);
                    return;
                }
                for(int i = 0; i < username.size();i++)
                {
                    if(username[i]=='-'||username[i]=='&'||username[i]=='+'||username[i]=='='||username[i]==','||username[i]=='<'||username[i]=='>')
                    {
                        QMessageBox::warning(this,"Ошибка регистрации","Имя пользователя содержит недопустимые символы!",0,1);
                        return;
                    }
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
            ui->messageList->clear();

            ui->usernameLabel->setVisible(true);
            ui->logoutButton->setVisible(true);
            ui->loginButton->setVisible(false);
            ui->registrationButton->setVisible(false);
            ui->usernameLabel->setText(currentUser.getLogin());
        }
    }
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

                    addMessagesToMessageList(currentUser.getMessages());
                    ui->usernameLabel->setVisible(true);
                    ui->logoutButton->setVisible(true);
                    ui->loginButton->setVisible(false);
                    ui->registrationButton->setVisible(false);
                    ui->usernameLabel->setText(currentUser.getLogin());
                    return;
                }
            }
        } else {
            QMessageBox::warning(this,"Ошибка авторизации","Неверное имя пользователя или пароль!",0,1);
            return;
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
    if (subjectText.size()>35)
    {
        QMessageBox::warning(this,"Ошибка отправки сообщения","Размер темы содержит слишком много символов!",0,1);
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
            ui->subjectLineEdit->setText("");
            ui->messageTextArea->setText("");
            QMessageBox::information(this,"","Сообщение пользователю " + toLoginText + " отправлено!");
            return;
        }
    }

}

void MainWindow::on_messageList_itemClicked(QListWidgetItem *item)
{
    QWidget *lineWidget = ui->messageList->itemWidget(item);
    QVariant messageVar = lineWidget->property("message");
    if(messageVar.canConvert<Message>())
    {
        Message message = messageVar.value<Message>();
        QString text = message.getText();
        QString time = message.getSendTime().toString("yyyy-MM-dd  HH:mm");
        QString subject = message.getSubject();
        MessageReader window(text,time,subject);
        window.setModal(true);
        window.exec();
    } else {
        //error
    }
}


void MainWindow::on_alphabetUpDownSortButton_clicked()
{
    QVector<Message> messages = currentUser.getMessages();
    MessageFilter::filterByAlphabetBigToSmall(messages);
    addMessagesToMessageList(messages);
}

void MainWindow::on_alphabetDownUpSortButton_clicked()
{
    QVector<Message> messages = currentUser.getMessages();
    MessageFilter::filterByAlphabetSmallToBig(messages);
    addMessagesToMessageList(messages);
}

void MainWindow::on_timeDownUpSortButton_clicked()
{
    QVector<Message> messages = currentUser.getMessages();
    MessageFilter::filterByTimeSmallToBig(messages);
    addMessagesToMessageList(messages);
}


void MainWindow::on_timeUpDownSortButton_clicked()
{
    QVector<Message> messages = currentUser.getMessages();
    MessageFilter::filterByTimeBigToSmall(messages);
    addMessagesToMessageList(messages);
}

void MainWindow::on_logoutButton_clicked()
{
    ui->usernameLabel->setVisible(false);
    ui->logoutButton->setVisible(false);
    ui->loginButton->setVisible(true);
    ui->registrationButton->setVisible(true);
    ui->messageTextArea->setEnabled(false);
    ui->subjectLineEdit->setEnabled(false);
    currentUser = User();
}

