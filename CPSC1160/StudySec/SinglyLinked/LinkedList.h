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

    // LinkedList(const LinkedList &source){
        
    // }
    
    // ~LinkedList(){
        
    // }

    // void Clear(Node* current){
        
    // }

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

    // adds a new node containing val at index i in the linked list
    // void Add(int i, int val){
       

    // }

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

    //Remove index
    int Remove(int i){
        
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
    // Node* FindMaxNode(){
        
    // }
    // int FindMax(){
        
    // }

    // int FindMin(){
        
    // }

    // // return the number of nodes containing odd values
    // int CountOdd(){
        
    // }

    // // return the difference between the highest and lowest values
    // int MaxDiff(){
        
    // }

    // void Reverse(){
       

    // }
    
    // returns the node at index i
    // Node* Get(int i)
    // {
        
    // }

    // Node *Search(int value)
    // {
        
    // }

    // void RemoveOddValues(){
        

    // }

    // void Swap(Node* left, Node* right){
         
    // }

};

#endif
