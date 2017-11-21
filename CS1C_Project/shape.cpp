#include "shape.h"

using namespace Shapes;

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
    void Rectangle::draw() {
		// use QPainter object here
        //cout << "Drawing rect x1:" << x1 << " y1:" << y1 << " length: " << length << " width: " << width << endl;


        QRectF rect(x1, y1, width, length);
        QPen pen(QColor("blue"));
        std::cout << "I am here." << std::endl;
        qpainter->setPen(pen);
        //qpainter->setPen(QColor("blue"));
        qpainter->drawRect(rect);
    }

	void Rectangle::move(int dx, int dy) {
		x1 += dx;
		y1 += dy;
	}


//---------------------------Square----------------------------------------
	float Square::calcPerimeter() {
		return (4 * length);
	}

	float Square::calcArea() {
		return (length * length);
	}

	void Square::draw(void) {
		// use QPainter object here
		cout << "Drawing Square x1:" << x1 << " y1:" << y1 << " length: " << length  << endl;

        QRectF rect(x1, y1, length, length);
        QPen pen(brush, penWidth, penStyle, capStyle, joinStyle);
        qpainter->setPen(pen);
        qpainter->drawRect(rect);
    }
	void Square::move(int dx, int dy) {
		x1 += dx;
		y1 += dy;
	}

// ------------------------Line----------------------------------------------------


	float Line::calcPerimeter() {
		double dx = x2 - x1;
		double dy = y2 - y1;
		return sqrt(dx*dx + dy*dy);
	}

	float Line::calcArea() {
		return 0;
	}

	void Line::draw(void) {
		// use QPainter object here
        //cout << "Drawing Line x1:" << x1 << " y1:" << y1 << " x2:" << x2 << " y2 : " << y2 << endl;

        QPoint a(x1, y1);
        QPoint b(x2, y2);
        QLineF line(a,b);
        QPen pen(brush, penWidth, penStyle, capStyle, joinStyle);
        qpainter->setPen(pen);
        qpainter->drawLine(a,b);
    }

	void Line::move(int dx, int dy) {
		x1 += dx;
		y1 += dy;
	}

// ------------------------PolyLine----------------------------------------------------

	float Polyline::calcPerimeter() {
        float sum = 0;
		for (int i = 0; i < numPoints - 1; i++){
            float dx = points[i + 1].x() - points[i].x();
            float dy = points[i + 1].y() - points[i].y();
			sum += sqrt(dx*dx + dy*dy);
		}
		return sum;
	}

	float Polyline::calcArea() {
		return 0;
	}

	void Polyline::draw(void) {
		// use QPainter object here
        //cout << "Drawing Polyline " << endl;

        QPen pen(brush, penWidth, penStyle, capStyle, joinStyle);
        qpainter->setPen(pen);
        qpainter->drawPolyline(points, numPoints);


	}

	void Polyline::move(int dx, int dy) {
		for (int i = 0; i < numPoints; i++) {
            points->setX(points[i].x() + dx);
            points->setY(points[i].y() + dy);
		}


	}

	// ------------------------Polygon----------------------------------------------------

	float Polygon::calcPerimeter() {
		float sum = 0;
		for (int i = 0; i < numPoints ; i++) {
            QPoint a = points[(i+1)%numPoints];
            QPoint b = points[(i)];
            double dx = a.x() - b.x();
            double dy = a.y() - b.y();
			sum += sqrt(dx*dx + dy*dy);
		}
		return (float)sum;
	}

	float Polygon::calcArea() {
		float area = 0;
		for (int i = 0; i < numPoints ; i++) {
            QPoint a = points[(i+1)%numPoints];
            QPoint b = points[(i)];
            area += -b.y() * a.x() + b.x() * a.y();
		}
		area = 0.5 * abs(area);
		return area;
	}

	void Polygon::draw(void) {
		// use QPainter object here
        //cout << "Drawing Polygon " << endl;
        /*
        for (int i = 0; i < numPoints; i++) {
			cout << "(" << x_values[i] << "," << y_values[i] << ")" << endl;
        } */
        QPen pen(brush, penWidth, penStyle, capStyle, joinStyle);
        qpainter->setPen(pen);
        qpainter->drawPolygon(points, numPoints); // uses default fill rule EvenOdd
	}

	void Polygon::move(int dx, int dy) {
		for (int i = 0; i < numPoints; i++) {
            points->setX(points[i].x() + dx);
            points->setY(points[i].y() + dy);
		}
	}

    /*
    int dimension(){
        return (r * )
    }
    */
    
