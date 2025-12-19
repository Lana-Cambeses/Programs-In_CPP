#include <iostream>
using namespace std;

/* class MyClass {
public:
    // 1) Overload operator new
    void* operator new(std::size_t size) {
        std::cout << "Allocating " << size << " bytes\n";
        return std::malloc(size);
    }

    // 2) Must also overload delete if you overload new
    void operator delete(void* ptr) {
        std::cout << "Freeing memory\n";
        std::free(ptr);
    }
}; */

void printDown(int n) {
    for (int i = n; i >= 1; i--) {
        cout << i << " ";
    }
}

void printDown(int n) {
    if (n < 1) {
        return;
    }
    cout << n << " ";
    printDown (n - 1);
}

int sum(int arr[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    return total;
}

int sum(int arr[], int n, int sumof) {
    if (n == 0) {
        return sumof;
    }
    sumof += arr[n - 1];
    return sum(arr, n - 1, sumof);
}
int sumHelper(int arr[], int n) {
    return sum(arr, n, 0);
}

int sum(int arr[], int n) {
    if (n == 0) return 0;
    return arr[n-1] + sum(arr, n-1);
}

void printMatrix(int rows, int cols) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            cout << "(" << r << "," << c << ") ";
        }
        cout << endl;
    }
}

void printMatrix(int rows, int cols) {
    printMatrix(rows, cols, 0);
}

void printMatrix(int rows, int cols, int r) {
    if (r == rows) {
        return;
    }
    
    printMatrixInner(cols, 0, r);
    printMatrix(rows, cols, r + 1);
}

void printMatrixInner(int cols, int c, int r) {
    if (c == cols) {
        return;
    }
    cout << "(" << r << "," << c << ") ";
    printMatrixInner(cols, c + 1, r);
}