/********************************************************************************
** Form generated from reading UI file 'conndialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNDIALOG_H
#define UI_CONNDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ConnDialog
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QDialogButtonBox *buttonBox;
    QListWidget *listConnections;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit;

    void setupUi(QDialog *ConnDialog)
    {
        if (ConnDialog->objectName().isEmpty())
            ConnDialog->setObjectName(QString::fromUtf8("ConnDialog"));
        ConnDialog->resize(630, 370);
        pushButton = new QPushButton(ConnDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(70, 180, 110, 30));
        pushButton_2 = new QPushButton(ConnDialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(280, 300, 93, 28));
        buttonBox = new QDialogButtonBox(ConnDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(390, 300, 193, 28));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        listConnections = new QListWidget(ConnDialog);
        listConnections->setObjectName(QString::fromUtf8("listConnections"));
        listConnections->setGeometry(QRect(310, 80, 250, 190));
        label = new QLabel(ConnDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 20, 250, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("Berlin Sans FB"));
        font.setPointSize(13);
        label->setFont(font);
        label_2 = new QLabel(ConnDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 70, 120, 20));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Berlin Sans FB"));
        font1.setPointSize(10);
        label_2->setFont(font1);
        label_3 = new QLabel(ConnDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(70, 100, 120, 30));
        lineEdit = new QLineEdit(ConnDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(70, 140, 110, 25));

        retranslateUi(ConnDialog);

        QMetaObject::connectSlotsByName(ConnDialog);
    } // setupUi

    void retranslateUi(QDialog *ConnDialog)
    {
        ConnDialog->setWindowTitle(QApplication::translate("ConnDialog", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("ConnDialog", "Add Connection", nullptr));
        pushButton_2->setText(QApplication::translate("ConnDialog", "Previous", nullptr));
        label->setText(QApplication::translate("ConnDialog", "Now let's add connections:", nullptr));
        label_2->setText(QApplication::translate("ConnDialog", "Add connection:", nullptr));
        label_3->setText(QApplication::translate("ConnDialog", "(from; to; capacity)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConnDialog: public Ui_ConnDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNDIALOG_H
