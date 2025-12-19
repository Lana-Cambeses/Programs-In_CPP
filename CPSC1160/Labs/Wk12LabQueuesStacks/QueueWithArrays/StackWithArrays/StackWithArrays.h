#ifndef STACKWITHARRAYS_H
#define STACKWITHARRAYS_H
#include <iostream>
#include "FlexibleArrayOperatorsSols.h"
using namespace std;
class Stack{
private:
    FlexibleArrayOperators data; // back is top, because pushback and popback are O(1) (faster than pushfront and popffont because both of these are O(n))
    int size;

public:
    Stack(){
        data = FlexibleArrayOperators();
        size = 0;
    }

    bool IsEmpty(){
        return size == 0;
    }

    void Push(int item){
        // adds a new item to the top of the stack
        data.pushBack(item);
        size++;
    }

    int Pop(){
        // removes top most item, and return value removed, (return 0 if nothing to remove)
        if(IsEmpty()){
            cout << "empty stack, nothing to remove, returning 0\n";
            return 0;
        }

        int item = data.getLastValue();

        data.popBack();
        size--;
        return item;
    }

    int Peek(){
        // look at the top of stack
        return data.getLastValue();

    }

    int GetSize(){
        // returns the number of items in the stack
        return size;
    }

    void Show(){
        cout << data << endl;
    }
};



#endif