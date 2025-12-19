#include <iostream>
#include "StackWithLinkedList.h"
using namespace std;

void Display(Stack s){
    while(!s.IsEmpty()){
        int item = s.Pop();
        cout << "item popped " << item << ", items left in the stack " << s.GetSize() << endl;
    }
}
int main() {

    Stack s;
    for(int i = 1; i <= 10; i++){
        s.Push(i * 10);
    }

    cout << s.Pop() << endl; // 100

    s.Push(200);
    s.Pop();
    s.Push(300);

    Display(s);
    

    return 0;
}