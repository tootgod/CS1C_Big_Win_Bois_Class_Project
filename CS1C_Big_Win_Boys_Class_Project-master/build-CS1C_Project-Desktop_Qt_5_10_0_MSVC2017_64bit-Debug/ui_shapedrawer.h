/********************************************************************************
** Form generated from reading UI file 'shapedrawer.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHAPEDRAWER_H
#define UI_SHAPEDRAWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShapeDrawer
{
public:
    QPushButton *createPolygon;
    QPushButton *createRectangle;
    QPushButton *createText;
    QPushButton *createPolyline;
    QPushButton *pushButton;
    QFrame *line;
    QPushButton *createLine;
    QPushButton *createEllipse;
    QPushButton *createSquare;
    QPushButton *createCircle;
    QPushButton *generateReport;

    void setupUi(QWidget *ShapeDrawer)
    {
        if (ShapeDrawer->objectName().isEmpty())
            ShapeDrawer->setObjectName(QStringLiteral("ShapeDrawer"));
        ShapeDrawer->resize(1003, 671);
        createPolygon = new QPushButton(ShapeDrawer);
        createPolygon->setObjectName(QStringLiteral("createPolygon"));
        createPolygon->setGeometry(QRect(110, 590, 101, 23));
        createRectangle = new QPushButton(ShapeDrawer);
        createRectangle->setObjectName(QStringLiteral("createRectangle"));
        createRectangle->setGeometry(QRect(220, 590, 101, 23));
        createText = new QPushButton(ShapeDrawer);
        createText->setObjectName(QStringLiteral("createText"));
        createText->setGeometry(QRect(110, 560, 101, 23));
        createPolyline = new QPushButton(ShapeDrawer);
        createPolyline->setObjectName(QStringLiteral("createPolyline"));
        createPolyline->setGeometry(QRect(220, 560, 101, 23));
        pushButton = new QPushButton(ShapeDrawer);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(460, 630, 21, 23));
        line = new QFrame(ShapeDrawer);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(0, 540, 1081, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        createLine = new QPushButton(ShapeDrawer);
        createLine->setObjectName(QStringLiteral("createLine"));
        createLine->setGeometry(QRect(330, 560, 101, 23));
        createEllipse = new QPushButton(ShapeDrawer);
        createEllipse->setObjectName(QStringLiteral("createEllipse"));
        createEllipse->setGeometry(QRect(330, 590, 101, 23));
        createSquare = new QPushButton(ShapeDrawer);
        createSquare->setObjectName(QStringLiteral("createSquare"));
        createSquare->setGeometry(QRect(220, 620, 101, 23));
        createCircle = new QPushButton(ShapeDrawer);
        createCircle->setObjectName(QStringLiteral("createCircle"));
        createCircle->setGeometry(QRect(330, 620, 101, 23));
        generateReport = new QPushButton(ShapeDrawer);
        generateReport->setObjectName(QStringLiteral("generateReport"));
        generateReport->setGeometry(QRect(110, 620, 101, 23));

        retranslateUi(ShapeDrawer);

        QMetaObject::connectSlotsByName(ShapeDrawer);
    } // setupUi

    void retranslateUi(QWidget *ShapeDrawer)
    {
        ShapeDrawer->setWindowTitle(QApplication::translate("ShapeDrawer", "Form", nullptr));
        createPolygon->setText(QApplication::translate("ShapeDrawer", "Create Polygon", nullptr));
        createRectangle->setText(QApplication::translate("ShapeDrawer", "Create Rectangle", nullptr));
        createText->setText(QApplication::translate("ShapeDrawer", "Create Text", nullptr));
        createPolyline->setText(QApplication::translate("ShapeDrawer", "Create Polyline", nullptr));
        pushButton->setText(QApplication::translate("ShapeDrawer", "?", nullptr));
        createLine->setText(QApplication::translate("ShapeDrawer", "Create Line", nullptr));
        createEllipse->setText(QApplication::translate("ShapeDrawer", "Create Ellipse", nullptr));
        createSquare->setText(QApplication::translate("ShapeDrawer", "Create Square", nullptr));
        createCircle->setText(QApplication::translate("ShapeDrawer", "Create Circle", nullptr));
        generateReport->setText(QApplication::translate("ShapeDrawer", "Generate Report", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShapeDrawer: public Ui_ShapeDrawer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHAPEDRAWER_H
