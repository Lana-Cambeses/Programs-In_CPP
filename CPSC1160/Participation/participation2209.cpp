#include <iostream>
using namespace std;

int main() {

} 

int countOdd(int** arr, int rows, int cols) {
    //return the number of odd valus in arr

    int count = 0;

    for(int i = 0; i < cols; i++) { //row loop
        for (int j = 0; j < rows; j++) { //column loop
            if (arr[i][j] % 2) { //arr[i][j] % 2 != 0 
                count++;
            }
        }
    }
}

int countOdd2(int*** book, int pages, int lines, int words) {
    //return the number of odd valus in arr

    int count = 0;

    for (int c = 0; c < pages; c++) {
        for(int i = 0; i < lines; i++) { //row loop
            for (int j = 0; j < words; j++) { //column loop
                if (book[c][i][j] % 2) { //arr[i][j] % 2 != 0 
                    count++;
                }
            }
        }
    }
}

int fun(string s, int i) { //suppose s = "abcde", i = 0
    
    
    if (i == s.length()) { //base case
        return 1;
    } else {
        return fun(s, i + 1); //recursive case
    }
}