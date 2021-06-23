#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QDialog>
#include <QFormLayout>
#include <QDialogButtonBox>
#include <inputdialog.h>
#include <user.h>
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

