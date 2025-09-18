#include <iostream>
using namespace std;

//EXERCISE: return the number of characters in the word
int Length(const char* word) {
    int count = 0;
    for (int i = 0; word[i] == '\0'; i++) {
        count++;
    }

    return count;
}

int main() {

    Length("Langara");

    return 0;
}