#ifndef NODE_H
#define NODE_H

class Node{
public:
    int value; // value held at current node
    Node* next; //  address of next node

    Node(){
        value = 0;
        next = nullptr;
    }
    Node(int z){
        value = z;
        next = nullptr;
    }
};

#endif