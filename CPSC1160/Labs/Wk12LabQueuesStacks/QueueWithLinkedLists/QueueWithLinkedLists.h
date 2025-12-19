#ifndef QUEUEWITHLINKEDLISTS_H
#define QUEUEWITHLINKEDLISTS_H
#include <iostream>
#include "LinkedList.h"
using namespace std;
class Queue{
private:
    LinkedList data; // Using LinkedList to store queue elements, where head of data is the front of the queue and tail of data is the rear

public:
    Queue(){
        //data = LinkedList(); // unnecessary as data is already initialized (when the object is created)
    }

    bool IsEmpty(){
        return data.IsEmpty(); // Check if the linked list is empty
    }

    void Enqueue(int item){
        // adds an item to the end of the queue
        // COMPLETE THE CODE
        data.AddLast(item);
    }

    int Dequeue(){
        // removes the first item in the queue and returns it
        if (IsEmpty()){
            cout << "Queue is empty! Returning -1." << endl;
            return -1; // Indicating that the queue is empty
        }
       // COMPLETE THE CODE
       return data.RemoveFirst();

    }

    int PeekFront(){
        // look at the first item in the queue without removing it
        if (IsEmpty()){
            cout << "Queue is empty! Returning -1." << endl;
            return -1; // Indicating that the queue is empty
        }

        // COMPLETE THE CODE
        return data.GetFirstValue();
    }

    int PeekRear(){
        // look at the last item in the queue without removing it
        if (IsEmpty()){
            cout << "Queue is empty! Returning -1." << endl;
            return -1; // Indicating that the queue is empty
        }

        // COMPLETE THE CODE
        return data.GetLastValue();
    }

    int GetSize(){
        // returns the number of items in the queue
        return data.Length(); // Return the length of the linked list, which represents the size of the queue
    }
};



#endif