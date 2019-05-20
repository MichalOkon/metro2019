#ifndef GREETDIALOG_H
#define GREETDIALOG_H
#include "mainwindow.h"
#include <QDialog>

namespace Ui {
class GreetDialog;
}

class GreetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GreetDialog(QWidget *parent = nullptr);
    ~GreetDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::GreetDialog *ui;
    MainWindow *mainWindow;
};

#endif // GREETDIALOG_H
