#ifndef REPORTGENERATOR_H
#define REPORTGENERATOR_H

#include <QWidget>

namespace Ui {
class ReportGenerator;
}

class ReportGenerator : public QWidget
{
    Q_OBJECT

public:
    explicit ReportGenerator(QWidget *parent = 0);
    ~ReportGenerator();

private:
    Ui::ReportGenerator *ui;
};

#endif // REPORTGENERATOR_H
