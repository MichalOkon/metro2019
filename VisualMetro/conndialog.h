#ifndef CONNDIALOG_H
#define CONNDIALOG_H

#include <QDialog>
#include <selectdodialog.h>

namespace Ui {
class ConnDialog;
}

class ConnDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConnDialog(QWidget *parent = nullptr);
    ~ConnDialog();

private slots:
    void on_buttonBox_accepted();

    void on_pushButton_clicked();

private:
    Ui::ConnDialog *ui;
    SelectDoDialog *sdDialog;
};

#endif // CONNDIALOG_H
