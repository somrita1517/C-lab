#include <iostream>
using namespace std;

// Call by value: a copy of the arguments is passed.
void callByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;

    cout << "Inside callByValue: a = " << a
         << ", b = " << b << endl;
}

// Call by reference: the original variables are passed by reference.
void callByReference(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;

    cout << "Inside callByReference: a = " << a
         << ", b = " << b << endl;
}

int main() {
    int x, y;

    cout << "Enter two numbers: ";
    cin >> x >> y;

    cout << "\\nBefore callByValue: x = " << x
         << ", y = " << y << endl;
    callByValue(x, y);
    cout << "After callByValue:  x = " << x
         << ", y = " << y << endl;

    cout << "\\nBefore callByReference: x = " << x
         << ", y = " << y << endl;
    callByReference(x, y);
    cout << "After callByReference:  x = " << x
         << ", y = " << y << endl;

    return 0;
}

/*
SAMPLE OUTPUT:

Enter two numbers: 10 20

Before callByValue: x = 10, y = 20
Inside callByValue: a = 20, b = 10
After callByValue:  x = 10, y = 20

Before callByReference: x = 10, y = 20
Inside callByReference: a = 20, b = 10
After callByReference:  x = 20, y = 10
*/
