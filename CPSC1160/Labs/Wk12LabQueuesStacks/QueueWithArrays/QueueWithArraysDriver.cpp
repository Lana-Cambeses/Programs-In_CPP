#include <iostream>
#include "QueueWithArrays.h"
using namespace std;

void Display(Queue s){
    while(!s.IsEmpty()){
        int item = s.Dequeue();
        cout << "item dequeued " << item << ", items left in the queue " << s.GetSize() << endl;
    }
}
int main() {

    Queue q;

    cout << "Is queue empty? " << (q.IsEmpty() ? "Yes" : "No") << endl;
    cout << "Enqueuing items 1, 2, 3, 4, 5" << endl;
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);
    q.Enqueue(5);
    
    Display(q);

    cout << "Dequeuing " << q.Dequeue() << endl; // Should return 1
    cout << "Dequeuing " << q.Dequeue() << endl; // Should return 2

    cout << "Items left in the queue: " << q.GetSize() << endl;
    cout << "Front item: " << q.PeekFront() << endl; // Should return 3
    cout << "Rear item: " << q.PeekRear() << endl; // Should return 5
    cout << "Is queue empty? " << (q.IsEmpty() ? "Yes" : "No") << endl;
    

    return 0;
}

/*
sample output:
Is queue empty? Yes
Enqueuing items 1, 2, 3, 4, 5
item dequeued 1, items left in the queue 4
item dequeued 2, items left in the queue 3
item dequeued 3, items left in the queue 2
item dequeued 4, items left in the queue 1
item dequeued 5, items left in the queue 0
Dequeuing 1
Dequeuing 2
Items left in the queue: 3
Front item: 3
Rear item: 5
Is queue empty? No
*/