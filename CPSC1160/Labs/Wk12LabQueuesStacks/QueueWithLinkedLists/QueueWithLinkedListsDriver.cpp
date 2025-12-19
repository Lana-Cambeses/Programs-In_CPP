#include <iostream>
#include "QueueWithLinkedLists.h"
using namespace std;

void Display(Queue s){
    while(!s.IsEmpty()){
        int item = s.Dequeue();
        cout << "item dequeued " << item << ", items left in the queue " << s.GetSize() << endl;
    }
}
int main() {
    Queue s;
    for(int i = 1; i <= 10; i++){
        s.Enqueue(i * 10);
    }

    cout << "Size of queue after enqueuing 10 items: " << s.GetSize() << endl;
    cout << "Front item: " << s.PeekFront() << endl;
    cout << "Rear item: " << s.PeekRear() << endl;
    cout << "Dequeueing items from the queue:\n";
    cout << "Dequeueing " << s.Dequeue() << endl;
    cout << "Dequeueing " << s.Dequeue() << endl;
    cout << "Size of queue after dequeuing 2 items: " << s.GetSize() << endl;
    cout << "Front item: " << s.PeekFront() << endl;
    cout << "Rear item: " << s.PeekRear() << endl;

    Display(s);

    return 0;
}

/*
sample output:
linked list's default constructor called
Size of queue after enqueuing 10 items: 10
Front item: 10
Rear item: 100
Dequeueing items from the queue:
Dequeueing Dequeueing item: 10
10
Dequeueing Dequeueing item: 20
20
Size of queue after dequeuing 2 items: 8
Front item: 30
Rear item: 100
Dequeueing item: 30
item dequeued 30, items left in the queue 7
Dequeueing item: 40
item dequeued 40, items left in the queue 6
Dequeueing item: 50
item dequeued 50, items left in the queue 5
Dequeueing item: 60
item dequeued 60, items left in the queue 4
Dequeueing item: 70
item dequeued 70, items left in the queue 3
Dequeueing item: 80
item dequeued 80, items left in the queue 2
Dequeueing item: 90
item dequeued 90, items left in the queue 1
Dequeueing item: 100
item dequeued 100, items left in the queue 0
linked list's destructor called
linked list's destructor called
deleting node with value: 100
deleting node with value: 90
deleting node with value: 80
deleting node with value: 70
deleting node with value: 60
deleting node with value: 50
deleting node with value: 40
deleting node with value: 30
*/