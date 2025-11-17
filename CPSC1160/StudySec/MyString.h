#ifndef MYSTRING_H
#define MYSTRING_H

/*
The BIG 3 (rule of 3 in textbook):
anytime a class has a pointer and dynamic memory has been allocated to that pointer within the class, that class MUST have the following 3:
1. copy constructor (deep copy)
2. destructor
3. assignment operator overload
*/

#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
class MyString {
private:
    char* str; // Pointer to hold the characters in the string, null-terminated
    int length; // Length of the string

    // Helper function to calculate the length of the string
    int CalculateLength(const char* s){
        // return the number of characters in the s without counting the null terminator
        int len = 0;
        while(s[len] != '\0' ){
            len++;
        }
        return len;
    }

    // Helper function to clear the allocated memory
    void ClearMemory() {
        // clears memory, deallocates everything, resets everything to 0
        if(str){
            delete[] str;
        }
        str = nullptr;
        length = 0;
    }
public:
    // Default constructor
    // MyString() : str(nullptr), length(0) {}
    MyString() {
        str = nullptr;
        length = 0; 
    }

    // Parameterized constructor
    MyString(const char* s) {
        str = nullptr;
        length = CalculateLength(s);
        if(length != 0){
            str = new char[length];
            for(int i = 0; i < length; i++){
                str[i] = s[i];
            }
        }
    }

    // Copy constructor: performs deep copy
    MyString(const MyString& other) {

        this->str = nullptr;
        this->length = other.length;
        if(this->length != 0){
            this->str = new char[this->length];
            for(int i = 0; i < this->length; i++){
                this->str[i] = other.str[i];
            }

        }        
    }

    // Destructor: releases the allocated memory
    ~MyString() {
        // display();
        // cout << "DESTROYED\n";
        ClearMemory();        
    }

    // getters/setters
    // Function to get the length of the string
    int getLength() const {
        return length;
    }  
    
    // dangerous to allow outside world direct access to str
    const char* const getStr() const{
        return str;
    }
    
    // // we do not want outside world to get the string directly (because they may make it invalid), so we do not provide a getter for str
    // // but we can provide outside world a way to get a specific character at a given index
    // // Function to get a character at a specific index
    char getCharAt(int index) const {
        if (index < 0 || index >= length) {
            cout << "Index out of range. Returning null character." << endl;
            return '\0'; // Return null character if index is out of range
        }
        return str[index];
    } 

    // similarly, we do not want outside world to set the string directly (they should use a constructor), so we do not provide a setter for str
    // but we can provide outside world a way to set a specific character at a given index
    // Function to set a character at a specific index
    void setCharAt(int index, char c) {
        if (index < 0 || index >= length) {
            cout << "Index out of range. Cannot set character." << endl;
            return; // Do nothing if index is out of range
        }
        str[index] = c; // Set the character at the specified index
    }

    // // we also do not want outside world to set the length directly, so we do not provide a setter for length

    // Function to display the string
    void display() const {
        if (str) {
            cout << "length: " << length << endl;
            cout << "the string: ";
            for(int i = 0; i < length; i++){
                cout << str[i];
            }
            cout << endl;
        } else {
            cout << "Empty String" << endl;
        }
    }


    bool IsEmpty() const{
        return length == 0;
    }
    
    // Function to concatenate another MyString object to this one
    void concatenate(const MyString& other) {
        if (other.str) {// check to see other has something
            int totalLength = this->length + other.length;
            // make room for all characters after concatenation
            char* newStr = new char[totalLength];

            for(int i = 0; i < this->length; i++){
                newStr[i] = this->str[i];
            }

            for(int i = this->length, j = 0; i < totalLength; i++, j++){
                newStr[i] = other.str[j];
            }

            ClearMemory();

            this->str = newStr;

            this->length = totalLength;

        

            // set this object's str to newStr
            // set this object's length to this->length + other.length

            
        }
    }


    MyString& operator=(const MyString &source){
        // clear all existing data in this object first
        ClearMemory();
        // deep copy info from source into this
        this->str = nullptr;
        this->length = source.length;
        if(this->length != 0){
            this->str = new char[this->length];
            for(int i = 0; i < this->length; i++){
                this->str[i] = source.str[i];
            }
        }
        return *this;
    }

    // overload all operators that apply to this class
    // operator + to concatenate two MyString objects
    MyString operator+(const MyString &other) const {
        MyString result; // Create a new MyString object to hold the result
        result.length = this->length + other.length; // Set the length of the result
        if (result.length > 0) {
            result.str = new char[result.length]; // Allocate memory for the result string
            for (int i = 0; i < this->length; i++) {
                result.str[i] = this->str[i]; // Copy characters from this object
            }
            for (int i = this->length, j = 0; i < result.length; i++, j++) {
                result.str[i] = other.str[j]; // Copy characters from the other object
            }
        }
        return result; // Return the new MyString object containing the concatenated string
    }

    // operator += to concatenate another MyString object to this one
    MyString& operator+=(const MyString &other) {
        if (other.str) { // Check if the other MyString has characters
            int totalLength = this->length + other.length; // Calculate the new length
            char* newStr = new char[totalLength]; // Allocate memory for the new string

            for (int i = 0; i < this->length; i++) {
                newStr[i] = this->str[i]; // Copy characters from this object
            }

            for (int i = this->length, j = 0; i < totalLength; i++, j++) {
                newStr[i] = other.str[j]; // Copy characters from the other object
            }

            ClearMemory(); // Clear existing memory in this object

            this->str = newStr; // Set this object's str to newStr
            this->length = totalLength; // Update the length of this object
        }
        return *this; // Return the current object to allow chaining
    }

    // operator == to compare two MyString objects for equality
    bool operator==(const MyString &other) const {
        if (this->length != other.length) {
            return false; // If lengths are different, they are not equal
        }
        for (int i = 0; i < this->length; i++) {
            if (this->str[i] != other.str[i]) {
                return false; // If any character is different, they are not equal
            }
        }
        return true; // All characters are equal, so the strings are equal
    }

    // operator != to compare two MyString objects for inequality
    bool operator!=(const MyString &other) const {
        return !(*this == other); // Use the equality operator to determine inequality
    }

    // operator < to compare two MyString objects for less than
    bool operator<(const MyString &other) const {
        int shorter = min(this->length, other.length);
        for (int i = 0; i < shorter; i++) {
            if (this->str[i] < other.str[i]) {
                return true; // This string is less than the other string
            } else if (this->str[i] > other.str[i]) {
                return false; // This string is greater than the other string
            }
        }
        return this->length < other.length; // If all characters are equal, compare lengths
    }

    // operator > to compare two MyString objects for greater than
    bool operator>(const MyString &other) const {
        int shorter = min(this->length, other.length);
        for (int i = 0; i < shorter; i++) {
            if (this->str[i] > other.str[i]) {
                return true; // This string is greater than the other string
            } else if (this->str[i] < other.str[i]) {
                return false; // This string is less than the other string
            }
        }
        return this->length > other.length; // If all characters are equal, compare lengths
    }

    // operator <= to compare two MyString objects for less than or equal to
    bool operator<=(const MyString &other) const {
        return *this < other || *this == other; // Use the less than and equality operators to determine less than or equal to
    }

    // operator >= to compare two MyString objects for greater than or equal to
    bool operator>=(const MyString &other) const {
        return *this > other || *this == other; // Use the greater than and equality operators to determine greater than or equal to
    }

    // // operator [] to access a character at a specific index
    // char& operator[](int index) {
    //     if (index < 0 || index >= length) {
    //         cout << "Index out of range. Returning null character." << endl;
    //         return *new char('\0'); // Return a reference to a null character if index is out of range
    //     }
    //     return str[index]; // Return a reference to the character at the specified index
    // }

    // operator [] to access a character at a specific index
    char operator[](int index) {
        if (index < 0 || index >= length) {
            cout << "Index out of range. Returning null character." << endl;
            return '\0'; // Return a reference to a null character if index is out of range
        }
        return str[index]; // Return a reference to the character at the specified index
    }

    // operator prefix ++
    // every character in the object is incremented by 1
    MyString operator++(){
        for(int i = 0; i < length; i++){
            str[i]++;
        }

        return *this;
    }

    // operator postfix ++
    // every character in the object is incremented by 1
    MyString operator++(int dummy){
        MyString old(*this);
        for(int i = 0; i < length; i++){
            str[i]++;
        }

        return old;
        
    }

    bool operator!(){
        return !IsEmpty();
    }

    // // Function to insert a character at a specific index
    // void insertCharAt(int index, char c) {
    //     if (index < 0 || index > length) {
    //         cout << "Index out of range. Cannot insert character." << endl;
    //         return; // Do nothing if index is out of range
    //     }
        
    // }

    // return comparison result as follows:
    // -1 if this < other (alphabetically)
    // 0 if this == other (alphabetically)
    // 1 if this > other (alphabetically)
    // example: 
    // this = "abc", other = "abc" => return 0
    // this = "abc", other = "abd" => return -1 because 'c' < 'd'
    // this = "abc", other = "abb" => return 1 because 'c' > 'b'
    // this = "abc", other = "abcd" => return -1 because "abc" is shorter than "abcd", notice that both strings are equal until the end of "abc"
    // this = "abc", other = "ab" => return 1 because "abc" is longer than "ab", notice that both strings are equal until the end of "ab"
    int compareTo(const MyString& other) const {
        int shorter = min(this->length, other.length);
        for(int i = 0; i < shorter; i++){
            if(this->str[i] < other.str[i]){
                return -1;
            }
            else if (this->str[i] > other.str[i]){
                return 1;
            }
        }

        if(this->length == other.length){
            return 0;
        }
        else{
            if(this->length < other.length){
                return -1;
            }
            else{
                return 1;
            }
        }
        
    }

    // MyString subString(int start, int end) const {
    //     if (start < 0 || end >= length || start > end) {
    //         cout << "Invalid range. Returning empty string." << endl;
    //         return MyString(); // Return an empty MyString object if the range is invalid
    //     }
        
    //     // Create a new MyString object to hold the substring
    //     MyString subStr;
    //     // Allocate memory for the substring and copy the characters from str
    //     // Set the length of the substring
    //     return subStr; // Return the new MyString object containing the substring
    // }

    // int indexOf(char c) const {
    //     // returns index of the first occurrence of character c in the string, or -1 if not found


    //     return -1; // Return -1 if character c is not found in the string
    // }

    // int indexOf(const MyString &s){
    //     // returns index of the first occurrence of MyString s in the string, or -1 if not found
    //     // example: 
    //     // this = "abcde", s = "cd" => return 2
    //     // this = "abcde", s = "xyz" => return -1
    //     // this = "abcde", s = "abcde" => return 0
    //     // this = "abcde", s = "a" => return 0
    //     // this = "abcde", s = "e" => return 4
    //     // this = "abcde", s = "" => return 0 (empty string is found at index 0)
        
    //     return -1; // Return -1 if MyString s is not found in the string
    // }

    // int replace(char oldChar, char newChar) {
    //     // replaces all occurrences of oldChar with newChar in the string
    //     // returns the number of replacements made
    //     int count = 0;
        
    //     return count; // Return the number of replacements made
    // }

    // void splits(const char delimiter, MyString* splits, int &splitCount) const {
    //     // splits the string into substrings based on the delimiter
    //     // stores the substrings in the splits array and updates splitCount with the number of splits
    //     // example:
    //     // this = "abc,def,ghi", delimiter = ',' => splits[0] = "abc", splits[1] = "def", splits[2] = "ghi", splitCount = 3
    //     // this = "abc:def:ghi", delimiter = ',' => splits[0] = "abc:def:ghi", splitCount = 1

        
        
    //     return
    // }

    friend ostream& operator<<(ostream &out, const MyString &obj);

    friend istream& operator>>(istream &in, MyString &obj);
    
};

ostream& operator<<(ostream &out, const MyString &obj){

    if (!obj.IsEmpty()) {
        out << "length: " << obj.length << endl;
        out << "the string: ";
        for(int i = 0; i < obj.length; i++){
            out << obj.str[i];
        }
        out << endl;
    } else {
        out << "Empty String" << endl;
    }

    return out;
}

istream& operator>>(istream &in, MyString &obj){

    string s;
    cout << "enter a string: ";
    getline(in, s);

    obj.ClearMemory();
    obj.length = s.length();
    obj.str = new char[obj.length];
    for(int i = 0; i < obj.length; i++){
        obj.str[i] = s[i];
    }

    return in;
}
#endif