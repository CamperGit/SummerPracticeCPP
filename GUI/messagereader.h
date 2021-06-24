#ifndef MESSAGEREADER_H
#define MESSAGEREADER_H

#include <QDialog>

namespace Ui {
class MessageReader;
}

class MessageReader : public QDialog
{
    Q_OBJECT

public:
    explicit MessageReader(QString &text, QString &time, QString &subject,QWidget *parent = nullptr);
    ~MessageReader();

private:
    QString text;
    QString time;
    QString subject;
    Ui::MessageReader *ui;
};

#endif // MESSAGEREADER_H
