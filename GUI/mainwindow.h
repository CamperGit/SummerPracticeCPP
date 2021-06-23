#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <user.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    User getCurrentUser();
    void setCurrentUser();
    QVector<User> getUsers();
    MainWindow(User& currentUser,QVector<User>& users,QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_comboBox_activated(const QString &arg1);

private:
    User currentUser;
    QVector<User> users;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
