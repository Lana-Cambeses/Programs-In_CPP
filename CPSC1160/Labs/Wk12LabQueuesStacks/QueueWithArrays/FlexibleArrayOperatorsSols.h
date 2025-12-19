#ifndef FLEXIBLEARRAYOPERATORSSOLS_H
#define FLEXIBLEARRAYOPERATORSSOLS_H

#include <iostream>
using namespace std;

class FlexibleArrayOperators {
private:
    int* data;       // Pointer to dynamically allocated array
    int size;        // Current number of elements
    int capacity;    // Max number of elements without resizing

    // Resizes the internal array to new_capacity.
    // If new_capacity <= size, then no resizing occurs.
    // If new_capacity < 1, it is set to 1.
    // all existing elements are copied to the new array in the same order.
    void resize(int new_capacity) {
        if (new_capacity <= size) {
            return; // No need to resize if new capacity is less than or equal to current size
        }
        if (new_capacity < 1) {
            new_capacity = 1; // Ensure capacity is at least 1
        }

        int* new_data = new int[new_capacity]; // Allocate new array
        for (int i = 0; i < size; ++i) {
            new_data[i] = data[i]; // Copy existing elements
        }
        
        delete[] data; // Deallocate old array
        data = new_data; // Point to the new array
        capacity = new_capacity; // Update capacity        
    }

    void deleteData() {
        if (data != nullptr) {
            delete[] data; // Deallocate memory if data is not null
        }
        data = nullptr; // Set data to null after deletion
        size = 0; // Reset size
        capacity = 0; // Reset capacity
    }

    int placePivot(int left, int right) {
        int pivot = data[left];
        int low = left + 1;
        int high = right;

        while (true) {
            while (low <= right && data[low] <= pivot) {
                low++;
            }
            while (high >= left && data[high] > pivot) {
                high--;
            }
            if (low > high) {
                break; // If pointers cross, we found the correct position for the pivot
            }
            swap(data[low], data[high]); // Swap elements to partition the array
        }
        swap(data[left], data[high]); // Place the pivot in its correct position
        return high; // Return the index of the pivot
    }

public:
    // Default constructor: initializes empty array with capacity 1.
    FlexibleArrayOperators() {
        size = 0; 
        capacity = 1;
        data = new int[capacity];
    }

    // Constructor: builds from existing array.
    // Example: FlexibleArrayOperators arr(a, 5);
    FlexibleArrayOperators(int *arr, int arr_size) {
        if (arr_size < 1) {
            cout << "Invalid array size. Initializing to default state." << endl;
            size = 0;
            capacity = 1;
            data = new int[capacity];
            return; // If the array size is invalid, initialize to default state
        }
        size = arr_size; 
        capacity = arr_size;
        data = new int[capacity];
        for (int i = 0; i < arr_size; ++i)
            data[i] = arr[i];
    }

    // Constructor: creates an array with a single item.
    // Example: FlexibleArrayOperators arr(5); // creates an array of size 1 which contains value 5
    FlexibleArrayOperators(int item) {
        size = 1; 
        capacity = 1;
        data = new int[capacity];
        data[0] = item; // Initialize the single element with the provided item
    }

    // Constructor: creates an array with specified capacity (and size) and initializes all elements to a specified value.
    // If capacity < 1, it is set to 1.
    // Example: FlexibleArrayOperators arr(5, 0); // creates an array of size/capacity 5, all elements initialized to 0
    FlexibleArrayOperators(int _capacity, int initial_value) {
        size = 0; 
        capacity = _capacity;
        if (capacity < 1) {
            capacity = 1; // Ensure capacity is at least 1
        }
        data = new int[capacity];
        for (int i = 0; i < capacity; ++i) {
            data[i] = initial_value; // Initialize all elements to the specified value
        }
    }

    // Deep copy constructor: makes a DEEP copy of another FlexibleArrayOperators object.
    FlexibleArrayOperators(const FlexibleArrayOperators& other) {
        if (this == &other) {
            return; // Handle self-assignment
        }
        if(other.capacity < 1) {
            // if other has no elements, initialize to default state
            size = 0; 
            capacity = 1;
            data = new int[capacity];
            return;
        }
        // Allocate new memory and copy the elements
        size = other.size;
        capacity = other.capacity;
        data = new int[capacity];
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    // Destructor: deallocates dynamic memory allocated within object.
    ~FlexibleArrayOperators() {
        deleteData(); // Call deleteData to deallocate all memory
    }

    // Returns current size.
    int getSize() const {
        return size;
    }

    // Returns current capacity.
    int getCapacity() const {
        return capacity;
    }

    // Returns true if array is empty.
    bool isEmpty() const {
        return size == 0;
    }

    // Returns value at index, outputs an error message if index out of bounds and returns 0.
    int get(int index) const {
        if (index < 0 || index >= size){
            cout << "Index out of range. Returning 0." << endl;
            return 0;
        }
        
        return data[index]; // Return the value at the specified index
    }

    int getFirstValue() const{
        if(isEmpty()){
            cout << "empty array! Returning 0\n";
            return 0;
        }
        return data[0];
    }
    int getLastValue() const{
        if(isEmpty()){
            cout << "empty array! Returning 0\n";
            return 0;
        }
        return data[size - 1];
    }
    // Sets value at index, outputs an error message if index out of bounds.
    void set(int index, int value) {
        if (index < 0 || index >= size){
            cout << "Index out of range. Nothing set." << endl;
            return; // Do not set value if index is out of bounds
        }

        data[index] = value; // Set the value at the specified index
    }

    // Clears the array. resets it to default state (size 0, capacity 1).
    void clear() {
        if(data == nullptr) 
            return; // If data is already null, do nothing

        // delete data and reset object to default state
        delete[] data;
        data = new int[1];
        size = 0;
        capacity = 1;
    }

    // Adds value to end of array, resizing if necessary.
    // if the size equals capacity, it doubles its capacity (by calling resize first).
    void pushBack(int value) {
        if (size == capacity) {
            resize(capacity * 2); // Double the capacity if size equals capacity
        }
        data[size] = value; // Add the new value at the end of the array
        size++; // Increment the size
    }

    // Adds value to front, all other elements shifted to the right by 1 position, resize if needed.
    // if the size equals capacity, it doubles its capacity (by calling resize first).
    void pushFront(int value) {
        if (size == capacity) {
            resize(capacity * 2); // Double the capacity if size equals capacity
        }
        // Shift all elements to the right by 1
        for (int i = size; i > 0; --i) {
            data[i] = data[i - 1];
        }
        data[0] = value; // Insert the new value at the front
        size++; // Increment the size
    }

    // Inserts value at index. all elements from index to end of array are shifted to the right by 1
    // if the size equals capacity, it doubles its capacity (by calling resize first).
    void insertAt(int index, int value) {
        if (index < 0 || index >= (size + 1)){
            cout << "Index out of range." << endl;
        }
        if (size == capacity) {
            resize(capacity * 2); // Double the capacity if size equals capacity
        }
        // Shift all elements from index to the end to the right by 1
        for (int i = size; i > index; --i) {
            data[i] = data[i - 1];
        }
        size++; // Increment the size
        data[index] = value; // Insert the new value at the specified index
    }

    // Removes last element.
    void popBack() {
        if (isEmpty()){
            cout << "Array is empty!" << endl;
            return;
        }
        size--; // Decrement the size to remove the last element
    }

    // Removes first element.
    // shift second element to first, third to second, and so on
    int popFront() {
        if (isEmpty()){
            cout << "Array is empty!" << endl;
            return;
        }
        int val = data[0];
        // Shift all elements to the left by 1
        for (int i = 0; i < size - 1; ++i){
            data[i] = data[i + 1];
        }
        size--; // Decrement the size to remove the first element
        return val;
    }

    // Removes value at index.
    // all elements from index+1 to end of array are shifted to the left by 1
    void removeAt(int index) {
        if (index < 0 || index >= size){
            cout << "Index out of range." << endl;
            return;
        }
        // Shift all elements from index+1 to the end to the left by 1
        for (int i = index; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        size--; // Decrement the size to remove the element at the specified index
    }

    // Helper function for quicksort, sort all elements between left and right in ascending order
    // additional helper methods are allowed 
    bool isSorted() const {
        for (int i = 1; i < size; ++i) {
            if (data[i] < data[i - 1]) {
                return false; // If any element is less than the previous one, it's not sorted
            }
        }
        return true; // If no such element found, the array is sorted
    }

    void quickSort(int left, int right) {
        if (left < right) {
            int pivotIndex = placePivot(left, right); // Place the pivot and get its index
            quickSort(left, pivotIndex - 1); // Recursively sort the left part
            quickSort(pivotIndex + 1, right); // Recursively sort the right part
        }
        
    }

    // Sorts the whole array using quick sort.
    void sort() {
        if (!isEmpty())
            quickSort(0, size - 1);
    }
    

    // Binary search. Array must be sorted SO first CHECK IF IT IS SORTED.
    // returns index of value if found, or -1 if not found.
    int search(int value) const {
        if (!isSorted()) {
            cout << "Array is not sorted. Cannot perform binary search." << endl;
            return -1; // Return -1 if the array is not sorted
        }

        int left = 0;
        int right = size - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2; // Avoid overflow

            if (data[mid] == value) {
                return mid; // Value found
            } else if (data[mid] < value) {
                left = mid + 1; // Search in the right half
            } else {
                right = mid - 1; // Search in the left half
            }
        }
        return -1; // Value not found
    }

    // Prints the array.
    void print() const {
        cout << "Size: " << size << ", Capacity: " << capacity << ", Data: [";
        for (int i = 0; i < size; ++i) {
            cout << data[i];
            if (i < size - 1)
                cout << ", ";
        }
        cout << "]" << endl;
    }

    // Overload the = operator so that it can be used to deep copy another FlexibleArrayOperators object into the current object.
    // The current object should be modified to contain all elements from the other object.
    // If the current object is the same as the other object, it should handle self-assignment gracefully.
    // Example: FlexibleArrayOperators arr1, arr2;
    // arr1.pushBack(1); arr1.pushBack(2);
    // arr2 = arr1; // arr2 should now contain 1, 2 (its own copy of the data from arr1)
    FlexibleArrayOperators& operator=(const FlexibleArrayOperators& other) {
        if (this == &other) {
            return *this; // Handle self-assignment
        }
        deleteData(); // Deallocate current data

        size = other.size;
        capacity = other.capacity;
        data = new int[capacity]; // Allocate new memory
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i]; // Copy elements from the other array
        }
        return *this; // Return the current object to allow chaining
    }

    // Overload the + operator so that it can be used to join two FlexibleArrayOperators objects together into a new FlexibleArrayObject and return the newly created object.
    // The resulting array should contain all elements from both arrays in the order they were added.
    // The original arrays should remain unchanged.
    // Example: FlexibleArrayOperators arr1, arr2, arr3;
    // arr1.pushBack(1); arr1.pushBack(2);
    // arr2.pushBack(3); arr2.pushBack(4);
    // arr3 = arr1 + arr2; // arr3 should contain 1, 2, 3, 4, arr1 should still contain 1, 2 and arr2 should still contain 3, 4
    FlexibleArrayOperators operator+(const FlexibleArrayOperators& other) const {
        FlexibleArrayOperators result;
        result.resize(size + other.size); // Resize to fit both arrays

        for (int i = 0; i < size; ++i) {
            result.pushBack(data[i]); // Add elements from the first array
        }
        for (int i = 0; i < other.size; ++i) {
            result.pushBack(other.data[i]); // Add elements from the second array
        }
        return result; // Return the new combined array
    }

    // Overload the + operator so that it can be used to add a new integer value to the end of the current array and the resulting array is returned as a new FlexibleArrayOperators object.
    // The original array should remain unchanged.
    // Example: FlexibleArrayOperators arr, arr2;
    // arr.pushBack(1); arr.pushBack(2);
    // arr2 = arr + 3; // arr2 should contain 1, 2, 3, arr should still contain 1, 2
    FlexibleArrayOperators operator+(int value) const {
        FlexibleArrayOperators result(*this); // Create a copy of the current array
        result.pushBack(value); // Add the new value to the end
        return result; // Return the new array with the added value
    }

    // Overload the - operator so that it can be used to remove the last n elements from the current array and return the resulting array as a new FlexibleArrayOperators object. n should be a positive integer.
    // If n is greater than the current size, the resulting array should be empty.
    // The original array should remain unchanged.
    // Example: FlexibleArrayOperators arr, arr2;
    // arr.pushBack(1); arr.pushBack(2); arr.pushBack(3);
    // arr2 = arr - 2; // arr2 should contain 1, arr should still contain 1, 2, 3
    FlexibleArrayOperators operator-(int n) const {
        if (n < 0) {
            cout << "Cannot remove negative number of elements." << endl;
            return *this; // Return the current array unchanged if n is negative
        }
        FlexibleArrayOperators result(*this); // Create a copy of the current array
        if (n >= result.size) {
            result.clear(); // If n is greater than or equal to size, clear the array
        } else {
            result.size -= n; // Reduce the size by n
        }
        return result; // Return the new array with the last n elements removed
    }

    // Overload the - operator so that it can be used to remove the occurrences of items in some FlexibleArrayOperators object from the current array and return the resulting array as a new FlexibleArrayOperators object.
    // The original array should remain unchanged.
    // Example: FlexibleArrayOperators arr1, arr2, arr3;
    // arr1.pushBack(1); arr1.pushBack(2); arr1.pushBack(3); arr1.pushBack(5); arr1.pushBack(2);
    // arr2.pushBack(2); arr2.pushBack(3);
    // arr3 = arr1 - arr2; // arr3 should contain 1, 5, arr1 should still contain 1, 2, 3, 5, 2 and arr2 should still contain 2, 3
    FlexibleArrayOperators operator-(const FlexibleArrayOperators& other) const {
        FlexibleArrayOperators result(*this); // Create a copy of the current array

        for (int i = 0; i < other.size; ++i) {
            int valueToRemove = other.data[i]; // Get the value to remove
            for (int j = 0; j < result.size; ) {
                if (result.data[j] == valueToRemove) {
                    result.removeAt(j); // Remove the value if found
                } else {
                    j++; // Only increment if no removal occurred
                }
            }
        }
        return result; // Return the new array with specified values removed
    }
    
    // Overload the += operator so that it can be used to join two FlexibleArrayOperators objects together into the current object.
    // The original arrays should be modified to include all elements from both arrays in the order they were added.
    // Example: FlexibleArrayOperators arr1, arr2;
    // arr1.pushBack(1); arr1.pushBack(2);
    // arr2.pushBack(3); arr2.pushBack(4);
    // arr1 += arr2; // arr1 should now contain 1, 2, 3, 4, arr2 should still contain 3, 4
    FlexibleArrayOperators& operator+=(const FlexibleArrayOperators& other) {
        if (this == &other) {
            return *this; // Handle self-assignment
        }
        resize(size + other.size); // Resize to fit both arrays

        for (int i = 0; i < other.size; ++i) {
            pushBack(other.data[i]); // Add elements from the other array
        }
        return *this; // Return the current object to allow chaining
    }

    // Overload the += operator so that it can be used to add a new integer value to the end of the current array.
    // The original array should be modified to include the new value.
    // Example: FlexibleArrayOperators arr;
    // arr.pushBack(1); arr.pushBack(2);
    // arr += 3; // arr should now contain 1, 2, 3
    FlexibleArrayOperators& operator+=(int value) {
        pushBack(value); // Add the new value to the end of the current array
        return *this; // Return the current object to allow chaining
    }

    // Overload the -= operator so that it can be used to remove the last n elements from the current array.
    // The original array should be modified to remove the last n elements.
    // If n is greater than the current size, the resulting array should be empty.
    // Example: FlexibleArrayOperators arr;
    // arr.pushBack(1); arr.pushBack(2); arr.pushBack(3);
    // arr -= 2; // arr should now contain 1
    FlexibleArrayOperators& operator-=(int n) {
        if (n < 0) {
            cout << "Cannot remove negative number of elements." << endl;
            return *this; // Return the current array unchanged if n is negative
        }
        if (n >= size) {
            clear(); // If n is greater than or equal to size, clear the array
        } else {
            size -= n; // Reduce the size by n
        }
        return *this; // Return the current object to allow chaining
    }

    // Overload the -= operator so that it can be used to remove the occurrences of items in some FlexibleArrayOperators object from the current array.
    // The original array should be modified to remove the specified values.
    // Example: FlexibleArrayOperators arr1, arr2;
    // arr1.pushBack(1); arr1.pushBack(2); arr1.pushBack(3); arr1.pushBack(5); arr1.pushBack(2);
    // arr2.pushBack(2); arr2.pushBack(3);
    // arr1 -= arr2; // arr1 should now contain 1, 5, arr2 should still contain 2, 3
    FlexibleArrayOperators& operator-=(const FlexibleArrayOperators& other) {
        if (this == &other) {
            return *this; // Handle self-assignment
        }

        for (int i = 0; i < other.size; ++i) {
            int valueToRemove = other.data[i]; // Get the value to remove
            for (int j = 0; j < size; ) {
                if (data[j] == valueToRemove) {
                    removeAt(j); // Remove the value if found
                } else {
                    j++; // Only increment if no removal occurred
                }
            }
        }
        return *this; // Return the current object to allow chaining
    }

    // Overload the [] operator so that it can be used to access elements at a specific index.
    // If the index is out of bounds, it should output an error message and return 0.
    // Example: FlexibleArrayOperators arr;
    // arr.pushBack(1); arr.pushBack(2);
    // cout << arr[0]; // Should output 1
    int operator[](int index) const {
        if (index < 0 || index >= size) {
            cout << "Index out of range. Returning 0." << endl;
            return 0; // Return 0 if index is out of bounds
        }
        return data[index]; // Return the value at the specified index
    }

    // Overload the ! operator so that it can be used to check if the array is empty.
    // It should return true if the array is empty, and false otherwise.
    // Example: FlexibleArrayOperators arr;
    // if (!arr) { cout << "Array is empty"; }
    bool operator!() const {
        return !isEmpty(); // Return true if the array is not empty, false otherwise
    }

    // Overload the == operator so that it can be used to compare two FlexibleArrayOperators objects for equality.
    // Two arrays are considered equal if they have the same size and all corresponding elements are equal.
    // Example: FlexibleArrayOperators arr1, arr2;
    // arr1.pushBack(1); arr1.pushBack(2);
    // arr2.pushBack(1); arr2.pushBack(2);
    // if (arr1 == arr2) { cout << "Arrays are equal"; }
    bool operator==(const FlexibleArrayOperators& other) const {
        if (size != other.size) {
            return false; // Arrays are not equal if sizes differ
        }
        for (int i = 0; i < size; ++i) {
            if (data[i] != other.data[i]) {
                return false; // Return false if any corresponding elements differ
            }
        }
        return true; // All elements are equal, return true
    }

    // Overload prefix ++ operator so that it increments every element in the array (of the calling object) by 1 and then proceeds to increment the size of the array by 1 (also set 0 as the initial value of the newly added position)
    // Example: FlexibleArrayOperators arr, arr2;
    // arr.pushBack(1); arr.pushBack(2);
    // arr2 = ++arr; // at the end of this statement arr should contain 2, 3, 0 and arr2 should also contain 2, 3, 0
    FlexibleArrayOperators& operator++() {
        for (int i = 0; i < size; ++i) {
            data[i]++; // Increment each element by 1
        }
        pushBack(0); // Add a new element with value 0 at the end
        return *this; // Return the current object to allow chaining
    }

    // Overload postfix ++ operator so that it increments every element in the array (of the calling object) by 1 and then proceeds to increment the size of the array by 1 (also set 0 as the initial value of the newly added position)
    // Example: FlexibleArrayOperators arr, arr2;
    // arr.pushBack(1); arr.pushBack(2);
    // arr2 = arr++; // at the end of this statement arr should contain 2, 3, 0 and arr2 should contain 1, 2
    FlexibleArrayOperators operator++(int dummy) {
        FlexibleArrayOperators temp(*this); // Create a copy of the current array
        for (int i = 0; i < size; ++i) {
            data[i]++; // Increment each element by 1
        }
        pushBack(0); // Add a new element with value 0 at the end
        return temp; // Return the original array before incrementing
    }

    // Overload the >> operator as a friend function so that it can be used to read values into the array from an input stream (e.g., std::cin).
    // The operator should ask the user to input the size of the array and then read that many integers into the array.
    // Example: FlexibleArrayOperators arr;
    // cin >> arr; // User inputs the size and values, arr should now contain those values
    // Sample input/output:
    // Enter the size of the array: 5
    // Enter 5 elements: 1 2 3 4 5
    // After this, arr should contain 1, 2, 3, 4, 5, its size should be 5
    friend istream& operator>>(istream& in, FlexibleArrayOperators& arr);

    // Overload the << operator as a friend function so that it can be used to print the array to an output stream (e.g., std::cout).
    // The operator should print the size, capacity, and all elements of the array in a readable format.
    // Example: FlexibleArrayOperators arr;
    // cout << arr; // Should output the size, capacity, and elements of the array
    friend ostream& operator<<(ostream& out, const FlexibleArrayOperators& arr);   

};


istream& operator>>(istream& in, FlexibleArrayOperators& arr) {
    arr.deleteData(); // Clear any existing data before reading new input
    cout << "Enter the size of the array (positive integer only): ";
    in >> arr.size; // Read the size of the array
    arr.resize(arr.size); // Resize the array to the new size

    cout << "Enter " << arr.size << " elements: ";
    for (int i = 0; i < arr.size; ++i) {
        in >> arr.data[i]; // Read each element into the array
    }
    return in; // Return the input stream to allow chaining
}

ostream& operator<<(ostream& out, const FlexibleArrayOperators& arr) {
    out << "Size: " << arr.size << ", Capacity: " << arr.capacity << ", Data: [";
    for (int i = 0; i < arr.size; ++i) {
        out << arr.data[i];
        if (i < arr.size - 1)
            out << ", ";
    }
    out << "]" << endl;
    return out; // Return the output stream to allow chaining
}

#endif
