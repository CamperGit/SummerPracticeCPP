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
    MainWindow(User& currentUser,QVector<User>& users,QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_comboBox_activated(const QString &arg1);

    void on_registrationButton_clicked();

private:
    User currentUser;
    QVector<User> users;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
