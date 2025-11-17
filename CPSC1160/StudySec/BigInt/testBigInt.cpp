#include <iostream>
#include "BigInt.h"

using namespace std;

int main() {
    // test all constructors of BigInt class
    BigInt num1("300");
    BigInt num2("50");
    BigInt num3(num1); // Copy constructor
    BigInt num4; // Default constructor
    BigInt num5("0"); // Default constructor with "0"
    cout << "num1: " << num1 << endl;
    cout << "num2: " << num2 << endl;
    cout << "num3 (copy of num1): " << num3 << endl;
    cout << "num4 (default constructor): " << num4 << endl;
    cout << "num5 (default constructor with '0'): " << num5 << endl;

    // test the comparison operators
    cout << "num1 == num2: " << (num1 == num2) << endl;
    cout << "num1 != num2: " << (num1 != num2) << endl;
    cout << "num1 < num2: " << (num1 < num2) << endl;
    cout << "num1 <= num2: " << (num1 <= num2) << endl;
    cout << "num1 > num2: " << (num1 > num2) << endl;
    cout << "num1 >= num2: " << (num1 >= num2) << endl;

    // test the += operator
    num1 += BigInt("5"); // Test the += operator
    cout << "num1 after +=: " << num1 << endl;
    cout << "num3 (copy of original num1): " << num3 << endl;

    // test the assignment operator
    num4 = num2; // Assignment operator
    cout << "num4 after assignment from num2: " << num4 << endl;
    // test the addition operator
    BigInt sum = num1 + num2;
    cout << "Sum of num1 and num2: " << sum << endl;
    // test the subtraction operator
    BigInt diff = num1 - num2;
    cout << "Difference of num1 and num2: " << diff << endl;
    // test the multiplication operator
    BigInt product = num1 * num2;
    cout << "Product of num1 and num2: " << product << endl;

    // test the multiplication assignment operator
    num1 *= num2;
    cout << "num1 after *= num2: " << num1 << endl;
    // test the subtraction assignment operator
    num1 -= num2;
    cout << "num1 after -= num2: " << num1 << endl;
    
    // test the prefix and postfix increment operators
    ++num1; // Prefix increment
    cout << "num1 after prefix increment: " << num1 << endl;
    num1++; // Postfix increment
    cout << "num1 after postfix increment: " << num1 << endl;
    
    return 0;
}

/*
Sample Output:
num1: 300
num2: 50
num3 (copy of num1): 300
num4 (default constructor): 0
num5 (default constructor with '0'): 0
num1 == num2: 0
num1 != num2: 1
num1 < num2: 0
num1 <= num2: 0
num1 > num2: 1
num1 >= num2: 1
num1 after +=: 305
num3 (copy of original num1): 300
num4 after assignment from num2: 50
Sum of num1 and num2: 355
Difference of num1 and num2: 255
Product of num1 and num2: 15250
num1 after *= num2: 15250
num1 after -= num2: 15200
num1 after prefix increment: 15201
num1 after postfix increment: 15202
*/