#include <iostream>
#include <iomanip>
using namespace std;

class Shape {
private:
    double radius;
    double length;
    double width;

public:
    // Default constructor
    Shape() {
        radius = 0;
        length = 0;
        width = 0;
        cout << "Shape object created." << endl;
    }

    // Parameterized constructor
    Shape(double r, double l, double w) {
        radius = r;
        length = l;
        width = w;
        cout << "Shape object created with given dimensions." << endl;
    }

    // Function to calculate circumference of a circle
    double circlePerimeter() {
        return 2 * 3.14159 * radius;
    }

    // Function to calculate perimeter of a rectangle
    double rectanglePerimeter() {
        return 2 * (length + width);
    }

    // Destructor
    ~Shape() {
        cout << "Shape object destroyed." << endl;
    }
};

int main() {
    double r, l, w;

    cout << "Enter radius of circle: ";
    cin >> r;

    cout << "Enter length of rectangle: ";
    cin >> l;

    cout << "Enter width of rectangle: ";
    cin >> w;

    {
        Shape s(r, l, w);

        cout << fixed << setprecision(2);
        cout << "\\nPerimeter of Circle    : "
             << s.circlePerimeter() << endl;
        cout << "Perimeter of Rectangle : "
             << s.rectanglePerimeter() << endl;
    } // Destructor is called when s goes out of scope.

    return 0;
}

/*
SAMPLE OUTPUT:

Enter radius of circle: 7
Enter length of rectangle: 10
Enter width of rectangle: 5
Shape object created with given dimensions.

Perimeter of Circle    : 43.98
Perimeter of Rectangle : 30.00
Shape object destroyed.
*/
