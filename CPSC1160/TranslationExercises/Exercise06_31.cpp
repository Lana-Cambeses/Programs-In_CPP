#include <iostream>
using namespace std;

//
bool isValid(long long number);
int sumOfDoubleEvenPlace(long long number);
int getDigit(int number);
int sumOfOddPlace(long long number);
int getSize(long long d);
long long getPrefix(long long number, int k);
bool prefixMatched(long long number, int d);

long long getPrefix(long long number, int k);

int main() {

    cout << "Enter a credit card number as a long long integer: " << endl;
    long long number;
    cin >> number;

    if (isValid(number)) {
        cout << number << " is valid";
    } else {
        cout << number << "is not valid";
    }

    return 0;
}

/** Return true if the card number is valid */
bool isValid(long long number) {
    return (getSize(number) >= 13) && (getSize(number) <= 16) && 
    (prefixMatched(number, 4) || prefixMatched(number, 5) ||
    prefixMatched(number, 6) || prefixMatched(number, 37)) && 
    (sumOfDoubleEvenPlace(number) + sumOfOddPlace(number)) % 10 == 0;
}

int sumOfDoubleEvenPlace(long long number) {
int result = 0;

number = number / 10; // Starting from the second digit from left
while (number != 0) {
    result += getDigit((int)((number % 10) * 2));
    number = number / 100; // Move to the next even place
}

return result;
}

/** Return this number if it is a single digit, otherwise, return 
 * the sum of the two digits */
int getDigit(int number) {
return number % 10 + (number / 10);
}

/** Return sum of odd place digits in number */
int sumOfOddPlace(long long number) {
int result = 0;

while (number != 0) {
    result += (int)(number % 10);
    number = number / 100; // Move two positions to the left
}

return result;
}

/** Return true if the digit d is a prefix for number */
bool prefixMatched(long long number, int d) {
return getPrefix(number, getSize(d)) == d;
}

/** Return the number of digits in d */
int getSize(long long d) {
int numberOfDigits = 0;

while (d != 0) {
    numberOfDigits++;
    d = d / 10;
}

return numberOfDigits;
}

/** Return the first k number of digits from number. If the number
 * of digits in number is less than k, return number. */
long long getPrefix(long long number, int k) {
long long result = number;

for (int i = 0; i < getSize(number) - k; i++)
    result /= 10;

return result;
}