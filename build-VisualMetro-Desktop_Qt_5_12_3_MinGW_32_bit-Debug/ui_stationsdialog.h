/********************************************************************************
** Form generated from reading UI file 'stationsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATIONSDIALOG_H
#define UI_STATIONSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_StationsDialog
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QListWidget *listStations;
    QPushButton *pushButton_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *StationsDialog)
    {
        if (StationsDialog->objectName().isEmpty())
            StationsDialog->setObjectName(QString::fromUtf8("StationsDialog"));
        StationsDialog->resize(630, 370);
        label = new QLabel(StationsDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 20, 250, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("Berlin Sans FB"));
        font.setPointSize(13);
        label->setFont(font);
        label_2 = new QLabel(StationsDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 70, 120, 20));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Berlin Sans FB"));
        font1.setPointSize(10);
        label_2->setFont(font1);
        label_3 = new QLabel(StationsDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(70, 100, 140, 30));
        lineEdit = new QLineEdit(StationsDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(70, 140, 110, 25));
        pushButton = new QPushButton(StationsDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(70, 180, 110, 30));
        listStations = new QListWidget(StationsDialog);
        listStations->setObjectName(QString::fromUtf8("listStations"));
        listStations->setGeometry(QRect(310, 80, 250, 190));
        pushButton_2 = new QPushButton(StationsDialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(280, 300, 93, 28));
        buttonBox = new QDialogButtonBox(StationsDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(390, 300, 193, 28));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(StationsDialog);

        QMetaObject::connectSlotsByName(StationsDialog);
    } // setupUi

    void retranslateUi(QDialog *StationsDialog)
    {
        StationsDialog->setWindowTitle(QApplication::translate("StationsDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("StationsDialog", "Add some stations:", nullptr));
        label_2->setText(QApplication::translate("StationsDialog", "Add station:", nullptr));
        label_3->setText(QApplication::translate("StationsDialog", "(name; xcoord; ycoord)", nullptr));
        pushButton->setText(QApplication::translate("StationsDialog", "Add Station", nullptr));
        pushButton_2->setText(QApplication::translate("StationsDialog", "Previous", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StationsDialog: public Ui_StationsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATIONSDIALOG_H
