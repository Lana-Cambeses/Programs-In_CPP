//Name: Lana Cambeses
//Student ID: 100411765
//Title: CPSC 1160 - Week 9 Homework
//Date: November 13, 2025
#ifndef FLEXIBLEARRAYOPERATORS_H
#define FLEXIBLEARRAYOPERATORS_H

#include <iostream>
using namespace std;

class FlexibleArrayOperators {
private:
    int* data;       // Pointer to dynamically allocated array
    int size;        // Current number of elements
    int capacity;    // Max number of elements without resizing

    // Resizes the internal array (data) to new_capacity.
    // If new_capacity <= size, then no resizing occurs.
    // If new_capacity < 1, it is set to 1.
    // all existing elements are copied to the new array in the same order.
    void resize(int new_capacity) {
        if (new_capacity <= size) {
            return;
        } 
        
        if (new_capacity < 1) {
            new_capacity = 1;
        } 

        int* new_data = new int[new_capacity];

        for (int i = 0; i < size; i++) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
        
    }

    // Deallocates memory and sets data, size, and capacity to nullptr, 0 and 0 respectively.
    void deleteData() {
        if (data) {
            delete[] data;
            data = nullptr;
            size = 0;
            capacity = 0;
        }
    }

public:
    // Default constructor: initializes empty array with capacity 1.
    FlexibleArrayOperators() {
        data = nullptr;
        size = 0; 
        capacity = 1;
        data = new int[capacity];
    }

    // Constructor: builds from existing array.
    // Example: FlexibleArrayOperators arr(a, 5); creates an array containing elements of a of size 5
    // If arr_size < 1, initializes to default state (see default constructor for default values).
    FlexibleArrayOperators(int *arr, int arr_size) {
        data = nullptr;
        if (arr_size < 1) {
            size = 0; 
            capacity = 1;
            data = new int[capacity];
        } else {
            size = arr_size; 
            capacity = arr_size;
            data = new int[capacity];
            for (int i = 0; i < size; i++) {
                data[i] = arr[i];
            }
        }
    }

    // Constructor: creates an array with a single item.
    // Example: FlexibleArrayOperators arr(5); // creates an array of size 1 which contains value 5
    FlexibleArrayOperators(int item) {
        data = nullptr;
        size = 1; 
        capacity = 1;
        data = new int[capacity];
        data[0] = item;
    }

    // Deep copy constructor: makes a DEEP copy of another FlexibleArrayOperators object.
    FlexibleArrayOperators(const FlexibleArrayOperators& other) {
        this->data = nullptr;
        this->capacity = other.capacity;
        this->size = other.size;
        this->data = new int[this->capacity];
        for (int i = 0; i < this->capacity; i++) {
            this->data[i] = other.data[i];
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

    // Returns true if array is empty, false otherwise.
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

    // Sets value at index, outputs an error message if index out of bounds.
    void set(int index, int value) {
        if (index < 0 || index >= size){
            cout << "Index out of range. Nothing set." << endl;
            return; // Do not set value if index is out of bounds
        }

        data[index] = value; // Set the value at the specified index
    }

    // Clears the array, i.e. deallocates memory and sets data, size and capacity to default state (size 0, capacity 1).
    void clear() {
        if (data) {
            delete[] data;
            data = nullptr;
            size = 0;
            capacity = 1;
        }
    }

    // Adds value to end of array, resizing if necessary.
    // if the size equals capacity, it doubles its capacity (by calling resize first).
    void pushBack(int value) {
        if (size == capacity) {
            resize(capacity * 2);
        }

        data[size] = value;
        size++;
    }

    // Adds value to front, all other elements shifted to the right by 1 position, resize if needed.
    // if the size equals capacity, it doubles its capacity (by calling resize first).
    void pushFront(int value) {
        if (size == capacity) {
            resize(capacity * 2);
        }

        for (int i = size; i > 0; i--) {
            data[i] = data[i - 1];
        }

        data[0] = value;
        size++;

    }

    // Inserts value at index. all elements from index to end of array are shifted to the right by 1
    // if the size equals capacity, it doubles its capacity (by calling resize first).
    void insertAt(int index, int value) {
        if (index < 0 || index > size) {
            cout << "Invalid index." << endl;
            return;
        }

        if (size == capacity) {
            resize(capacity * 2);
        }

        for (int i = size; i > index; i--) {
            data[i] = data[i - 1];
        }

        data[index] = value;
        size++;
    }

    // Removes last element.
    void popBack() {
        if (size > 0) {
            size--;
        } else {
            cout << "Can't reduce array.\n";
        }
    }

    // Removes first element.
    // shift second element to first, third to second, and so on
    void popFront() {
        if (size > 0) {

            for (int i = 0; i < size - 1; i++) {
                data[i] = data[i + 1];
            }

            size--;
        } else {
            cout << "Can't reduce array.\n";
        }

    }

    // Removes value at index.
    // all elements from index+1 to end of array are shifted to the left by 1
    void removeAt(int index) {
        if (size > 0) {
            if (index < 0 || index >= size) {
                cout << "Invalid index.\n";
                return;
            }

            for (int i = index; i < size - 1; i++) {
                data[i] = data[i + 1];
            }

            size--;
        } else {
            cout << "Can't reduce array.\n";
        }
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
            return *this; 
        }

        deleteData();

        this->size = other.size;
        this->capacity = other.capacity;
        this->data = new int[this->capacity];

        for (int i = 0; i < this->size; i++) {
            this->data[i] = other.data[i];
        }

        return *this;
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
        result.size = this->size + other.size;
        result.capacity = result.size;
        result.data = new int[result.capacity];

        for (int i = 0; i < this->size; i++) {
            result.data[i] = this->data[i];
        }
        for (int i = this->size, j = 0; i < result.size; i++, j++) {
            result.data[i] = other.data[j];
        }

        return result;

    }

    // Overload the + operator so that it can be used to add a new integer value to the end of the current array and the resulting array is returned as a new FlexibleArrayOperators object.
    // The original array should remain unchanged.
    // Example: FlexibleArrayOperators arr, arr2;
    // arr.pushBack(1); arr.pushBack(2);
    // arr2 = arr + 3; // arr2 should contain 1, 2, 3, arr should still contain 1, 2
    FlexibleArrayOperators operator+(int value) const {
        FlexibleArrayOperators result;
        result.size = this->size;
        result.capacity = this->capacity;
        result.data = new int[result.capacity];

        for (int i = 0; i < this->size; i++) {
            result.data[i] = this->data[i];
        }

        if (result.size == result.capacity) {
            result.resize(result.capacity * 2);
        }

        result.data[result.size] = value;
        result.size++;
        
        return result;
    }
    
    // Overload the += operator so that it can be used to join two FlexibleArrayOperators objects together into the current object.
    // The original arrays should be modified to include all elements from both arrays in the order they were added.
    // Example: FlexibleArrayOperators arr1, arr2;
    // arr1.pushBack(1); arr1.pushBack(2);
    // arr2.pushBack(3); arr2.pushBack(4);
    // arr1 += arr2; // arr1 should now contain 1, 2, 3, 4, arr2 should still contain 3, 4
    FlexibleArrayOperators& operator+=(const FlexibleArrayOperators& other) {
        *this = *this + other; // Professor Muntaseer's tip
        
        // if (other.size == 0) {
        //     return *this;
        // } 
        
        // if (capacity < size + other.size) {
        //     resize(size + other.size);               
        // }

        // for (int j = 0; j < other.size; ++j) {
        //     data[size + j] = other.data[j];
        // }

        // size += other.size;
        return *this;
    }

    // Overload the [] operator so that it can be used to access elements at a specific index.
    // If the index is out of bounds, it should output an error message and return 0.
    // Example: FlexibleArrayOperators arr;
    // arr.pushBack(1); arr.pushBack(2);
    // cout << arr[0]; // Should output 1
    int operator[](int index) const {
        if (index < 0 || index >= size) {
            cout << "Error: Index out of bounds." << endl;
            return 0;
        }
        return data[index];
    }

    // Overload the ! operator so that it can be used to check if the array is empty.
    // It should return true if the array is empty, and false otherwise.
    // Example: FlexibleArrayOperators arr;
    // if (!arr) { cout << "Array is empty"; }
    bool operator!() const {
        if (size <= 0) {
            return true;
        }

        return false;
    }

    // Overload prefix ++ operator so that it increments every element in the array (of the calling object) by 1 and then proceeds to increment the size of the array by 1 (also set 0 as the initial value of the newly added position)
    // Example: FlexibleArrayOperators arr, arr2;
    // arr.pushBack(1); arr.pushBack(2);
    // arr2 = ++arr; // at the end of this statement arr should contain 2, 3, 0 and arr2 should also contain 2, 3, 0
    FlexibleArrayOperators& operator++() {
        for (int i = 0; i < size; i++) {
            data[i]++;
        }

        if (size == capacity) {
            resize(capacity * 2);
        }

        data[size] = 0;
        size++;
        return *this;
    }

    // Overload postfix ++ operator so that it increments every element in the array (of the calling object) by 1 and then proceeds to increment the size of the array by 1 (also set 0 as the initial value of the newly added position)
    // Example: FlexibleArrayOperators arr, arr2;
    // arr.pushBack(1); arr.pushBack(2);
    // arr2 = arr++; // at the end of this statement arr should contain 2, 3, 0 and arr2 should contain 1, 2
    FlexibleArrayOperators operator++(int dummy) {
        FlexibleArrayOperators temp = *this;

        for (int i = 0; i < size; i++) {
            data[i]++;
        }

        if (size == capacity) {
            resize(capacity * 2);
        }

        data[size] = 0;
        size++; 

        return temp;
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
    arr.clear();

    cout << "Enter the size of the array: ";
    int newSize;
    in >> newSize;

    if (newSize < 0) {
        cout << "Invalid size.\n";
        return in;
    }

    arr.size = newSize;
    arr.capacity = arr.size * 2;
    arr.data = new int[arr.capacity];

    cout << "Enter " << arr.size << " elements: ";
    for (int i = 0; i < arr.size; i++) {
        in >> arr.data[i];
    }

    return in;
    
}

ostream& operator<<(ostream& out, const FlexibleArrayOperators& arr) {
    out << "Size: " << arr.size << ", Capacity: " << arr.capacity << ", Data: [";
    for (int i = 0; i < arr.size; ++i) {
        out << arr.data[i];
        if (i < arr.size - 1)
            out << ", ";
    }
    out << "]" << endl;
    return out;
}

#endif
