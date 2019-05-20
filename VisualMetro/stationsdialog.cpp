#include "stationsdialog.h"
#include "ui_stationsdialog.h"
#include <sstream>

StationsDialog::StationsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StationsDialog)
{
    ui->setupUi(this);
}

StationsDialog::~StationsDialog()
{
    delete ui;
}

void StationsDialog::on_buttonBox_accepted()
{
    hide();
}

std::vector<std::string> split1(std::string strToSplit, char delimeter)
{
    std::stringstream ss(strToSplit);
    std::string item;
    std::vector<std::string> splittedStrings;
    while (std::getline(ss, item, delimeter)) {
        splittedStrings.push_back(item);
    }
    return splittedStrings;
}



void StationsDialog::on_pushButton_clicked()
{
    std::string text = ui->lineEdit->text().toStdString();
    std::vector<std::string> values = split1(text, ';');
    std::stringstream ss;
    ss << "Station: " << values[0] << ", Xcoord: " << values[1] << ", Ycoord: " << values[2];
    text = ss.str();
    ui->listStations->addItem(QString::fromStdString(text));
}
