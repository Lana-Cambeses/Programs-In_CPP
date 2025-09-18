#include <iostream>
using namespace std;

int Sum(int* arr, int size){
    int s = 0;
    for(int i = 0; i < size; i++){
        s += arr[i];
    }
    return s;
}

int* Sum2(int* arr, int *size){
    int *s = new int;
    *s = 0;

    int* i = new int;
    
    
    for(*i = 0; (*i) < (*size); (*   i)++){
        (*s) += arr[*i];
    }

    if(i != nullptr){
        delete i;
        i = nullptr;
    }

    return s;
    
}

int main(){
    int a[] = {10, 20, 30};
    int* s = new int(3);
    int *result = Sum2(a, s);
    
    cout << *result;
    if(result != nullptr){
        delete result;
        result = nullptr;
    }
    if(s != nullptr){
        delete s;
        s = nullptr;
    }
    return 0;
}