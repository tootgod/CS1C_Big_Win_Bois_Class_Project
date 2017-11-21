#include "shapedrawer.h"
#include "ui_shapedrawer.h"
#include "shape.h"
#include "renderarea.h"

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

