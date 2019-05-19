#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    hide();
    selectDialog = new SelectDoDialog(this);
    selectDialog->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    stDialog = new StationsDialog(this);
    stDialog->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    connDialog = new ConnDialog(this);
    connDialog->show();
}
