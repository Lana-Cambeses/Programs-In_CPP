//Name: Lana Cambeses
//Student ID: 100411765
//Title: CPSC 1160 - Week 4 Homework
//Date: September 25, 2025

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {

    //Part B: Code Fixing 1
    int rows = 3, cols = 4;
    int **arr = new int*[rows];

    for(int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }

    for(int i=0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            arr[i][j] = i + j;
        }
    }

    if (arr) {
        for (int i = 0; i < rows; i++) {
            delete[] arr[i];
        }

        delete[] arr;
        arr = nullptr;
    }


    //Part B: Code Fixing 2
    int x = 2, y = 3, z = 4;
    int ***arr2;
    arr2 = new int**[x];

    for(int i = 0; i < x; i++){
        arr2[i] = new int*[y]; 
        for(int j = 0; j < y; j++){
            arr2[i][j] = new int[z];
        }
    }
    
    if (arr2) {
        for(int i = 0; i < x; i++){
            for(int j = 0; j < y; j++){
                delete[] arr2[i][j];
            }
            delete[] arr2[i];
        }

        delete[] arr2;
        arr2 = nullptr;
    }

    //Part C: Code Writing
    srand(time(0));
    int n;
    cout << "Insert number of Employees:";
    cin >> n;

    int c = 7;

    //Build 2d array
    int **arr2d = new int*[n];
    for(int i = 0; i < n; i++) {
        arr2d[i] = new int[c];
    }

    int* hourCount = new int[n];

    //Populate 2d array
    for(int i = 0; i < n; i++){
        for(int j = 0; j < c; j++){
            arr2d[i][j] = (rand() % 9) + 1;
        }
    }

    //Print array
    for(int i = 0; i < n; i++){
        for(int j = 0; j < c; j++){
            cout << arr2d[i][j] << " ";
        }
        cout << endl;
        
    }

    //Print results
    int count;
    for(int i = 0; i < n; i++){
        count = 0;
        for(int j = 0; j < c; j++){
            count += arr2d[i][j];
        }
        cout << endl;
        cout << "Employee " << i << " worked " << count << " hours!";
        hourCount[i] = count;
    }

    //Min and Max:
    int maxHours = hourCount[0];
    int minHours = hourCount[0];
    int maxEmp = 0, minEmp = 0;

    for (int i = 1; i < n; i++) {
        if (hourCount[i] > maxHours) {
            maxHours = hourCount[i];
            maxEmp = i;
        }
        if (hourCount[i] < minHours) {
            minHours = hourCount[i];
            minEmp = i;
        }
    }

    cout << endl;
    cout << "Employee " << maxEmp << " worked more: " << maxHours << endl;
    cout << "Employee " << minEmp << " worked less: " << minHours << endl;

    //Deallocation
    if (arr2d) {
        for (int i = 0; i < n; i++) {
            delete[] arr2d[i];
        }

        delete[] arr2d;
        arr2d = nullptr;
    }

    if (hourCount) {
        delete[] hourCount;
        hourCount = nullptr;
    }

    return 0;
}

