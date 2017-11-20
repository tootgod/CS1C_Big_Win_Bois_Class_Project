#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "shapedrawer.h"
#include <string>
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void SetShapeId(int newID);
    void SetShapeType(string newSType);
    void SetShapeDimensions(string newDimension);
    void SetPenColor(Qt::GlobalColor);
    void SetPenWidth(int newPWidth);
    void SetPenStyle(Qt::PenStyle);
    void SetPenCapStyle(Qt::PenCapStyle);
    void SetPenJoinStyle(Qt::PenJoinStyle);
    void SetBrushColor(Qt::GlobalColor);
    void SetBrushStyle(Qt::BrushStyle);
    void SetTextString(string newText);
    void SetTextColor(Qt::GlobalColor);
    void SetTextAlignment(Qt::AlignmentFlag);
    void SetTextPointSize(int newPointSize);
    void SetTextFontFamily(string newFont);
    void SetTextFontStyle(QFont::Style);
    void SetTextFontWeight(QFont::Weight);
    void SetAll(int newId, string newStype, string newDimension, Qt::GlobalColor, int newPWidth, Qt::PenStyle, Qt::PenCapStyle, Qt::PenJoinStyle, Qt::GlobalColor, Qt::BrushStyle, string newText, Qt::GlobalColor, Qt::AlignmentFlag, int newPointSize, string newFont, QFont::Style, QFont::Weight);


private slots:
    void on_pushButton_clicked();
    void on_guestLogin_clicked();

private:
    Ui::MainWindow *ui;
    ShapeDrawer *fun = new ShapeDrawer();
};

#endif // MAINWINDOW_H
