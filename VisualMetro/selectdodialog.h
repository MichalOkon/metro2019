#ifndef SELECTDODIALOG_H
#define SELECTDODIALOG_H

#include <QDialog>


namespace Ui {
class SelectDoDialog;
}

class SelectDoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SelectDoDialog(QWidget *parent = nullptr);
    ~SelectDoDialog();

private:
    Ui::SelectDoDialog *ui;
};

#endif // SELECTDODIALOG_H
