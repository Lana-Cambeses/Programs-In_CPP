//Name: Lana Cambeses
//Student ID: 100411765
//Title: CPSC 1160 - Week 3 Homework
//Date: September 22, 2025

#include <iostream>
using namespace std;

//Function signatures:
void swap(int* a, int* b);
int* countPositives(int* arr, int* size);
void IncreaseSize(int* &arr, int* oldSize, int* newSize);
void DecreaseSize(int* &arr, int* oldSize, int* newSize);

int main() {

    /**Test swap function
     * test case : 
     * expected output :
     *  **/
    //Creating and alocating memory for the pointer variables
    int* x = new int(10);
    int* y = new int(20);

    //Function swap calling
    swap(x, y);

    //Printout of the results
    cout << "X new content: " << *x << endl;
    cout << "Y new content: " << *y << endl;

    //Dealocating and freeing up memory of the pointer variables
    if (x) {
        delete x;
        x = nullptr;
    }

    if (y) {
        delete y;
        y = nullptr;
    }

    /**Test count positive function
     * test case : [-1, 2, -3, 4, 5]
     * expected output : 3
     *  **/
    //Creating and alocating memory for the pointer variables
    int* size = new int(5);
    int* arr = new int[*size];
    *(arr) = -1;
    *(arr + 1) = 2;
    *(arr + 2) = -3;
    *(arr + 3) = 4;
    *(arr + 4) = 5;

    //Function countPositives calling
    int* t = countPositives(arr, size);

    cout << *t << endl;

    //Dealocating and freeing up memory of the pointer variables
    if (arr) {
        delete[] arr;
        arr = nullptr;
    }

    if (size) {
        delete size;
        size = nullptr;
    }

    if (t) {
        delete t;
        t = nullptr;
    }
    
    /**Test count positive function
     * test case : [-1, 2, -3, 4, 5] increased to size 8
     * expected output : [-1, 2, -3, 4, 5, 0, 0, 0]
     *  **/
    //Creating and alocating memory for the pointer variables
    int* sizeArr = new int(5);
    int* arr2 = new int[*sizeArr];
    int* newSize = new int(8);
    *(arr2) = -1;
    *(arr2 + 1) = 2;
    *(arr2 + 2) = -3;
    *(arr2 + 3) = 4;
    *(arr2 + 4) = 5;

    //Function IncreaseSize calling
    IncreaseSize(arr2, sizeArr, newSize);

    int* i = new int(0);
    for (; *i < *newSize; (*i)++) {
        cout << *(arr2 + *i) << " ";
    }
    cout << endl;

    //Dealocating and freeing up memory of the pointer variables
    if (arr2) {
        delete[] arr2;
        arr2 = nullptr;
    }

    if (sizeArr) {
        delete sizeArr;
        sizeArr = nullptr;
    }

    if (newSize) {
        delete newSize;
        newSize = nullptr;
    }

    if (i) {
        delete i;
        i = nullptr;
    }


     /**Test count positive function
     * test case : [-1, 2, -3, 4, 5] decreased to size 4
     * expected output : [-1, 2, -3, 4]
     *  **/
    //Creating and alocating memory for the pointer variables
    int* sizeArr3 = new int(5);
    int* arr3 = new int[*sizeArr3];
    int* newSize3 = new int(4);
    *(arr3) = -1;
    *(arr3 + 1) = 2;
    *(arr3 + 2) = -3;
    *(arr3 + 3) = 4;
    *(arr3 + 4) = 5;

    //Function IDecreaseSize calling
    DecreaseSize(arr3, sizeArr3, newSize3);

    int* j = new int(0);
    for (; *j < *sizeArr3; (*j)++) {
        cout << *(arr3 + *j) << " ";
    }
    cout << endl;

    //Dealocating and freeing up memory of the pointer variables
    if (arr3) {
        delete[] arr3;
        arr3 = nullptr;
    }

    if (sizeArr3) {
        delete sizeArr3;
        sizeArr3 = nullptr;
    }

    if (newSize3) {
        delete newSize3;
        newSize3 = nullptr;
    }

    if (j) {
        delete j;
        j = nullptr;
    }

    return 0;
}

//1. Swap function
void swap(int* a, int* b) {
    int* placeholder = new int(*a);

    *a = *b;
    *b = *placeholder;

    if (placeholder) {
        delete placeholder;
        placeholder = nullptr;
    }
   
}

//2. Count positive numbers
int* countPositives(int* arr, int* size) {
    int* count = new int(0);
    int* i = new int(0);

    for (; *i < *size; (*i)++) {
        if (*(arr + *i) > 0) {
            *count += 1;
        }
    }

    if (i) {
        delete i;
        i = nullptr;
    }

    return count;
}


//3a. Increase array size
void IncreaseSize(int* &arr, int* oldSize, int* newSize) {

    if (*newSize < *oldSize) {
        delete[] arr;
        arr = nullptr;
        return;
    }

    if (*newSize == *oldSize) {
        return;
    }

    int* newArr = new int[*newSize];

    int* i = new int(0);
    for (; *i < *oldSize; (*i)++) {
        *(newArr + *i) = *(arr + *i);
    }

    for (*i = *oldSize; *i < *newSize; (*i)++) {
        *(newArr + *i) = 0;
    }

    if (arr) {
        delete[] arr;
        arr = nullptr;
    }

    if (i) {
        delete i;
        i = nullptr;
    }

    arr = newArr;
}

//3b. Decrease array size
void DecreaseSize(int* &arr, int* oldSize, int* newSize) {
    
    if (*newSize > *oldSize) {
        delete[] arr;
        arr = nullptr;
        return;
    }

    if (*newSize == *oldSize) {
        return;
    }

    int* newArr = new int[*newSize];

    int* i = new int(0);
    for (; *i < *newSize; (*i)++) {
        *(newArr + *i) = *(arr + *i);
    }

    if (arr) {
        delete[] arr;
        arr = nullptr;
    }

    arr = newArr;
    *oldSize = *newSize;


    if (i) {
        delete i;
        i = nullptr;
    }
}




