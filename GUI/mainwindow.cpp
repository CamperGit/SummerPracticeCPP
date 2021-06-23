#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QDialog>
#include <QFormLayout>
#include <QDialogButtonBox>
#include <inputdialog.h>
#include <user.h>
#include <message.h>
//#include <main.cpp>

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
    }
}


void MainWindow::on_sendButton_clicked()
{
    QString messageText = ui->messageTextArea->toPlainText();
    messageText.replace("\n"," ");
    QDateTime currentTime = QDateTime::currentDateTime();
    QString subjectText = ui->subjectLineEdit->text();
    QString toLoginText = ui->comboBox->currentText();
    QString fromLoginText = currentUser.getLogin();

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

