#include <iostream>
#include <cctype>
using namespace std;

bool isValidPassword(string s, int size);

int main() {
    //Prompt the user to enter a password
    string s;
    int size;
    cout << "Enter your password: " << endl;
    cin >> s;
    cout << "Enter password size: " << endl;
    cin >> size;

    if (isValidPassword(s, size)) {
        cout << "Valid Password" << endl;
    } else {
        cout << "Invalid Password" << endl;
    }
}

//Check if a string is a valid password
bool isValidPassword(string s, int size) {
    //Only letters and digits?
    for (int i = 0; i < size; i++) {
        if (!isdigit(s[i]) && !isalpha(s[i])) {
            return false;
        }            
    }

    //Check Length
    if (size < 8) {
        return false;
    }

    //Count number of digits
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (isdigit(s[i])) {
            count++;
        }
    }

    if (count >= 2) {
        return true;
    } else {
        return false;
    }

}