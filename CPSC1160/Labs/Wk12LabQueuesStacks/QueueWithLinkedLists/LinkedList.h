#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "Node.h"
#include <climits>
using namespace std;

class LinkedList{
public:
    Node* head; // points to the first node
    Node* tail; // points to the last node

    LinkedList(){
        // empty linked list
        cout << "linked list's default constructor called\n";
        head = tail = nullptr;
    }

    LinkedList(const LinkedList &source){
        //cout << "linked list's copy constructor called\n";
        head = tail = nullptr; // initialize to empty
        Node* current = source.head;
        while(current != nullptr){
            AddLast(current->value); // add each value to the new linked list
            current = current->next; // move to the next node in the source list
        }                
    }
    
    ~LinkedList(){
        cout << "linked list's destructor called\n";
        Clear(head);
        head = tail = nullptr;      
    }

    // overloaded assignment operator
    LinkedList& operator=(const LinkedList &source){
        //cout << "linked list's assignment operator called\n";
        if(this != &source){ // check for self-assignment
            Clear(head); // clear the current linked list
            head = tail = nullptr; // reset to empty
            Node* current = source.head;
            while(current != nullptr){
                AddLast(current->value); // copy each value from source
                current = current->next; // move to the next node in the source list
            }
        }
        return *this; // return the current object
    }

    // deletes all nodes in the linked list starting from current
    void Clear(Node* current){
        if(current == nullptr){
            return; // base case
        }
        Clear(current->next); // recursive call
        cout << "deleting node with value: " << current->value << endl;
        // delete the current node
        delete current; // delete the current node
        current = nullptr; // set pointer to null        
    }

    bool IsEmpty(){
        return head == nullptr;
    }
    
    // AddFirst(int x): adds a new node containing x
    // to the beginning of the  linked list
    void AddFirst(int item){
        Node* newNode = new Node(item);
        if(IsEmpty()){
            head = tail = newNode;
        }
        else{
            newNode->next = head;
            head = newNode;
        }        
    }

    void AddLast(int item){
        Node* newNode = new Node(item);
        if(IsEmpty()){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    void Add(int index, int val){
        int len = Length();
        if(index < 0 || index > len){
            cout << "index out of bounds\n";
            return;
        }
        if(index == 0){
            AddFirst(val);
        }
        else if(index == len){
            AddLast(val);
        }
        else{
            Node* newNode = new Node(val);
            Node* current = Get(index - 1);
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    // removes the first node in the linked list
    // and returns the value inside that node
    int RemoveFirst(){
        if(IsEmpty()){
            cout << "list is empty! returning 0" << endl;
            return 0;
        } 
        else if(head == tail){
            int temp = head->value;
            delete head;
            head = tail = nullptr;
            return temp;
        }
        else{ // length > 1
            Node* toDelete = head;
            int temp = toDelete->value;
            head = head->next;
            delete toDelete;
            toDelete = nullptr;
            return temp;           

        }    
    }

    // removes the last node in the linked list and returns its value
    int RemoveLast(){
        if(IsEmpty()){
            cout << "nothing to remove returning 0 as a dummy value\n";
            return 0;
        }
        else{
            if(head == tail){
                int val = head->value;
                delete head;
                head = tail = nullptr;
                return val;
            }
            else{
                Node* beforeTail = head;
                while(beforeTail->next != tail){
                    beforeTail = beforeTail->next;
                }

                beforeTail->next = nullptr;
                int val = tail->value;
                delete tail;
                tail = beforeTail;
                return val;
            }
        }
        
    }

    // removes the node at position index and returns its value
    int Remove(int index){
        int len = Length();
        if(index < 0 || index >= len){
            cout << "index out of bounds\n";
            return 0;
        }
        if(index == 0){
            return RemoveFirst();
        }
        else if(index == Length() - 1){
            return RemoveLast();
        }
        else{
            Node* current = Get(index - 1);
            Node* toDelete = current->next;
            int val = toDelete->value;
            current->next = toDelete->next;
            delete toDelete;
            toDelete = nullptr;
            return val;
        }
        
    }

    void Show(){
        cout << "the list: \n";
        Node* temp = head;
        while(temp != nullptr){
            cout << temp->value << " -> ";
            temp = temp->next;
        }
        cout << endl;
        
    }

    // // Length: returns number of nodes in a linked list
    int Length(){
        int count = 0;
        Node* temp = head;
        while(temp != nullptr){
            count++;
            temp = temp->next;
        }
        return count;        
    }

    // // FindMax: returns node containing the maximum value
    Node* FindMaxNode(){
        if(IsEmpty()){
            cout << "list is empty\n";
            return nullptr;
        }
        Node* maxNode = head;
        Node* current = head->next;
        while(current != nullptr){
            if(current->value > maxNode->value){
                maxNode = current;
            }
            current = current->next;
        }
        return maxNode;        
    }
    
    int FindMax(){
        Node* maxNode = FindMaxNode();
        if(maxNode != nullptr){
            return maxNode->value;
        }
        else{
            cout << "list is empty. returning 0.\n";
            return 0;    
        }
    }

    int FindMin(){
        if(IsEmpty()){
            cout << "list is empty. returning 0.\n";
            return 0;
        }
        Node* minNode = head;
        Node* current = head->next;
        while(current != nullptr){
            if(current->value < minNode->value){
                minNode = current;
            }
            current = current->next;
        }
        return minNode->value;        
    }

    // return the number of nodes containing odd values
    int CountOdd(){
        int count = 0;
        Node* current = head;
        while(current != nullptr){
            if(current->value % 2 != 0){
                count++;
            }
            current = current->next;
        }
        return count;        
    }

    // return the difference between the highest and lowest values
    int MaxDiff(){
        if(IsEmpty()){
            cout << "list is empty. returning 0.\n";
            return 0;
        }
        int maxVal = FindMax();
        int minVal = FindMin();
        return maxVal - minVal;        
    }

    // void Reverse(){
       

    // }
    
    // returns the node at index i
    Node* Get(int i){
        if(i < 0 || i >= Length()){
            cout << "index out of bounds\n";
            return nullptr;
        }
        Node* current = head;
        for(int j = 0; j < i; j++){
            current = current->next;
        }
        return current;
    }

    int GetFirstValue(){
        if(IsEmpty()){
            cout << "list is empty. returning 0.\n";
            return 0;
        }
        return head->value;
    }

    int GetLastValue(){
        if(IsEmpty()){
            cout << "list is empty. returning 0.\n";
            return 0;
        }
        return tail->value;
    }

    Node *Search(int value){
        Node* current = head;
        while(current != nullptr){
            if(current->value == value){
                return current; // found the node
            }
            current = current->next;
        }
        return nullptr; // not found
    }

    void RemoveOddValues(){
        Node* current = head;
        Node* previous = nullptr;

        while(current != nullptr){
            if(current->value % 2 != 0){ // odd value
                if(previous == nullptr){ // removing the head
                    head = current->next;
                    delete current;
                    current = head; // move to the next node
                }
                else{ // removing a node in the middle or end
                    previous->next = current->next;
                    delete current;
                    current = previous->next; // move to the next node
                }
            }
            else{ // even value, just move to the next node
                previous = current;
                current = current->next;
            }
        }

        // update tail if necessary
        if(head == nullptr){
            tail = nullptr; // list is now empty
        }
        else{
            tail = previous; // last node is now the previous node
        }      

    }

    void Swap(Node* left, Node* right){
        if(left == nullptr || right == nullptr || left == right){
            return; // nothing to swap
        }
        
        // swap values of the nodes
        int temp = left->value;
        left->value = right->value;
        right->value = temp;

        // can you think of a way to swap the nodes themselves (and NOT just the values inside the nodes)?
        // Hint: you need to update the next pointers of the nodes
    }

};

#endif
