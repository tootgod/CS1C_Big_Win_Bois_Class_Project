#ifndef SHAPE
#define SHAPE

#include <iostream> 
//#include <QPainter>

using namespace std;


//enum PenColor { white = 1, black, red, green, blue, cyan, magenta, yellow, gray };
//const string COLORS[9] = { "white", "black", "red", "green", "blue", "cyan", "magenta", "yellow", "gray " };

class Shape {
public:
	// default constructor 
	Shape() {}

	// alternative constructor 
	Shape(int x1, int y1, int id_num) : x1(x1), y1(y1), id(id_num){}
	
	// copy constructor "mark constructor delete"
	Shape(const Shape& obj) = delete;
	
	// disable assigment operator 
	Shape & operator = (const Shape& obj) = delete;

	void set_id(int id_num);

	//void set_pen_color(string pen_color)
	int get_x1();
	int get_y1();

	void set_x1(int value);
	void set_y1(int value);

	bool operator== (const Shape& rhs)const {
		return (rhs.id == id);
	}

	//friend bool operator< (const Shape& sh_1, const Shape& sh_2);

	// need Qpatiner library 
	virtual void draw(void) = 0;
	virtual void move(int dx, int dy) = 0; // dx --> changing x , dy -- > chnaging y 
	virtual float calcPerimeter() = 0;
	virtual float calcArea() = 0;


	void printPerimeter(Shape& s);
	void printArea(Shape& s1);
protected:
	int id;
	int x1;
	int y1;
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

//Polyline - x1, y1, x2, y2, x3, y3, ... , xN, yN [sequence of N points]
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

/*
void printPerimeter(Shape& s) {
	cout << s.calcPerimeter() << endl;
}
void printArea(Shape& s1) {
	cout << s1.calcArea() << endl;
}
*/
#endif

