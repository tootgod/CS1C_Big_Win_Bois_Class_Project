#include "mainwindow.h"
#include <QApplication>
#include "shape.h"
#include <stdlib.h>


int main(int argc, char *argv[])
{
    //------------Runs QT Program----------------
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
    //------------Do not touch-------------------
  /*  Rectangle rec(10, 20, 1234, 200, 60);

    cout << "--------------------------------- Testing rectangle ---------------------------------" << endl;
    cout << " " << endl;

    rec.set_id(1);


    cout << "For Rectangle, calculate area " << endl;
    rec.printArea(rec);

    cout << "For Rectangle, calculate Perimeter " << endl;
    rec.printPerimeter(rec);

    cout << "Draw test" << endl;
    rec.draw();

    cout << "--------------------------------- Testing Square ---------------------------------" << endl;
    cout << " " << endl;

    Square sqr(10, 20, 1235, 45);

    cout << "For Square, calculate area " << endl;
    sqr.printArea(sqr);

    cout << "For Square, calculate Perimeter " << endl;
    sqr.printPerimeter(sqr);


    cout << "Draw test" << endl;
    sqr.draw();




    cout << "--------------------------------- Testing Polygon ---------------------------------" << endl;
    cout << " " << endl;

    int x_points2[4] = { 1, 3, 3, 1 };  // area 8
    int y_points2[4] = { 1, 1, 5, 5 };  // perimeter = 2 + 2 + 4 + 4 = 12
    Polygon polygon(44444, 4, x_points2, y_points2);



    cout << "For Polygon, calculate area " << endl;
    polygon.printArea(polygon);

    cout << "For Polygon, calculate Perimeter " << endl;
    polygon.printPerimeter(polygon);

    cout << "Draw test" << endl;
    polygon.draw();

    cout << "--------------------------------- Line ---------------------------------" << endl;

    Line line(30, 50, 33333, 30, 70);

    cout << "For line, calculate area " << endl;
    line.printArea(line);

    cout << "For line, calculate Perimeter " << endl;
    line.printPerimeter(line);

    cout << "Draw test" << endl;
    line.draw();

    cout << "--------------------------------- polyline ---------------------------------" << endl;

    int x_points[4] = { 1, 2, 3, 4};
    int y_points[4] = { 1, 2, 3, 4};
    Polyline polyline(1237, 4, x_points, y_points);

    cout << "For polyline, calculate area " << endl;
    polyline.printArea(polyline);

    cout << "For polyline, calculate Perimeter " << endl;
    polyline.printPerimeter(polyline);

    cout << "Draw test" << endl;
    polyline.draw();
    system("pause");
}



- ellipse
- text
"
Text Properties: Text String, Text Color, Text Alignment, Text
Point Size, Text Font Family, Text Font Style, Text Font Weight
(refer to shape_input_file_specs.txt)"(2D Graphics Modeler Class Project.pdf )

*/
