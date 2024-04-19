/********************************************************************************
** Form generated from reading UI file 'map.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAP_H
#define UI_MAP_H

#include <QtCore/QVariant>
#include <QtQuickWidgets/QQuickWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_map
{
public:
    QQuickWidget *quickWidget;

    void setupUi(QDialog *map)
    {
        if (map->objectName().isEmpty())
            map->setObjectName("map");
        map->resize(782, 539);
        quickWidget = new QQuickWidget(map);
        quickWidget->setObjectName("quickWidget");
        quickWidget->setGeometry(QRect(0, 0, 782, 539));
        quickWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);

        retranslateUi(map);

        QMetaObject::connectSlotsByName(map);
    } // setupUi

    void retranslateUi(QDialog *map)
    {
        map->setWindowTitle(QCoreApplication::translate("map", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class map: public Ui_map {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAP_H
