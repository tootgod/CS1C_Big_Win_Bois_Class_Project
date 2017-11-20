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
    if(checkMode())
  ui->label->setText("1");
    else
  ui->label->setText("0");
}
