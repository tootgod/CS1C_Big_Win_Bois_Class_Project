#ifndef SHAPE_H
#define SHAPE_H

#include <QWidget>
#include <iostream>
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

class Shape : public QWidget
{
    Q_OBJECT
public:
    Shape(QWidget *parent = 0);
    //enum PenColor { white = 1, black, red, green, blue, cyan, magenta, yellow, gray };
    //const string COLORS[9] = { "white", "black", "red", "green", "blue", "cyan", "magenta", "yellow", "gray " };
    // default constructor
    Shape();

    // alternative constructor
    Shape(int x1, int y1, int id_num) : x1(x1), y1(y1), id(id_num){}

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

    //    bool operator== (const Shape& rhs)const {
    //        return (rhs.id == id);
    //    }

    //friend bool operator< (const Shape& sh_1, const Shape& sh_2);

    // need Qpatiner library
    virtual void draw(void) = 0;
    virtual void move(int dx, int dy) = 0; // dx --> changing x , dy -- > chnaging y
    virtual float calcPerimeter() = 0;
    virtual float calcArea() = 0;


    void printPerimeter(Shape& s);
    void printArea(Shape& s1);

public slots:
    //void SetDimensions(int dim[]);
    void InitializeMap();
    void InitializeShapes();
    //    void SetShapeId(int newID);
    //    void SetShapeType(string newSType);
    //    void SetShapeDimensions(string newDimension);
    //    void SetPenColor(Qt::GlobalColor);
    //    void SetPenWidth(int newPWidth);
    //    void SetPenStyle(Qt::PenStyle);
    //    void SetPenCapStyle(Qt::PenCapStyle);
    //    void SetPenJoinStyle(Qt::PenJoinStyle);
    //    void SetBrushColor(Qt::GlobalColor);
    //    void SetBrushStyle(Qt::BrushStyle);
    //    void SetTextString(string newText);
    //    void SetTextColor(Qt::GlobalColor);
    //    void SetTextAlignment(Qt::AlignmentFlag);
    //    void SetTextPointSize(int newPointSize);
    //    void SetTextFontFamily(string newFont);
    //    void SetTextFontStyle(QFont::Style);
    //    void SetTextFontWeight(QFont::Weight);
    //    void SetAll(int newId, string newStype, string newDimension, Qt::GlobalColor, int newPWidth, Qt::PenStyle, Qt::PenCapStyle, Qt::PenJoinStyle, Qt::GlobalColor, Qt::BrushStyle, string newText, Qt::GlobalColor, Qt::AlignmentFlag, int newPointSize, string newFont, QFont::Style, QFont::Weight);

protected:
    struct ShapeInfo {
        int    tempid;
        string type;
        int    dimensions[];
        string pencolor;
        int    penwidth;
        string penstyle;
        string pencap;
        string penjoin;
        string brushcolor;
        string brushstyle;
    };

    vector<ShapeInfo> currentShape;

    int id;
    int x1;
    int y1;
    int x2;
    int y2;
    int x3;
    int y3;

    /*
    enum PenStyle { NoPen, SolidLine, DashLine, DotLine, DashDotLine, DashDotDotLine };
    enum PenCapStyle { FlatCap, SquareCap, RoundCap };
    enum PenJoinStyle { MiterJoin, BevelJoin, RoundJoin };
    enum BrushColor { white, black, red, green, blue, cyan, magenta, yellow, gray };
    enum BrushStyle { SolidPattern, HorPattern, VerPattern, NoBrush };
    enum TextString {};
    enum TextColor { white, black, red, green, blue, cyan, magenta, yellow, gray };
    enum TextAlignment { AlignLeft, AlignRight, AlignTop, AlignBottom, AlignCenter };

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

private:
    enum ShapeType {
        LINE,
        POLYLINE,
        POLYGON,
        RECTANGLE,
        SQUARE,
        ELLIPSE,
        CIRCLE,
        TEXT
    };

    std::map<std::string, ShapeType> mapShapeType;

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
class Rectangle : public Shape {
public:
    Rectangle(int x1, int y1, int id, int length, int width) : Shape(x1, y1, id), length(length), width(width) {}
    float calcPerimeter();
    float calcArea();
    void draw(void) ;
    void move(int dx, int dy);
protected:
    int width;
    int length;
};


// class for Square
class Square : public Shape {
public:
    Square(int x1, int y1,int id, int length): Shape(x1, y1, id), length(length){}
    float calcPerimeter();
    float calcArea();
    void draw(void);
    void move(int dx, int dy);
protected:
    int length;
};


class Line : public Shape {
public:
    Line(int x1, int y1, int id, int x2, int y2) : Shape(x1, y1, id), x2(x2), y2(y2) {}
    float calcPerimeter();
    float calcArea();
    void draw(void);
    void move(int dx, int dy);
protected:
    int x2;
    int y2;
};

////Polyline - x1, y1, x2, y2, x3, y3, ... , xN, yN [sequence of N points]
class Polyline : public Shape {
public:
    // deep copy
    Polyline(int id, int numPoints, int* x_vals, int* y_vals) : Shape(x_vals[0], y_vals[0], id), numPoints(numPoints){
        x_values = new int[numPoints]; // dynamic array
        y_values = new int[numPoints];// dynamic array
        for (int i = 0; i < numPoints; i++) {
            x_values[i] = x_vals[i];
            y_values[i] = y_vals[i];
        }
    }

    ~Polyline() {
        if (x_values)
            delete[] x_values;
        if (y_values)
            delete[] y_values;
    }
    float calcPerimeter();
    float calcArea();
    void draw(void);
    void move(int dx, int dy);

protected:
    int numPoints;
    int* x_values;
    int* y_values;
};

//Polygon - x1, y1, x2, y2, x3, y3, ... , xN, yN
class Polygon : public Shape {
public:

    // deep copy
    Polygon(int id, int numPoints, int* x_vals, int* y_vals) : Shape(x_vals[0], y_vals[0], id), numPoints(numPoints) {
        x_values = new int[numPoints]; // dynamic array
        y_values = new int[numPoints];// dynamic array
        for (int i = 0; i < numPoints; i++) {
            x_values[i] = x_vals[i];
            y_values[i] = y_vals[i];
        }
    }

    ~Polygon() {
        if (x_values)
            delete[] x_values;
        if (y_values)
            delete[] y_values;
    }
    float calcPerimeter();
    float calcArea();
    void draw(void);
    void move(int dx, int dy);
protected:
    int* x_values;
    int* y_values;
    int numPoints;
};


class Ellipse : public Shape {
protected:
    int a;
    int b;
};

//void printPerimeter(Shape& s) {
//    cout << s.calcPerimeter() << endl;
//}
//void printArea(Shape& s1) {
//    cout << s1.calcArea() << endl;
//}

#endif
