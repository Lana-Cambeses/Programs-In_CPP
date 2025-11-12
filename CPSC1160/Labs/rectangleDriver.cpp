#include <iostream>
#include "Rectangle.h"

using namespace std;

int main() {

    Rectangle r; // Rectangle r = Rectangle();
    Rectangle r2(5.5, 3); 

    //Values
    cout << "Default rectangle values:" << endl;
    cout << r.getWidth() << endl;
    cout << r.getHeight() << endl;
    cout << endl << "Defined rectangle values:" << endl;
    cout << r2.getWidth() << endl;
    cout << r2.getHeight() << endl;

    cout << endl;

    //Getters & Setters
    cout << "Changed values for defined rectangle:" << endl;
    r2.setWidth(4);
    cout << r2.getWidth() << endl;
    r2.setHeight(6.5);
    cout << r2.getHeight() << endl;

    cout << endl;

    //Methods
    cout << "Area and Perimeter of default rectangle:" << endl;
    cout << r.getArea() << endl;
    cout << r.getPerimeter() << endl;
    cout << endl << "Area and Perimeter of defined rectangle:" << endl;
    cout << r2.getArea() << endl;
    cout << r2.getPerimeter() << endl;

    return 0;
}