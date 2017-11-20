#ifndef SHAPEDRAWER_H
#define SHAPEDRAWER_H

#include <QWidget>
#include "form.h"

namespace Ui {
class ShapeDrawer;
}

class ShapeDrawer : public QWidget
{
    Q_OBJECT

public:
    explicit ShapeDrawer(QWidget *parent = 0);
    ~ShapeDrawer();

private slots:
    void on_pushButton_clicked();

    void on_createCircle_clicked(QPaintEvent *event);

private:
    Ui::ShapeDrawer *ui;
    Form *test = new Form();
};

#endif // SHAPEDRAWER_H
