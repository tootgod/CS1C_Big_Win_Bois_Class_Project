#include <QtGui>

#include "renderarea.h"
#include "shape.h"

RenderArea::RenderArea(QWidget *parent)
    : QWidget(parent)
{

}


void RenderArea::paintEvent(QPaintEvent * /* event */)
{

    QPainter painter(this);
    Shapes::Rectangle  rect(&painter, 20, 20, 1, 100, 200);
    QColor c("red");
    //painter.setPen(c);
    //painter.drawRect(QRectF(20, 20, 100, 200));
    rect.setPenColor(c);
    rect.setPenStyle(Qt::SolidLine);
    rect.draw();

}
