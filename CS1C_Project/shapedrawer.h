#ifndef SHAPEDRAWER_H
#define SHAPEDRAWER_H

#include <QWidget>
#include "form.h"
#include "reportgenerator.h"
#include <QBrush>
#include <QPen>
#include <QPixmap>

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


private:
    int adminMode = 0;
    Ui::ShapeDrawer *ui;
    Form *test = new Form();
    ReportGenerator *gene = new ReportGenerator();


};

#endif // SHAPEDRAWER_H
