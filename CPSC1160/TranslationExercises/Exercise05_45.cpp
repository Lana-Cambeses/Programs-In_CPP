#include <iostream>
#include <cmath>
using namespace std;

int main() {
    const int COUNT = 10; //Total numbers
    double sum = 0; //Store the sum of the numbers
    double squareSum = 0; //Store the sum of the squares

    //Create numbers, find its sum, and its square sum
    for (int i = 0; i < COUNT; i ++) {
        //Get a new number
        double number;
        cin >> number;

        //Add the number to sum
        sum += number;

        //Add the square of the number to squareSum
        squareSum += std::pow(number, 2);
    }

    //Find mean
    double mean = sum / COUNT;

    //Find standard deviation
    double deviation = std::pow((squareSum - sum * sum / COUNT) / (COUNT - 1), 0.5);

    //Display result
    cout << "The mean is " << mean << endl;
    cout << "The standard deviation is " << deviation;
}