#include "selectdodialog.h"
#include "ui_selectdodialog.h"

SelectDoDialog::SelectDoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectDoDialog)
{
    ui->setupUi(this);
}

SelectDoDialog::~SelectDoDialog()
{
    delete ui;
}
