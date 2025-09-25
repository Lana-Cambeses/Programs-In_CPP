#include <iostream>
using namespace std;

int Length(const char* word) {
    //EXERCISE: return the number of characters in the word
    int count = 0;
    for (int i = 0; word[i] == '\0'; i++) {
        count++;
    }

    return count;
}

bool LuckyArray(int* arr, int len) {
    //EXERCISE: Lucky Array 

}

int main() {

    Length("Langara");

    return 0;
}