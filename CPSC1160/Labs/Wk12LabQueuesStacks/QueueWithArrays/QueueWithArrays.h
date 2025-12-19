#ifndef QUEUEWITHARRAYS_H
#define QUEUEWITHARRAYS_H
#include <iostream>
#include "FlexibleArrayOperatorsSols.h"
using namespace std;
class Queue{
private:
    FlexibleArrayOperators data; // Flexible array to hold queue elements, front is at index 0, back is at the end

public:
    Queue(){
        //data = FlexibleArrayOperators(); // unnecessary as data is already initialized (when the object is created)
    }

    bool IsEmpty(){
        return data.isEmpty();
    }

    void Enqueue(int item){
        // adds item to the end of the queue

        // COMPLETE THE CODE
        data.pushBack(item); 
        
    }

    int Dequeue(){
        // removes the first item from the queue and returns it
        if (IsEmpty()){
            cout << "Queue is empty! Returning -1." << endl;
            return -1; // Indicating that the queue is empty
        }

        // COMPLETE THE CODE
        return data.popFront();
        
    }

    int PeekFront(){
        // look at the first item in the queue without removing it
        if (IsEmpty()){
            cout << "Queue is empty! Returning -1." << endl;
            return -1; // Indicating that the queue is empty
        }

        // COMPLETE THE CODE
        return data[0];
    }

    int PeekRear(){
        // look at the last item in the queue without removing it
        if (IsEmpty()){
            cout << "Queue is empty! Returning -1." << endl;
            return -1; // Indicating that the queue is empty
        }

        // COMPLETE THE CODE
        return data[data.getSize() - 1];
    }

    int GetSize(){
        // returns the number of items in the stack
        return data.getSize(); // Return the current size of the queue
    }
};



#endif