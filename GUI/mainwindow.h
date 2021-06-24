#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QListWidgetItem>
#include <user.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int addMessagesToMessageList(QVector<Message> messagesToAdd);
    QVector<User> getUsers();
    MainWindow(User& currentUser,QVector<User>& users,QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_comboBox_activated(const QString &arg1);

    void on_registrationButton_clicked();

    void on_sendButton_clicked();

    void on_loginButton_clicked();

    void on_messageList_itemClicked(QListWidgetItem *item);

    void on_alphabetUpDownSortButton_clicked();

    void on_alphabetDownUpSortButton_clicked();

    void on_timeDownUpSortButton_clicked();

    void on_timeUpDownSortButton_clicked();

    void on_logoutButton_clicked();

private:
    User currentUser;
    QVector<User> users;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
