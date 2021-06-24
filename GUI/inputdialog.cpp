#include "inputdialog.h"

#include <QLabel>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QPushButton>

InputDialog::InputDialog(QWidget *parent) : QDialog(parent)
{
    QString defaultColorStrStylesheet = "color: rgb(185, 185, 185);";

    QFormLayout *lytMain = new QFormLayout(this);

    QLabel *usernameLabel = new QLabel("Username: ");
    QLineEdit *usernameLineEdit = new QLineEdit(this);
    lytMain->addRow(usernameLabel,usernameLineEdit);
    fields << usernameLineEdit;
    usernameLineEdit->setMaxLength(16);
    usernameLineEdit->setStyleSheet(defaultColorStrStylesheet);
    usernameLabel->setStyleSheet(defaultColorStrStylesheet);

    QLabel *passwordLabel = new QLabel("Password: ");
    QLineEdit *passwordLineEdit = new QLineEdit();
    passwordLineEdit->setEchoMode(QLineEdit::Password);
    passwordLineEdit->setMaxLength(16);
    lytMain->addRow(passwordLabel,passwordLineEdit);
    fields << passwordLineEdit;
    passwordLineEdit->setStyleSheet(defaultColorStrStylesheet);
    passwordLabel->setStyleSheet(defaultColorStrStylesheet);


    QDialogButtonBox *buttonBox = new QDialogButtonBox
            ( QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
              Qt::Horizontal, this );
    QPushButton *okBut = buttonBox->button(QDialogButtonBox::Ok);
    QPushButton *cancelBut = buttonBox->button(QDialogButtonBox::Cancel);
    okBut->setStyleSheet(defaultColorStrStylesheet);
    cancelBut->setStyleSheet(defaultColorStrStylesheet);

    lytMain->addWidget(buttonBox);
    buttonBox->setStyleSheet(defaultColorStrStylesheet);
    buttonBox->setStyleSheet("background-color: rgb(61, 61, 61)");

    bool conn = connect(buttonBox, &QDialogButtonBox::accepted,
                   this, &InputDialog::accept);
    Q_ASSERT(conn);
    conn = connect(buttonBox, &QDialogButtonBox::rejected,
                   this, &InputDialog::reject);
    Q_ASSERT(conn);

    setLayout(lytMain);
}

QStringList InputDialog::getStrings(QWidget *parent, bool *ok)
{
    InputDialog *dialog = new InputDialog(parent);

    QStringList list;

    const int ret = dialog->exec();
    if (ok)
        *ok = !!ret;

    if (ret) {
        foreach (auto field, dialog->fields) {
            list << field->text();
        }
    }

    dialog->deleteLater();

    return list;
}
