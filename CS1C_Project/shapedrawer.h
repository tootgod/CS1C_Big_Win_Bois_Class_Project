#ifndef SHAPEDRAWER_H
#define SHAPEDRAWER_H

#include <QWidget>
#include "form.h"
#include "reportgenerator.h"

namespace Ui {
class ShapeDrawer;
}

class ShapeDrawer : public QWidget
{
    Q_OBJECT

public:
    explicit ShapeDrawer(QWidget *parent = 0);
    ~ShapeDrawer();
    void changeMode(int a);
    bool checkMode();

private slots:
    void on_pushButton_clicked();

    void on_createCircle_clicked();

    void on_generateReport_clicked();

    void on_logout_clicked();

private:
    int adminMode = 0;
    Ui::ShapeDrawer *ui;
    Form *test = new Form();
    ReportGenerator *gene = new ReportGenerator();

};

#endif // SHAPEDRAWER_H
