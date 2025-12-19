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

    LinkedList(const LinkedList &source) {
        head = nullptr;
        tail = nullptr;

        Node* curr = source.head;

        while (curr != nullptr) {
            AddLast(curr->value);   // deep copy each node
            curr = curr->next;
        }
    }
    
    ~LinkedList(){
        
    }

    void Clear(Node* current){
        
    }

    bool IsEmpty(){
        return head == nullptr;
    }
    
    // AddFirst(int x): adds a new node containing x
    // to the beginning of the  linked list
    void AddFirst(int item){
        Node* newNode = new Node(item);
        if (IsEmpty()) {
            head = tail = newNode;;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void AddLast(int item){
        Node* newNode = new Node(item);
        if (IsEmpty()) {
            head = tail = newNode;;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        
    }

    // adds a new node containing val at index i in the linked list
    void Add(int i, int val){
        if(i < 0 || i > Length()){
            cout << "index out of bounds\n";
            return;
        }
        if(i == 0){
            AddFirst(val);
        }
        else if(i == Length()){
            AddLast(val);
        }
        else {
            Node* newNode = new Node(val);
            Node* current = head;
            for (int j = 0; j < i; j++) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }

    }

    // removes the first node in the linked list
    // and returns the value inside that node
    int RemoveFirst(){
        if(IsEmpty()) {
            cout << "Error, list is empty" << endl;
            return 0;
        } else if (head == tail) {
            int val = head->value;
            delete head;
            head = tail = nullptr;
            return val;
        } else {
            int val = head->value;
            Node* temp = head;
            head = head->next;
            delete temp;
            temp = nullptr;
            return val;
        }
    }

    // removes the last node in the linked list and returns its value
    int RemoveLast(){
        if(IsEmpty()) {
            cout << "Error, list is empty" << endl;
            return 0;
        } else if (head == tail) {
            int val = head->value;
            delete head;
            head = tail = nullptr;
            return val;
        } else {
            int val = tail->value;
            Node* beforeTail = head;

            while (beforeTail->next != tail) {
                beforeTail = beforeTail->next;
            }

            beforeTail->next = nullptr;
            delete tail;
            tail = beforeTail;
            return val;
        }
    }

    int Remove(int i){
        if(i < 0 || i > Length()){
            cout << "index out of bounds\n";
            return;
        }
        if(i == 0){
            RemoveFirst();
        }
        else if(i == Length() - 1){
            RemoveLast();
        }
        else {
            Node* current = head;
            for (int j = 0; j < i; j++) {
                current = current->next;
            }
            Node* temp = current->next;
            int val = temp->value;
            current->next = temp->next;
            delete temp;
            temp = nullptr;
            return val;
        }
    }

    void Show(){
        cout << "The list" << endl;
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->value << "->";
            temp = temp->next;
        }
        cout << endl;
    }

    // // Length: returns number of nodes in a linked list
    int Length(){
        Node* temp = head;
        int count = 0;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;

    }

    // FindMax: returns node containing the maximum value
    Node* FindMaxNode() {
        if(IsEmpty()){
            cout << "list is empty\n";
            return nullptr;
        }
        Node* temp = head->next;
        Node* max = head;
        while (temp != nullptr) {
            if (temp->value > max-> value) {
                max = temp;
            }
            temp = temp->next;
        }
        return max;
    }

    int FindMax() {

        Node* maxNode = FindMaxNode();
        if(maxNode != nullptr){
            return maxNode->value;
        } else{
            cout << "list is empty. returning 0.\n";
            return 0;    
        }
    }

    int FindMin() {
        if(IsEmpty()){
            cout << "list is empty\n";
            return 0;
        }
        Node* temp = head->next;
        int min = head->value;
        while (temp != nullptr) {
            if (temp->value < min) {
                min = temp->value;
            }
            temp = temp->next;
        }
        return min;
    }

    // return the number of nodes containing odd values
    int CountOdd(){
        if (IsEmpty()) {
            cout << "list is empty\n";
            return 0;
        }

        Node* temp = head;
        int count = 0;
        while (temp != nullptr) {
            if (temp->value % 2 != 0) {
                count++;
            } 
            temp = temp->next;
        }

        return count;

    }

    // return the difference between the highest and lowest values
    int MaxDiff() {
        if (IsEmpty()) {
            cout << "list is empty\n";
            return 0;
        } else {
            int max = FindMax();
            int min = FindMin();
            return max - min;
        }
    }

    void Reverse() {
        if (IsEmpty()) {
            cout << "list is empty\n";
            return;
        } else {
            Node* prev = nullptr;
            Node* curr = head;
            Node* next = nullptr;

            while (curr != nullptr) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            tail = head;
            head = prev;
        }

    }
    
    //returns the node at index i
    Node* Get(int i) {
        if (i < 0 || i > Length() - 1) {
            cout << "index out of bounds\n";
            return nullptr;
        }

        Node* temp = head;
        for (int j = 0; j < i; j++) {
            temp = temp->next;
        }

        return temp;
    }

    Node *Search(int value) {
        if (IsEmpty()) {
            cout << "list is empty\n";
            return nullptr;
        } else {

            Node* curr = head;

            while (curr != nullptr) {
                if (curr->value == value) {
                    return curr;
                }
                curr = curr->next;
            }

            return nullptr;
        }
    }

    void RemoveOddValues(){
        if (IsEmpty()) {
            cout << "list is empty\n";
            return;
        } else {
            Node* curr = head;
            int i = 0;

            while (curr != nullptr) {
                if (curr->value % 2 != 0) {
                    Remove(i);
                    curr = Get(i); 
                } else {
                    curr = curr->next;
                    i++;
                }
                
            }
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

    }

    //Add a new node after every second node of some linked list
    void AddEveryTwo() {
        
    }

};

#endif
