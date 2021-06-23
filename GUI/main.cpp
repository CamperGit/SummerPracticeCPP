#include "mainwindow.h"

#include <QApplication>
#include <QVector>
#include <QString>
#include "user.h"
#include <inputdialog.h>



void saveUsers(QVector<User> usersList);
void loadUsers(QVector<User> usersList);

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
    int x = 0;
}
void loadUsers(QVector<User> usersList)
{

}


