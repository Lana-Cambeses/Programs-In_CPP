#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {

    srand(time(0));

    const int SIZE = 100;
    int* counts = new int[10]();

    for (int i = 0; i < SIZE; i++) {
        int value = (rand() % 9);
        counts[value] += 1;
    }

    for (int i = 0; i < 10; i++) {
        cout << "Count for " << i << " is " << counts[i] << endl;
    }


    return 0;
}