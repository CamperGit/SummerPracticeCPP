#ifndef USER_H
#define USER_H

#include "User_global.h"
#include <QVector>
#include <message.h>

class USER_EXPORT User
{
private:
    QString login;
    QString password;
    QVector<Message> messages;
public:
    User();
    User(const QString login, const QString password);
    User(const QString login, const QString password, const QVector<Message> messages);

    QString getLogin();
    QString getPassword();
    QVector<Message> getMessages();
    void addMessage(const Message &message);
    static bool verification(const QVector<User> &users, const QString login, const QString password);
};

#endif // USER_H
