#include "mainwindow.h"
//#include <QApplication>
#include "shape.h"
#include <stdlib.h>


int main(int argc, char *argv[]){
    /*//------------Runs QT Program----------------
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
*/
    //Vector<Shape> v(20);
    //------------Whitebox testing-------------------
    QPainter *qp = &a;
    cout << "--------------------------------- Testing rectangle ---------------------------------" << endl;
    cout << " " << endl;

    Rectangle rec(qp, 10, 20, 1234, 200, 60);
    rec.set_id(1);

    cout << "For Rectangle, calculate area " << rec.calcArea() << endl;

    cout << "For Rectangle, calculate Perimeter " << rec.calcPerimeter() << endl;

    cout << "Draw test" << endl;
    rec.draw();

    cout << "--------------------------------- Testing Square ---------------------------------" << endl;
    cout << " " << endl;

    Square sqr(qp, 10, 20, 1235, 45);

    cout << "For Square, calculate area " << sqr.calcArea() << endl;

    cout << "For Square, calculate Perimeter " << sqr.calcPerimeter() << endl;

    cout << "Draw test" << endl;
    sqr.draw();
    
    cout << "--------------------------------- Testing Circle ---------------------------------" << endl;
    cout << " " << endl;
    
    Circle crc(qp, 10, 20, 1236, 45);
    
    cout << "For Circle, calculate area " << crc.calcArea() << endl;
    
    cout << "For Circle, calculate Perimeter " << crc.calcPerimeter() << endl;
    
    cout << "Draw test" << endl;
    crc.draw();

    cout << "--------------------------------- Testing Ellipse ---------------------------------" << endl;
    cout << " " << endl;
    
    Ellipse ell(qp, 10, 20, 1236, 45, 40);
    
    cout << "For Ellipse, calculate area " << ell.calcArea() << endl;
    
    cout << "For Ellipse, calculate Perimeter " << ell.calcPerimeter() << endl;
    
    cout << "Draw test" << endl;
    ell.draw();

    cout << "--------------------------------- Testing Polygon ---------------------------------" << endl;
    cout << " " << endl;

    int x_points2[4] = { 1, 3, 3, 1 };  // area 8
    int y_points2[4] = { 1, 1, 5, 5 };  // perimeter = 2 + 2 + 4 + 4 = 12
    Polygon polygon(qp, 44444, 4, x_points2, y_points2);

    cout << "For Polygon, calculate area " << polygon.calcArea() << endl;

    cout << "For Polygon, calculate Perimeter " << polygon.calcPerimeter() << endl;

    cout << "Draw test" << endl;
    polygon.draw();

    cout << "--------------------------------- Line ---------------------------------" << endl;

    Line line(qp, 30, 50, 33333, 30, 70);

    cout << "For line, calculate area " << line.calcArea() << endl;
    
    cout << "For line, calculate Perimeter " << line.calcPerimeter() << endl;

    cout << "Draw test" << endl;
    line.draw();

    cout << "--------------------------------- polyline ---------------------------------" << endl;

    int x_points[4] = { 1, 2, 3, 4};
    int y_points[4] = { 1, 2, 3, 4};
    Polyline polyline(qp, 1237, 4, x_points, y_points);

    cout << "For polyline, calculate area " << polyline.calcArea() << endl;

    cout << "For polyline, calculate Perimeter " << polyline.calcPerimeter() << endl;

    cout << "Draw test" << endl;
    polyline.draw();
    system("pause");
    
    
    //return a.exec();
}
