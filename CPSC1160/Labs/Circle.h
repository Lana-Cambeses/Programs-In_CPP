#ifndef CIRCLE_H
#define CIRCLE_H
#include <iostream>

using namespace std;

class Circle{
    private:
     double radius;
     int centerX;
     int centerY;

    public:
    // constructors (always return an Object of the class, hence no return type)
    Circle(){ //  default/ no-arg
        radius = 1.0;
        centerX = centerY = 0;
    }

    Circle(double rad){ //  defined
        radius = rad;
        centerX = centerY = 0;
    }

    Circle(double rad, int x, int y){ //. defined
        radius = rad;
        centerX = x;
        centerY = y;
    }

    // destructor
    ~Circle(){
        cout << "destructor called on circle with radius " << radius << endl;
    }
    // getters (accessors) / setters (mutators)
    double GetRadius(){
        return radius;
    }

    void SetRadius(double r){
        if(r <= 0){
            cout << "invalid radius";
            return;
        }
        radius = r;
    }

    int GetCenterX(){
        return centerX;
    }
    void SetCenterX(int x){
        centerX = x;
    }

    int GetCenterY(){
        return centerY;
    }
    void SetCenterY(int y){
        centerY = y;
    }

    // other methods
    void Print(){
        cout << "radius: " << radius << ", center: " << centerX << ", " << centerY << endl;
    }
};

#endif