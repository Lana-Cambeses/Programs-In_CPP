#include <iostream>
using namespace std;

bool isSorted(int* list, int size);

int main() {

    //Enter values for list 1
    cout << "Enter a list size: " << endl;
    int size;
    cin >> size;
    cout << "Enter the list: " << endl;
    int* list = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> list[i];
    }

    if (isSorted(list, size)) {
        cout << "The list is already sorted" << endl;
    } else {
        cout << "The list is not sorted" << endl;
    }


    return 0;
}

bool isSorted(int* list, int size) {
for (int i = 0; i < size - 1; i++) {
    if (list[i] > list[i + 1]) {
        return false;
    }
}

return true;
}