#include "shape.h"

//---------------------------Shape ----------------------------------
Shape::Shape(QWidget *parent) : QWidget(parent)
{

}

void Shape::set_id(int i) {
id = i;
cout << "ID == " << id << endl;
}

int Shape::get_x1() {
    return x1;
}
int Shape::get_y1() {
    return y1;
}

void Shape::set_x1(int value) {
    x1 = value;
}
void Shape::set_y1(int value) {
    y1 = value;
}

void  Shape::printPerimeter(Shape& s) {
    cout << s.calcPerimeter() << endl;
}
void  Shape::printArea(Shape& s1) {
    cout << s1.calcArea() << endl;
}

//---------------------------Rectangle ----------------------------------
float Rectangle::calcPerimeter(){
    return ((width + length ) * 2 );
}

float Rectangle::calcArea(){
    return (width * length);
}
void Rectangle::draw(void) {
    cout << "Drawing rect x1:" << x1 << " y1:" << y1 << " length: " << length << " width: " << width << endl;
    // use QPainter object here
    QRectF rect(x1, y1, width, length);
    QPen pen(QColor("blue"));
    qpainter->setPen(pen);
    //qpainter->setPen(QColor("blue"));
    qpainter->drawRect(rect);
}

//---------------------------Square ----------------------------------------
float Square::calcPerimeter() {
    return (4 * length);
}

float Square::calcArea() {
    return (length * length);
}

void Square::draw(void) {
    cout << "Drawing rect x1:" << x1 << " y1:" << y1 << " length: " << length << " width: " << width << endl;
    // use QPainter object here
    QRectF rect(x1, y1, length, length);
    QPen pen(QColor("blue"));
    qpainter->setPen(pen);
    //qpainter->setPen(QColor("blue"));
    qpainter->drawRect(rect);
}
void Square::move(int dx, int dy) {
    x1 += dx;
    y1 += dy;
}

//---------------------------Circle ----------------------------------
float Circle::calcPerimeter(){
    return (PI_VAL * r * 2);
}

float Circle::calcArea(){
    return (PI_VAL * r * r);
}
void Circle::draw() {
    cout << "Drawing circ x1:" << x1 << " y1:" << y1 << " radius: " << r << endl;
    // use QPainter object here
    QCircF circ(x1, y1, r);
    QPen pen(QColor("blue"));
    qpainter->setPen(pen);
    //qpainter->setPen(QColor("blue"));
    qpainter->drawCirc(circ);
}
void Circle::move(int dx, int dy) {
    x1 += dx;
    y1 += dy;
}

//---------------------------Ellipse ----------------------------------
float Ellipse::calcPerimeter(){//Ramanujan's approximation//r major axis r2 minor axis
    double h = pow(r - r2, 2) / pow(r + r2, 2);//h value used in calculations
    return (PI_VAL * (r + r2) * (1 + ((3 * h) / (10 + sqrt(4 - (3 * h))))));
}

float Ellipse::calcArea(){//r major axis r2 minor axis
    return (PI_VAL * r * r2);
}
void Ellipse::draw(void) {
    cout << "Drawing circ x1:" << x1 << " y1:" << y1 << " radius: " << r << endl;
    // use QPainter object here
    QElliF elli(x1, y1, r);
    QPen pen(QColor("blue"));
    qpainter->setPen(pen);
    //qpainter->setPen(QColor("blue"));
    qpainter->drawElli(elli);
}

//// ------------------------Line ----------------------------------------------------


float Line::calcPerimeter() {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(dx*dx + dy*dy);
}

float Line::calcArea() {
    return 0;
}

void Line::draw() {
    // use QPainter object here
    QPoint a(x1, y1);
    QPoint b(x2, y2);
    QLineF line(a,b);
    QPen pen(brush, penWidth, penStyle, capStyle, joinStyle);
    qpainter->setPen(pen);
    qpainter->drawLine(a,b);
    cout << "Drawing Line x1:" << x1 << " y1:" << y1 << " x2:" << x2 << " y2 : " << y2 << endl;
}

//------------------------PolyLine ----------------------------------------------------

float Polyline::calcPerimeter() {
    double sum = 0;
    for (int i = 0; i < numPoints - 1; i++){
        double dx = x_values[i + 1] - x_values[i];
        double dy = y_values[i + 1] - y_values[i];
        sum += sqrt(dx*dx + dy*dy);
    }
    return sum;
}

float Polyline::calcArea() {
    return 0;
}

void Polyline::draw(void) {
    // use QPainter object here
    QPen pen(brush, penWidth, penStyle, capStyle, joinStyle);
    qpainter->setPen(pen);
    qpainter->drawPolyline(points, numPoints);
    cout << "Drawing Polyline " << endl;
    for (int i = 0; i < numPoints; i++) {
        cout << "(" << x_values[i] << "," << y_values[i] << ")" << endl;
    }
}

void Polyline::move(int dx, int dy) {
    for (int i = 0; i < numPoints; i++) {
        x_values[i] += dx;
        y_values[i] += dy;
    }
}

//------------------------Polygon ----------------------------------------------------

float Polygon::calcPerimeter() {
    float sum = 0;
    for (int i = 0; i < numPoints ; i++) {
        double dx = x_values[(i + 1)%numPoints] - x_values[i];
        double dy = y_values[(i + 1) % numPoints] - y_values[i];
        sum += sqrt(dx*dx + dy*dy);
    }
    return (float)sum;
}

float Polygon::calcArea() {
    float area = 0;
    for (int i = 0; i < numPoints ; i++) {
        area += -y_values[i] * x_values[(i + 1)%numPoints] + x_values[i] * y_values[(i + 1)%numPoints];
    }
    area = 0.5 * abs(area);
    return area;
}

void Polygon::draw(void) {
    // use QPainter object here
    QPen pen(brush, penWidth, penStyle, capStyle, joinStyle);
    qpainter->setPen(pen);
    qpainter->drawPolygon(points, numPoints); // uses default fill rule EvenOdd
    cout << "Drawing Polygon " << endl;
    for (int i = 0; i < numPoints; i++) {
        cout << "(" << x_values[i] << "," << y_values[i] << ")" << endl;
    }
}

void Polygon::move(int dx, int dy) {
    for (int i = 0; i < numPoints; i++) {
        x_values[i] += dx;
        y_values[i] += dy;
    }
}
