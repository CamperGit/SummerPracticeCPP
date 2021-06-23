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


void MainWindow::on_sendButton_clicked()
{
    QString messageText = ui->messageTextArea->toPlainText();
    if (messageText.isEmpty())
    {
        QErrorMessage errorMessage;
        errorMessage.showMessage("Текст сообщения не может быть пустым!");
        errorMessage.exec();
        return;
    } else {
        messageText.replace("\n"," ");
    }


    QDateTime currentTime = QDateTime::currentDateTime();


    QString subjectText = ui->subjectLineEdit->text();
    if (subjectText.isEmpty())
    {
        QErrorMessage errorMessage;
        errorMessage.showMessage("Тема сообщения не может быть пустой!");
        errorMessage.exec();
        return;
    }


    QString toLoginText = ui->comboBox->currentText();
    if (toLoginText == currentUser.getLogin())
    {
        QErrorMessage errorMessage;
        errorMessage.showMessage("Нельзя отправить сообщение самому себе!");
        errorMessage.exec();
        return;
    }


    QString fromLoginText = currentUser.getLogin();
    if (fromLoginText.isEmpty())
    {
        QErrorMessage errorMessage;
        errorMessage.showMessage("Войдите или зарегестрируйтесь, чтобы отправлять сообщения!");
        errorMessage.exec();
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

