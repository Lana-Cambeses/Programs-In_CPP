#include <iostream>
#include <cmath>
using namespace std;

double deviation(double* x, int size);
double deviation(int* x, int size);
double mean(double* x, int size);
double mean(int* x, int size);
void printArray(double* x, int size);

int main() {

    int numSize = 10;
    double* numbers = new double[numSize];

    cout << "Enter ten numbers: ";

    for (int i = 0; i < numSize; i++) {
        cin >> numbers[i];
    }

    //Display mean and deviation
    cout << "The mean is " << mean(numbers, numSize) << endl;
    cout << "The standard deviation is " << deviation(numbers, numSize);

    return 0;
}

double deviation(double* x, int size) {
    double m = mean(x, size);
    double squareSum = 0;

    for (int i = 0; i < size; i++) {
      squareSum += pow(x[i] - m, 2);
    }

    return sqrt(squareSum / (size - 1));
}

  /** Method for computing deviation of int values*/
  double deviation(int* x, int size) {
    double m = mean(x, size);
    double squareSum = 0;

    for (int i = 0; i < size; i++) {
      squareSum += pow(x[i] - m, 2);
    }

    return sqrt(squareSum / (size - 1));
  }

  /** Method for computing mean of an array of double values*/
  double mean(double* x, int size) {
    double sum = 0;

    for (int i = 0; i < size; i++)
      sum += x[i];

    return sum / size;
  }

  /** Method for computing mean of an array of int values*/
  double mean(int* x, int size) {
    int sum = 0;

    for (int i = 0; i < size; i++)
      sum += x[i];

    return sum / size;
  }

  /** Method for printing array */
  void printArray(double* x, int size) {
    for (int i = 0; i < size; i++)
      cout << x[i] << " ";
    cout << endl;
  }