//Name: Lana Cambeses
//Student ID: 100411765
//Title: CPSC 1160 - Week 5 Homework
//Date: October 7, 2025

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Function signatures:
void callSwap(int *list, int arraySize, bool &needNextPass, int i);
void bubbleSort(int *list, int arraySize);
bool IsSorted(int* arr, int len, int i);
bool IsSortedHelper(int* arr, int len);
int rowSum(int* r, int c, int j);
bool HasMostlyEvenRows(int** arr, int r, int c, int i, int countAbove);
bool HasMostlyEvenRows(int** arr, int r, int c);

int main() {

    //Question 1 testing:
    int n = 7;
    int* a = new int[n]{5, 1, 4, 2, 8, 0, 2};

    cout << "Before: ";
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << endl;
    bubbleSort(a, n);
    cout << "After:  ";
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << endl;

    delete[] a;

    //Question 3 testing:
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {5, 3, 4, 1};

    cout << (IsSortedHelper(arr1, 5) ? "Sorted\n" : "Not sorted\n");
    cout << (IsSortedHelper(arr2, 4) ? "Sorted\n" : "Not sorted\n");


    //Question 4 testing:
    int c = 5;
    int row[] = {2, 4, 6, 8, 10};

    cout << "Sum of row = " << rowSum(row, c, 0) << endl;
    return 0;
    

    return 0;
}


/* QUESTION 1: Recursive Bubble Sort Function
    Step 1 (Smaller problem): The smaller problem in this case is to sort a smaller lists than before
    Step 2 (Use solution of step 1 to solve the bigger problem): I used the smaller sorted list to sort the bigger one
    Step 3 (Find base cases): the base case will be if the list has only one element or less, cause that means its already sorted
    Step 4 (Put steps into right order): The order will be setting the flag to false, then loop internally doing the swaps, to just 
        then stop if no more iterations are necessary; but if they are, we do the recursive call to keep the passes.
*/
void callSwap(int *list, int arraySize, bool &needNextPass, int i) {

    if (i >= arraySize - 1) {
        return;
    }

    if (list[i] > list[i + 1]) {
        // Swap list[i] with list[i + 1]
        int temp = list[i];
        list[i] = list[i + 1];
        list[i + 1] = temp;
        needNextPass = true; // Next pass still needed
    }

    callSwap(list, arraySize, needNextPass, i + 1);

}

void bubbleSort(int *list, int arraySize) {

    if (arraySize <= 1) {
        return;
    }

    bool needNextPass = false;

    callSwap(list, arraySize, needNextPass, 0);

    if (!needNextPass) return;
    
    bubbleSort(list, arraySize - 1);
}


/* QUESTION 3: IsSorted Function
    Step 1 (Smaller problem): The smaller problem in this case is to check if a smaller portion of the array is already sorted
    Step 2 (Use solution of step 1 to solve the bigger problem): Once confirmed that the smaller portion is sorted, check the remaining elements
    Step 3 (Find base cases): the base case will be if the list has only one element or less, cause that means its already sorted
    Step 4 (Put steps into right order): Check base case, check if array has an element thats greater than the next and then do the recursive call
*/
bool IsSorted(int* arr, int len, int i) {
    if (i >= len - 1) {
        return true;
    }

    if (arr[i] > arr[i + 1])
        return false;

    return IsSorted(arr, len, i + 1);
}

bool IsSortedHelper(int* arr, int len) {
    return IsSorted(arr, len, 0);
}

/* QUESTION 4: HasMostlyEvenRows Function
    Step 1 (Smaller problem): The smaller problem in this case is to check if the sum of an smaller amount of rows is even
    Step 2 (Use solution of step 1 to solve the bigger problem): Once thats settled, we can check if the row that we held back is even as well. If it is, we add it to the count
    Step 3 (Find base cases): the base case will be if the iteration index is the same as the amount of rows processed
    Step 4 (Put steps into right order): Check the base case, sum each column, see if the sum is even and then do the recursive call
*/

int rowSum(int* r, int c, int j) {
    if (j >= c) return 0;
    return r[j] + rowSum(r, c, j + 1); 
}

bool HasMostlyEvenRows(int** arr, int r, int c, int i, int countAbove) {
    if (i >= r) {
        return countAbove > r / 2;
    }

    int rowCount = 0;

    int sum = rowSum(arr[i], c, 0);
    if (sum % 2 == 0) {
        countAbove += 1;
    }

    return HasMostlyEvenRows(arr, r, c, i + 1, countAbove);

}

bool HasMostlyEvenRows(int** arr, int r, int c) {
    return HasMostlyEvenRows(arr, r, c, 0, 0);
}

