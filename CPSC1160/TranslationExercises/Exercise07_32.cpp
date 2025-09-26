#include <iostream>
using namespace std;

int partition(int* list, int size);

int main() {
    // Enter values for list1
    cout << "Enter a list size: " << endl;
    int size;
    cin >> size;
    int* list = new int[size];
    cout << "Enter the list: " << endl;

    for (int i = 0; i < size; i++) 
      cin >> list[i];

    partition(list, size);

    cout << "After the partition, the list is " << endl;

    for (int i = 0; i < size; i++)
      cout << list[i] << " ";

    return 0;
}

int partition(int* list, int size) {
  	int first = 0;
  	int last = size - 1;
    int pivot = list[first]; // Choose the first element as the pivot
    int low = first + 1; // Index for forward search
    int high = last; // Index for backward search

    while (high > low) {
      // Search forward from left
      while (low <= high && list[low] <= pivot)
        low++;

      // Search backward from right
      while (low <= high && list[high] > pivot)
        high--;

      // Swap two elements in the list
      if (high > low) {
        int temp = list[high];
        list[high] = list[low];
        list[low] = temp;
      }
    }

    while (high > first && list[high] >= pivot)
      high--;

    // Swap pivot with list[high]
    if (pivot > list[high]) {
      list[first] = list[high];
      list[high] = pivot;
      return high;
    }
    else {
      return first;
    }
  }