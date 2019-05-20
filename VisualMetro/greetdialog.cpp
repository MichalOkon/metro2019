#include "greetdialog.h"
#include "ui_greetdialog.h"


GreetDialog::GreetDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GreetDialog)
{
    ui->setupUi(this);
}

GreetDialog::~GreetDialog()
{
    delete ui;
}

void GreetDialog::on_pushButton_clicked()
{
    hide();
    mainWindow = new MainWindow(this);
    mainWindow->show();
}
