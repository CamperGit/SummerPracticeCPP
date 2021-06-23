#include "mainwindow.h"

#include <QApplication>
#include <QVector>
#include <QString>
#include "user.h"
#include <inputdialog.h>

QVector<User> users;
User currentUser;

void loadUsers(QVector<User> usersList,QString saveDir);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    loadUsers(users,"");

    MainWindow w(currentUser,users);
    w.show();
    return a.exec();
}

void loadUsers(QVector<User> usersList,QString saveDir)
{

}
