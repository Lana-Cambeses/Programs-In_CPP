#ifndef PRODUCTNODE_H
#define PRODUCTNODE_H
#include <string>
#include <iostream>

using namespace std;

class ProductNode{
public:
    string name; // Name of the product
    double price; // Price of the product
    int quantity; // Quantity of the product in stock
    ProductNode* prev; // Pointer to the previous product node in the doubly linked list
    ProductNode* next; // Pointer to the next product node in the doubly linked list

    ProductNode(){
        name = "n/a";
        price = 0.0;
        quantity = 0;
        prev = nullptr;
        next = nullptr;
    }

    ProductNode(string s, double p, int q){
        name = s;
        price = p;
        quantity = q;
        prev = nullptr;
        next = nullptr;
    }

    friend ostream& operator<<(ostream& os, const ProductNode& p) {
        os << "Name: " << p.name << ", Price: $" << p.price << ", Quantity: " << p.quantity;
        return os;
    }
};

#endif