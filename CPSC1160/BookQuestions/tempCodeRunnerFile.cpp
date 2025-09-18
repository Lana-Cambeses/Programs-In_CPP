/* *1.3 (Display a pattern) Write a program that displays the following pattern:

  CCCC    +        +     
 C        +        +     
C      +++++++  +++++++  
 C        +        +     
  CCCC    +        +    */

#include <iostream>
using namespace std;

int main() {

    for (int i = 0; i < 5; i++) {
        if (i == 0 || i == 4) {
            cout << "  CCCC    +        +" << endl;
        } else if (i == 1 || i == 3) {
            cout << " C        +        +" << endl;
        } else {
            cout << "C      +++++++  +++++++" << endl;
        }
    }


    return 0;
}