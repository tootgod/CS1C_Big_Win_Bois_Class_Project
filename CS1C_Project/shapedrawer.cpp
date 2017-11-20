#include "shapedrawer.h"
#include "ui_shapedrawer.h"
#include <QPainter>

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
