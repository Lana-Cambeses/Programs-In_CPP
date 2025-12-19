#ifndef STACKWITHLINKEDLIST_H
#define STACKWITHLINKEDLIST_H

#include "LinkedList.h"
class Stack{
private:
    LinkedList data; // head node is the top of the stack
    int size;

public:
    Stack(){
        size = 0;
    }

    bool IsEmpty(){
        return size == 0;
    }

    void Push(int item){
        data.AddFirst(item); // add to the front of the linked list
        size++;       
    }

    int Pop(){
        if(IsEmpty()){
            cout << "stack is empty! returning 0" << endl;
            return 0;
        }
        int val = data.GetFirstValue(); // get the top value
        data.RemoveFirst(); // remove the top node
        size--;
        return val; // return the value of the removed node
    }

    int Peek(){
        if(IsEmpty()){
            cout << "stack is empty! returning 0" << endl;
            return 0;
        }
        return data.GetFirstValue(); // return the value of the top node without removing it        
    }

    int GetSize(){
        return size; // return the current size of the stack       
    }
};



#endif