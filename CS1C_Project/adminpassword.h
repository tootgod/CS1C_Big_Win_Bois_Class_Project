#ifndef ADMINPASSWORD_H
#define ADMINPASSWORD_H

#include <QWidget>

namespace Ui {
class AdminPassword;
}

class AdminPassword : public QWidget
{
    Q_OBJECT

public:
    explicit AdminPassword(QWidget *parent = 0);
    ~AdminPassword();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AdminPassword *ui;
};

#endif // ADMINPASSWORD_H
