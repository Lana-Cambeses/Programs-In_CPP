#include <iostream>
using namespace std;

void fun(int &x, int &y) { //x and y are pass by reference
    //&x means x holds the address of the passed paramenter
    x = 100;
    y = 200;

}

int main() {

    int a = 1;
    int b = 2;

    fun(a, b);

    cout << a << ", " << b << endl;

    int x = 10;
    int y = 20;
    
    const int* const ptr = &x;

    //(*ptr)++;
    //ptr= &y;

    cout << *ptr << endl;

    //int *nums = new int[3]; //heap memory
    //nums[0] = 10;
    //nums[1] = 20;
    //nums[2] = nums[0] + nums[1];
    //for (int i = 0; i < 3 ; i++) {
        //cout << "Address: " << &nums[i] << ", Value: " << nums[i] << endl;
        //Rewrite the line above in another way without brackets huahuahua
        
        //cout << "Address: " << nums << ", Value " << *nums << endl;
        //nums++;

        //cout << "Address: " << nums + i << ", Value " << *(nums + i) << endl;

    //}
    //nums = 0x7717ac, a8 + 4

    //Question 1:
    //&nums[0] is at 100
    //Output:
    //100, 10
    //104, 20
    //108, 30

    //week 2 only pointers cpp

    //if (nums) {
    //    delete[] nums;
    //    nums = nullptr;
    //}

    return 0;
}