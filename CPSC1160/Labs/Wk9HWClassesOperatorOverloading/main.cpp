//Name: Lana Cambeses
//Student ID: 100411765
//Title: CPSC 1160 - Week 9 Homework
//Date: November 13, 2025

#include <iostream>
#include "FlexibleArrayOperators.h";
using namespace std;



int main() {

    int baseArr[] = {1, 2, 3};
    FlexibleArrayOperators a(baseArr, 3);
    FlexibleArrayOperators b(5);
    FlexibleArrayOperators c;

    a.pushBack(4);
    a.pushFront(0);
    a.insertAt(2, 99);

    cout << "1. Array a after insertions:\n" << a << endl;

    a.popBack();
    a.popFront();
    a.removeAt(1);

    cout << "2. Array a after removals:\n" << a << endl;

    b.pushBack(6);
    b.pushBack(7);

    cout << "3. Array b:\n" << b << endl;

    FlexibleArrayOperators d = a + b;
    cout << "4. Array d (a + b):\n" << d << endl;

    FlexibleArrayOperators e = a + 42;
    cout << "5. Array e (a + 42):\n" << e << endl;

    a += b;
    cout << "6. Array a after a += b:\n" << a << endl;

    cout << "7. Element at index 2 of a: " << a[2] << endl;
    cout << endl;
    cout << "8. Out-of-bounds access: " << a[100] << endl;
    cout << endl;

    if (!c) {
        cout << "9. Array c is empty.\n" << endl;
    }

    ++a;
    cout << "10. After prefix ++a:\n" << a << endl;

    FlexibleArrayOperators f = a++;
    cout << "11. Array f (from a++):\n" << f << endl;
    cout << "12. Array a after a++:\n" << a << endl;

    FlexibleArrayOperators g;
    cin >> g;
    cout << "13. Entered:\n" << g << endl;

    FlexibleArrayOperators h;
    h = a;
    cout << "14. Array h (copy of a):\n" << h << endl;
    

    return 0;
}