#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

/*
   Base class defining a common interface for all shapes.
   Demonstrates runtime polymorphism.
*/
class Shape {
public:
    virtual double area() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) {
        if (r <= 0) {
            throw invalid_argument("Radius must be positive.");
        }
        radius = r;
    }

    double area() {
        return M_PI * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double length, width;

public:
    Rectangle(double l, double w) {
        if (l <= 0 || w <= 0) {
            throw invalid_argument("Length and width must be positive.");
        }
        length = l;
        width = w;
    }

    double area() {
        return length * width;
    }
};

class Triangle : public Shape {
private:
    double base, height;

public:
    Triangle(double b, double h) {
        if (b <= 0 || h <= 0) {
            throw invalid_argument("Base and height must be positive.");
        }
        base = b;
        height = h;
    }

    double area() {
        return 0.5 * base * height;
    }
};

// Extra shape added to extend the hierarchy
class Square : public Shape {
private:
    double side;

public:
    Square(double s) {
        if (s <= 0) {
            throw invalid_argument("Side length must be positive.");
        }
        side = s;
    }

    double area() {
        return side * side;
    }
};

int main() {
    int choice;
    cout << "Select Shape to Calculate Area:\n";
    cout << "1. Circle\n2. Rectangle\n3. Triangle\n4. Square\n";
    cout << "Enter choice (1-4): ";
    cin >> choice;

    try {
        Shape* shape = nullptr;

        if (choice == 1) {
            double r;
            cout << "Enter radius: ";
            cin >> r;
            shape = new Circle(r);
        }
        else if (choice == 2) {
            double l, w;
            cout << "Enter length and width: ";
            cin >> l >> w;
            shape = new Rectangle(l, w);
        }
        else if (choice == 3) {
            double b, h;
            cout << "Enter base and height: ";
            cin >> b >> h;
            shape = new Triangle(b, h);
        }
        else if (choice == 4) {
            double s;
            cout << "Enter side length: ";
            cin >> s;
            shape = new Square(s);
        }
        else {
            cout << "Invalid choice.\n";
            return 0;
        }

        cout << "Calculated Area: " << shape->area() << endl;
        delete shape;
    }
    catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
