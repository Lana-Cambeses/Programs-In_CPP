#include <iostream>
using namespace std;

int main() {

    float km = 14.0;
    float timeInSec = (45 * 60) + 30;

    float kmToMile = km * 1.6;
    float secToHour = (timeInSec / 60) / 60;

    float speed = kmToMile / secToHour;

    cout << speed << endl;

    return 0;
}