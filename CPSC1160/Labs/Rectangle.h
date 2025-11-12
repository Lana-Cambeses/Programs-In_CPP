#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>
using namespace std;

class Rectangle{
private:
    double width;
    double height;


public:
    Rectangle(){
        width = 1;
        height = 1;

    }

    Rectangle(double w, double h){
        if (w > 0 && h > 0) {
            width = w;
            height = h;
        } else {
            cout << "Invalid value for Width or Height" << endl;
        }
        
    }

    // create accessors and mutators for width and height
    double getWidth() {
        return width;
    }

    void setWidth(double w) {
        if (w > 0) {
            width = w;
        } else {
            cout << "Invalid value for Width" << endl;
        }
    }

    double getHeight() {
        return height;
    }

    void setHeight(double h) {
        if (h > 0) {
            height = h;
        } else {
            cout << "Invalid value for Height" << endl;
        }
    }

    // create methods GetArea GetPerimeter
    double getArea() {
        return width * height;
    }

    double getPerimeter() {
        return (2 * width) + (2 * height);
    }

};

#endif