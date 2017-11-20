/********************************************************************************
** Form generated from reading UI file 'reportgenerator.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTGENERATOR_H
#define UI_REPORTGENERATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReportGenerator
{
public:
    QLabel *label;
    QPushButton *ID;
    QPushButton *area;
    QPushButton *perimeter;

    void setupUi(QWidget *ReportGenerator)
    {
        if (ReportGenerator->objectName().isEmpty())
            ReportGenerator->setObjectName(QStringLiteral("ReportGenerator"));
        ReportGenerator->resize(329, 244);
        label = new QLabel(ReportGenerator);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 70, 231, 16));
        ID = new QPushButton(ReportGenerator);
        ID->setObjectName(QStringLiteral("ID"));
        ID->setGeometry(QRect(30, 120, 75, 23));
        area = new QPushButton(ReportGenerator);
        area->setObjectName(QStringLiteral("area"));
        area->setGeometry(QRect(130, 120, 75, 23));
        perimeter = new QPushButton(ReportGenerator);
        perimeter->setObjectName(QStringLiteral("perimeter"));
        perimeter->setGeometry(QRect(230, 120, 75, 23));

        retranslateUi(ReportGenerator);

        QMetaObject::connectSlotsByName(ReportGenerator);
    } // setupUi

    void retranslateUi(QWidget *ReportGenerator)
    {
        ReportGenerator->setWindowTitle(QApplication::translate("ReportGenerator", "Form", nullptr));
        label->setText(QApplication::translate("ReportGenerator", "How would you like your report to be sorted by?", nullptr));
        ID->setText(QApplication::translate("ReportGenerator", "ID", nullptr));
        area->setText(QApplication::translate("ReportGenerator", "Area", nullptr));
        perimeter->setText(QApplication::translate("ReportGenerator", "Perimeter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReportGenerator: public Ui_ReportGenerator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTGENERATOR_H
