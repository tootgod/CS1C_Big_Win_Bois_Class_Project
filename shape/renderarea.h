#ifndef RENDERAREA_H
#define RENDERAREA_H


#include <QBrush>
#include <QPen>
#include <QPixmap>
#include <QWidget>

class RenderArea : public QWidget
{
    Q_OBJECT

public:


    RenderArea(QWidget *parent = 0);



protected:
    void paintEvent(QPaintEvent *event);


};

#endif // RENDERAREA_H
