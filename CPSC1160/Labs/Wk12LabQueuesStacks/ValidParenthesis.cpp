#include <iostream>
using namespace std;

char stack[1000]; // all tests will use at most 1000 characters
int top = -1; // index of top-most item, -1 means stack is empty, non-negative means stack has elements. for example, top = 0 means stack has one element at index 0. top = 1 means stack has two elements at indices 0 and 1, etc.

bool isValid(string s) {
    // MUST use a stack to check for valid parentheses
    // MUST use global stack variable
    // MUST use global top variable to track the top of the stack
    // length of s is going to be at most 1000 characters

    if(s.length() == 0) {
        return true; // An empty string is considered valid
    }
    top = -1; // Reset stack for each call, i.e. start with an empty stack
    
    // COMPLETE THE CODE    
    if(s.length() % 2 != 0) {
        return false;
    }

    if(s[0] == ')' || s[0] == '}' || s[0] == ']' ) {
        return false;

    } else {
        for (int i = 0; i < s.length(); i++) {
            if (!(s[i] == ')' || s[i] == '}' || s[i] == ']')) {
                top++;
                stack[top] = s[i];
            } else {
                char val = stack[top];
                top--;
                if ((val == '(' && s[i] != ')')) {
                    return false;
                } else if ((val == '[' && s[i] != ']')) {
                    return false;
                } else if ((val == '{' && s[i] != '}')) {
                    return false;
                }
                
            }
        }
        return true;
    }

    
}

int main() {
    string s = "()[]{}";
    cout << (isValid(s) ? "Valid" : "Invalid") << endl;

    s = "([)]";
    cout << (isValid(s) ? "Valid" : "Invalid") << endl;

    s = "{[]}";
    cout << (isValid(s) ? "Valid" : "Invalid") << endl;

    s = "((()))";
    cout << (isValid(s) ? "Valid" : "Invalid") << endl;

    s = "((())";
    cout << (isValid(s) ? "Valid" : "Invalid") << endl;

    s = "([{}])";
    cout << (isValid(s) ? "Valid" : "Invalid") << endl;

    s = "([)]{}";
    cout << (isValid(s) ? "Valid" : "Invalid") << endl;

    s = "([{}])()";
    cout << (isValid(s) ? "Valid" : "Invalid") << endl;

    s = "([{}])(({}))";
    cout << (isValid(s) ? "Valid" : "Invalid") << endl;

    s = "([{}])(({})";
    cout << (isValid(s) ? "Valid" : "Invalid") << endl;

    s = "";
    cout << (isValid(s) ? "Valid" : "Invalid") << endl;

    s = "[";
    cout << (isValid(s) ? "Valid" : "Invalid") << endl; 
    return 0;
}

/*
sample output:
Valid
Invalid
Valid
Valid
Invalid
Valid
Invalid
Valid
Valid
Invalid
Valid
Invalid
*/
