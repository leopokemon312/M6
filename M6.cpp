


// File: main.cpp

#include <iostream>
#include <string>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

using namespace std;

// Abstract base class
class BasicShape {
private:
    double area;
    string name;

public:
    virtual ~BasicShape() {}

    double getArea() const {
        return area;
    }

    string getName() const {
        return name;
    }

    void setArea(double a) {
        area = a;
    }

    void setName(const string& n) {
        name = n;
    }

    virtual void calcArea() = 0;
};

// Derived class Circle
class Circle : public BasicShape {
private:
    double xCenter;
    double yCenter;
    double radius;

public:
    Circle(double x, double y, double r, const string& n = "Circle")
        : xCenter(x), yCenter(y), radius(r) {
        setName(n);
        calcArea();
    }

    double getXCenter() const { return xCenter; }
    double getYCenter() const { return yCenter; }
    double getRadius() const { return radius; }

    void calcArea() override {
        double area = M_PI * radius * radius;
        setArea(area);
    }
};

// Derived class Rectangle
class Rectangle : public BasicShape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w, const string& n = "Rectangle")
        : length(l), width(w) {
        setName(n);
        calcArea();
    }

    double getLength() const { return length; }
    double getWidth() const { return width; }

    void calcArea() override {
        double area = length * width;
        setArea(area);
    }
};

// Derived class Square
class Square : public Rectangle {
private:
    double side;

public:
    Square(double s, const string& n = "Square")
        : Rectangle(s, s, n), side(s) {
        setName(n);
    }

    double getSide() const { return side; }
};

// Main testing program
int main() {
    const int SIZE = 5;
    BasicShape* shapes[SIZE] = {
        new Rectangle(5.0, 3.0, "Rectangle1"),
        new Rectangle(7.5, 2.0, "Rectangle2"),
        new Circle(0.0, 0.0, 4.0, "Circle1"),
        new Circle(1.0, 1.0, 6.0, "Circle2"),
        new Square(5.0, "Square1")
    };

    for (int i = 0; i < SIZE; ++i) {
        cout << shapes[i]->getName() << " has area: " << shapes[i]->getArea() << endl;
    }

    for (int i = 0; i < SIZE; ++i) {
        delete shapes[i];
    }

    return 0;
}
