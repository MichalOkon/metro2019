#include "conndialog.h"
#include "ui_conndialog.h"
#include <sstream>

ConnDialog::ConnDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnDialog)
{
    ui->setupUi(this);
}

ConnDialog::~ConnDialog()
{
    delete ui;
}



void ConnDialog::on_buttonBox_accepted()
{
    hide();
    sdDialog = new SelectDoDialog(this);
    sdDialog->show();
}


std::vector<std::string> split(std::string strToSplit, char delimeter)
{
    std::stringstream ss(strToSplit);
    std::string item;
    std::vector<std::string> splittedStrings;
    while (std::getline(ss, item, delimeter)) {
        splittedStrings.push_back(item);
    }
    return splittedStrings;
}

void ConnDialog::on_pushButton_clicked()
{
    std::string text = ui->lineEdit->text().toStdString();
    std::vector<std::string> values = split(text, ';');
    std::stringstream ss;
    ss << "From: " << values[0] << "; To: " << values[1] << "; Capacity: " << values[2];
    text = ss.str();

    ui->listConnections->addItem(QString::fromStdString(text));
}
