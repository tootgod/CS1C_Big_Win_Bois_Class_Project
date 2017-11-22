#ifndef SHAPE_H
#define SHAPE_H
#define PI_VAL 3.14159265359

#include <QWidget>
#include <iostream>
#include <QtGui>
#include <cmath>

using namespace std;

class Shape : public QWidget {
public:
    Shape(QWidget *parent = 0);

    // default constructor
    Shape(QPainter * painter, int id_num): qpainter(painter), id(id_num) {}

    // alternative constructor
    Shape(QPainter * painter, int x1, int y1, int id_num) : x1(x1), y1(y1), id(id_num){}

    // copy constructor "mark constructor delete"
    Shape(const Shape& obj) = delete;

    // disable assigment operator
    Shape & operator = (const Shape& obj) = delete;

    //string SetCoordinates(string )

    void set_id(int id_num);

    //void set_pen_color(string pen_color)
    int get_x1();
    int get_y1();

    void set_x1(int value);
    void set_y1(int value);
    
    void setPenStyle(Qt::PenStyle ps){
        penStyle = ps;
    }
    
    void setPenColor(QColor color){
        penColor = color;
    }
    
    bool operator== (const Shape& rhs)const {
        return (rhs.id == id);
    }

    //friend bool operator< (const Shape& sh_1, const Shape& sh_2);

    // need Qpatiner library
    virtual void draw() = 0;
    virtual void move(int dx, int dy) = 0; // dx --> changing x , dy -- > chnaging y
    virtual float calcPerimeter() = 0;
    virtual float calcArea() = 0;

    void printPerimeter(Shape& s);
    void printArea(Shape& s1);

protected:
    QPen pen;
    QBrush brush;
    QFont font;
    
    Qt::PenStyle penStyle;
    Qt::PenCapStyle capStyle;
    Qt::PenJoinStyle joinStyle;

    int id;
    int x1;
    int y1;
    int x2;
    int y2;
    int x3;
    int y3;

    /*
    int textPointerSize() {
        int TextPointSize[51];
        for (int i = -1; i < 52; i++) {
            TextPointSize[i] = i;
            return TextPointSize[i];
        }
    }
    TextFontFamily: Comic Sans MS, Courier, Helvetica, Times [string]
    enum TextFontStyle { StyleNormal, StyleItalic, StyleObliqu };
    enum TextFontWeight { Thin, Light, Normal, Bold };
    */

};

/*
bool operator< (const Shape& sh_1, const Shape& sh_2) {
    return sh_1.id < sh_2.id;
}
*/

/*
bool operator== (const Shape& rhs) const {
return (rhs.obj = obj);
}
*/

// class for Rectangle
class Rectangle : public Square {
public:
    Rectangle(QPainter * qp, int x1, int y1, int id, int length, int width) : Shape(qp, x1, y1, id), Square(length), width{width} {}
    float calcPerimeter();
    float calcArea();
    void draw(void);
    void move(int dx, int dy);
protected:
    int width;
};


// class for Square
class Square : public Shape {
public:
    Square(QPainter* qp, int x1, int y1, int id, int length): Shape(qp, x1, y1, id), length{length}{}
    float calcPerimeter();
    float calcArea();
    void draw(void);
protected:
    int length;
};

//Circle
class Circle : public Shape{
public:
    Circle(QPainter * qp, int x1, int y1, int id, int r) : Shape(qp, x1, y1, id), r{width} {}
    float calcPerimeter();
    float calcArea();
    void draw() ;
    void move(int dx, int dy);
protected:
    int r;
};

//Ellipse
class Ellipse : public Circle {
protected:
    int r2;//minor axis (shortest distance from center point to perimeter)
    //major axis (longest distance from center point to perimeter) is the radius (int r) in circle
public:
    Ellipse(QPainter * qp, int x1, int y1, int id, int a, int b) : Circle(qp, x1, y1, id, a), r2{b} {}
    float calcPerimeter();
    float calcArea();
    void draw() ;
};

class Line : public Shape {
public:
    Line(QPainter * qp, int x1, int y1, int id, int x2, int y2) : Shape(qp, x1, y1, id), x2(x2), y2(y2) {}
    float calcPerimeter();
    float calcArea();
    void draw();
    void move(int dx, int dy);
protected:
    int x2;
    int y2;
};

//Polyline - x1, y1, x2, y2, x3, y3, ... , xN, yN [sequence of N points]
class Polyline : public Shape {
public:
    // deep copy
    Polyline(QPainter * qp, int id, int numPoints, int* x_vals, int* y_vals) : Shape(qp, x_vals[0], y_vals[0], id), numPoints(numPoints){
        
        points = new QPoint[numPoints];
        
        for (int i = 0; i < numPoints; i++) {
            
            points[i] = QPoint(x_vals[i], y_vals[i]);
        }
    }
    
    ~Polyline() {
        if(points)
            delete [] points;
    }
    float calcPerimeter();
    float calcArea();
    void draw(void);
    void move(int dx, int dy);
protected:
    int numPoints;
    QPoint * points;
    
};
//Polygon - x1, y1, x2, y2, x3, y3, ... , xN, yN
class Polygon : public Shape {
public:
    
    // deep copy
    Polygon(QPainter *qp, int id, int numPoints, QPoint * pts): Shape(qp, id), numPoints(numPoints) {
        points = new QPoint[numPoints]; // dynamic array
        
        for (int i = 0; i < numPoints; i++) {
            points[i] = pts[i];
        }
    }
    
    Polygon(QPainter * qp, int id, int numPoints, int* x_vals, int* y_vals) : Shape(qp, x_vals[0], y_vals[0], id), numPoints(numPoints) {
        points = new QPoint[numPoints]; // dynamic array
        
        for (int i = 0; i < numPoints; i++) {
            points[i] = QPoint(x_vals[i], y_vals[i]);
        }
    }
    
    ~Polygon() {
        if (points)
            delete [] points;
    }
    float calcPerimeter();
    float calcArea();
    void draw(void);
    void move(int dx, int dy);
protected:
    QPoint * points;
    int numPoints;
};

#endif
