#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int getDice();

int main() {
    int dice = getDice();
    if (dice == 7 || dice == 11) {
        cout << "You win";
        exit(1);
    } else if (dice == 2 || dice == 3 || dice == 12) {
        cout << "You lose";
        exit(2);
    }

    int point = dice;
    cout << "point is  " << point << endl;
    do {
        dice = getDice();
    } while (dice != 7 && dice != point);

    if (dice == 7) {
        cout << "You lose";
    } else {
        cout << "You win";
    }


    return 0;
}

int getDice() {
    srand(time(0));
    int i1 = (rand() % 6) + 1;
    int i2 = (rand() % 6) + 1;

    cout << "You rolled " << i1 << " + "<< i2 << " = " << (i1 + i2) << endl;
    return i1 + i2;
}