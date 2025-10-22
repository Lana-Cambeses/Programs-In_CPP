#include <iostream>
using namespace std;


int countEvens(int* arr, int size) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] % 2 == 0)
            ++count;
    }
    return count;
}

int countEvens(int* arr, int size, int count) {
    if (size == 0) {
        return count;
    }

    if (arr[size - 1] % 2 == 0)
            count += 1;

    return countEvens(arr, size - 1, count);
}

int findMax(int* arr, int size) {
    int maxVal = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }
    return maxVal;
}

int findMax(int* arr, int size, int maxVal) {
    if (size <= 0) {
        return maxVal;
    } 

    if (arr[size - 1] > maxVal) {
        maxVal = arr[size - 1];
    }

    return findMax(arr, size - 1, maxVal);
}

int countDigits(int n) {
    int count = 0;
    while (n > 0) {
        count++;
        n /= 10; // remove the last digit
    }
    return count;
}

int countDigits(int n, int count) {
    if (n <= 0) {
        return count;
    }

    count += 1;
    
    return countDigits(n / 10, count);
}

int countDigits(int n) {
    if (n < 10) {
        return 1;
    }
    
    return 1 + countDigits(n / 10);
}

int rowHasNeg(int* row, int c, int j, bool found) {
    if (j == c) {
        return found;
    }

    if (row[j] < 0) found = true;

    return rowHasNeg(row, c, j + 1, found);

}

bool countRowsWithNegRec(int** arr, int r, int c, int i, int count) {
    if (i == r) {
        return count;
    }

    bool hasNeg = rowHasNeg(arr[i], c, 0, false);
    if (hasNeg) ++count;

    return countRowsWithNegRec(arr, r, c, i + 1, count);
    
}


int main() {

    return 0;
}