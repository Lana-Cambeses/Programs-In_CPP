#ifndef BIGINT_H
#define BIGINT_H

#include <iostream>
using namespace std;
int CalculateLength(const char* str) {
    // does not count the null terminator
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}
void CopyCharArray(const char* source, char* destination, int length) {
    for (int i = 0; i < length; ++i) {
        destination[i] = source[i];
    }
    destination[length] = '\0'; // Null-terminate the string, ensuring it is a valid C-style string (easy to print!)
}
int CompareStrings(const char* str1, const char* str2) {
    // Compare two strings lexicographically
    // Note: This function assumes that both strings are null-terminated
    while (*str1 && *str2) {
        if (*str1 != *str2) {
            return *str1 - *str2; // Return the difference of the first non-matching characters
        }
        str1++;
        str2++;
    }
    if(*str1 == '\0' && *str2 == '\0') {
        return 0; // Both strings are equal
    }
    else if (*str1 == '\0') {
        return -(*str2); // str1 is shorter than str2
    }
    else {
        return *str1; // str1 is longer than str2
    }
}

int CharToInt(char c) {
    return c - '0'; // Convert character digit to integer
}

char IntToChar(int num) {
    return num + '0'; // Convert integer digit to character
}

class BigInt {
    friend ostream& operator<<(ostream& os, const BigInt& b);
private:
    char* digits;
    int size;

public:
    BigInt(const char* num = "0") { // this is both a default (if no parameter is given then num is "0") and a defined constructor!!!
        size = CalculateLength(num); // null terminator is not counted in size
        digits = new char[size + 1];
        CopyCharArray(num, digits, size);
        digits[size] = '\0'; // Ensure null-termination       
    }

    BigInt(const BigInt& other) {
        size = other.size;
        digits = new char[size + 1];
        CopyCharArray(other.digits, digits, size);
        digits[size] = '\0'; // Ensure null-termination        
    }

    ~BigInt() {
        delete[] digits; // minimum size is 1, so no need to check for null
    }

    // overload the assignment operator
    // gandle self-assignment and deep copy
    // This will handle assignment of one BigInt to another, deep copy
    // It will return a reference to the current object to allow for chained assignments
    BigInt& operator=(const BigInt& other) {
        
    }

    // overload the == operator to compare two BigInt objects
    // two BigInt objects are equal if they have the same size and their digits are the same
    // It will return true if they are equal, false otherwise
    // Note: This implementation assumes that the BigInt numbers are non-negative and do not have leading zeros
    bool operator==(const BigInt& other) const {
        
    }
    // overload the != operator to compare two BigInt objects
    bool operator!=(const BigInt& other) const {
        
    }
    // overload the < operator to compare two BigInt objects
    // two BigInt objects are less than each other if they have fewer digits or if they have the same number of digits but the first different digit is smaller
    // It will return true if this BigInt is less than the other, false otherwise
    // Note: This implementation assumes that the BigInt numbers are non-negative and do not have leading zeros
    bool operator<(const BigInt& other) const {
        
    }
    // overload the >= operator to compare two BigInt objects
    bool operator>=(const BigInt& other) const {
        
    }
    // overload the > operator to compare two BigInt objects
    // two BigInt objects are greater than each other if they have more digits or if they have the same number of digits but the first different digit is greater
    // It will return true if this BigInt is greater than the other, false otherwise
    // Note: This implementation assumes that the BigInt numbers are non-negative and do not have leading zeros
    bool operator>(const BigInt& other) const {
        
    }
    // overload the <= operator to compare two BigInt objects
    bool operator<=(const BigInt& other) const {
        
    }

    // overload the + operator to add two BigInt objects
    // This will handle addition of two BigInt numbers, including carry handling
    // The result will be a new BigInt object
    // Note: This implementation assumes that the BigInt numbers are non-negative and do not have leading zeros
    BigInt operator+(const BigInt& other) const {
    }

    // overload the += operator to add another BigInt to this one
    // This will modify the current BigInt object by adding another BigInt to it
    void operator+=(const BigInt& other) {
        *this = *this + other; // Use the + operator to perform the addition
    }

    // overload the - operator to subtract another BigInt from this one
    // This will handle subtraction of two BigInt numbers, including borrow handling
    // The result will be a new BigInt object
    // Note: This implementation assumes that the BigInt numbers are non-negative and do not have leading zeros
    // Also, it assumes that the first BigInt is greater than or equal to the second BigInt
    BigInt operator-(const BigInt& other) const {
    }

    // overload the -= operator to subtract another BigInt from this one
    // This will modify the current BigInt object by subtracting another BigInt from it
    void operator-=(const BigInt& other) {
        *this = *this - other; // Use the - operator to perform the subtraction
    }

    // overload the prefix ++ operator to increment this BigInt by 1
    // This will modify the current BigInt object by adding 1 to it
    BigInt& operator++() {
        *this += BigInt("1"); // Use the += operator to perform the increment
        return *this; // Return the modified object
    }
    // overload the postfix ++ operator to increment this BigInt by 1
    // This will modify the current BigInt object by adding 1 to it
    BigInt operator++(int) {
        BigInt temp(*this); // Create a copy of the current object
        ++(*this); // Use the prefix increment operator to modify the current object
        return temp; // Return the copy (the value before increment)
    }

    // overload the * operator to multiply two BigInt objects
    // This will handle multiplication of two BigInt numbers
    // The result will be a new BigInt object
    BigInt operator*(const BigInt& other) const {
        
    }

    // overload the *= operator to multiply another BigInt with this one
    // This will modify the current BigInt object by multiplying it with another BigInt
    void operator*=(const BigInt& other) {
        *this = *this * other; // Use the * operator to perform the multiplication
    }

};

ostream& operator<<(ostream& os, const BigInt& b) {
    os << b.digits;
    return os;
}

#endif