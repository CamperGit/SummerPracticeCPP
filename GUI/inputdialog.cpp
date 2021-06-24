#include "inputdialog.h"

#include <QLabel>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QFormLayout>

InputDialog::InputDialog(QWidget *parent) : QDialog(parent)
{
    QFormLayout *lytMain = new QFormLayout(this);

    QLabel *usernameLabel = new QLabel("Username: ");
    QLineEdit *usernameLineEdit = new QLineEdit(this);
    lytMain->addRow(usernameLabel,usernameLineEdit);
    fields << usernameLineEdit;
    usernameLineEdit->setStyleSheet("color: rgb(185, 185, 185);");

    usernameLabel->setStyleSheet("color: rgb(185, 185, 185);");

    QLabel *passwordLabel = new QLabel("Password: ");
    QLineEdit *passwordLineEdit = new QLineEdit();
    passwordLineEdit->setEchoMode(QLineEdit::Password);
    lytMain->addRow(passwordLabel,passwordLineEdit);
    fields << passwordLineEdit;
    passwordLineEdit->setStyleSheet("color: rgb(185, 185, 185);");

    passwordLabel->setStyleSheet("color: rgb(185, 185, 185);");

    QDialogButtonBox *buttonBox = new QDialogButtonBox
            ( QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
              Qt::Horizontal, this );
    lytMain->addWidget(buttonBox);
    buttonBox->setStyleSheet("color: rgb(185, 185, 185);");
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
