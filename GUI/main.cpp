#include "mainwindow.h"

#include <QApplication>
#include <QVector>
#include <QString>
#include "user.h"

QVector<User> users;
void loadUsers(QVector<User> usersList,QString saveDir);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    loadUsers(users,"");

    w.show();
    return a.exec();
}

void loadUsers(QVector<User> usersList,QString saveDir)
{

}
