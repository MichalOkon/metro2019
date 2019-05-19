#ifndef STATIONSDIALOG_H
#define STATIONSDIALOG_H

#include <QDialog>

namespace Ui {
class StationsDialog;
}

class StationsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StationsDialog(QWidget *parent = nullptr);
    ~StationsDialog();

private slots:
    void on_buttonBox_accepted();

    void on_pushButton_clicked();

private:
    Ui::StationsDialog *ui;
};

#endif // STATIONSDIALOG_H
