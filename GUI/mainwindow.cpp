#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QDialog>
#include <QFormLayout>
#include <QDialogButtonBox>
#include <inputdialog.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    bool ok;
    QStringList list = InputDialog::getStrings(this, &ok);
    if (ok) {
        // use list
    }
    //QString login = QInputDialog::getText(this, tr("QInputDialog::getText()"),tr("User name:"), QLineEdit::Normal,"", &ok);
    //QString password = QInputDialog::getText(this, tr("QInputDialog::getText()"),tr("Password:"), QLineEdit::Password,"", &ok);

    /*QDialog dialog(this);
    // Use a layout allowing to have a label next to each field
    QFormLayout form(&dialog);

    // Add some text above the fields
    form.addRow(new QLabel("Username: "));

    // Add the lineEdits with their respective labels
    QList<QLineEdit *> fields;
    QLineEdit *usernameLineEdit = new QLineEdit(&dialog);
    form.addRow("Username:",usernameLineEdit);
    fields << usernameLineEdit;

    QLineEdit *passwordLineEdit = new QLineEdit(&dialog);
    form.addRow("Password:",usernameLineEdit);
    fields << passwordLineEdit;

    // Add some standard buttons (Cancel/Ok) at the bottom of the dialog
    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                               Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);
    QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
    QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));

    // Show the dialog as modal
    if (dialog.exec() == QDialog::Accepted) {
        QString login = fields.;
        QString password;
        // If the user didn't dismiss the dialog, do something with the fields
        foreach(QLineEdit * lineEdit, fields) {
            qDebug() << lineEdit->text();
        }
    }*/

}

