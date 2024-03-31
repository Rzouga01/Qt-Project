/********************************************************************************
** Form generated from reading UI file 'qrcodedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QRCODEDIALOG_H
#define UI_QRCODEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QrCodeDialog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;

    void setupUi(QDialog *QrCodeDialog)
    {
        if (QrCodeDialog->objectName().isEmpty())
            QrCodeDialog->setObjectName("QrCodeDialog");
        QrCodeDialog->resize(240, 240);
        verticalLayoutWidget = new QWidget(QrCodeDialog);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(0, 0, 241, 241));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(QrCodeDialog);

        QMetaObject::connectSlotsByName(QrCodeDialog);
    } // setupUi

    void retranslateUi(QDialog *QrCodeDialog)
    {
        QrCodeDialog->setWindowTitle(QCoreApplication::translate("QrCodeDialog", "Qr Code", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QrCodeDialog: public Ui_QrCodeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QRCODEDIALOG_H
