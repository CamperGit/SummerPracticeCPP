#include "messagereader.h"
#include "ui_messagereader.h"

MessageReader::MessageReader(QString &text, QString &time, QString &subject,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MessageReader)
{
    ui->setupUi(this);
    this->text = text;
    this->time = time;
    this->subject = subject;

    ui->text->setText(text);
    ui->timeLabel->setText(time);
    ui->subjectLabel->setText(subject);
}

MessageReader::~MessageReader()
{
    delete ui;
}
