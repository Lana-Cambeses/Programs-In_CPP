
#include <iostream>
#include "Circle.h"

using namespace std;

int main(){
    Circle c; // Circle c = Circle();
    Circle c2(5); // Circle c2 = Circle(50);

    Circle c3 = Circle(50, 2, 3);

    c3.Print();

    c.SetRadius(100);

    cout << c.GetRadius() << endl;

    c2.SetCenterX(55);
    c2.SetCenterY(66);

    c2.Print();



    return 0;
}