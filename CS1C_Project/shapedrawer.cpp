#include "shapedrawer.h"
#include "ui_shapedrawer.h"
#include <QPainter>
#include "mainwindow.h"
#include <QString>

ShapeDrawer::ShapeDrawer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShapeDrawer)
{
    ui->setupUi(this);
    setMaximumSize(1003,671);
}

ShapeDrawer::~ShapeDrawer()
{
    delete ui;
}

void ShapeDrawer::changeMode(int a)
{
    adminMode = a;
    return;
}

bool ShapeDrawer::checkMode()
{
    return adminMode;
}

void ShapeDrawer::on_pushButton_clicked()
{
    test->show();
}

void ShapeDrawer::on_createCircle_clicked()
{

}

void ShapeDrawer::on_generateReport_clicked()
{
    gene->show();
}

void ShapeDrawer::on_logout_clicked()
{

}

void ShapeDrawer::on_selectShape_windowTitleChanged(const QString &title)
{

}

void ShapeDrawer::on_selectShape_activated(const QString &arg1)
{

}

void ShapeDrawer::on_selectShape_activated(int index)
{

}

void ShapeDrawer::on_selectShape_currentIndexChanged(int index)
{
    ui->shapeMenu->setCurrentIndex(index);
}
