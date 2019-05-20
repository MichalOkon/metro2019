#ifndef CONNDIALOG_H
#define CONNDIALOG_H

#include <QDialog>

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
};

#endif // CONNDIALOG_H
