#include <iostream>
#include "LinkedList.h"
#include <climits>
using namespace std;

int main(){

    LinkedList list;

    for(int i = 1; i <= 10; i++){
        list.AddFirst(i);
    }
    list.Show();

    LinkedList list;
    cout << "Adding 10, 20, 30, 40, 50 to the list\n";
    list.AddLast(10);
    list.AddLast(20);
    list.AddLast(30);
    list.AddLast(40);
    list.AddLast(50);
    cout << "List after adding elements: ";
    list.Show();

    cout << "Length of the list: " << list.Length() << endl;

    cout << "Is the list empty? " << (list.IsEmpty() ? "Yes" : "No") << endl;

    // cout << "Reversing the list\n";
    // list.Reverse();
    // cout << "List after reversing: ";
    // list.Show();
    cout << "Removing first element: " << list.RemoveFirst() << endl;
    cout << "List after removing first element: ";
    list.Show();

    cout << "Removing last element: " << list.RemoveLast() << endl;
    cout << "List after removing last element: ";
    list.Show();
    cout << "Removing element at index 1: " << list.Remove(1) << endl;
    cout << "List after removing element at index 1: ";
    list.Show();
    
    return 0;
}

