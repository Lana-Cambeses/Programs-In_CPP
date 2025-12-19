#ifndef CATEGORYNODE_H
#define CATEGORYNODE_H

#include <string>
#include <iostream>
#include "ProductNode.h"

using namespace std;

class CategoryNode{
public:
    string name;
    ProductNode* prods; // Pointer to the first product in the doubly linked list of products in this category, prods is kept sorted by name in alphabetical order!!!!!!!!!!!!!
    CategoryNode* prev; // Pointer to the previous category node in the doubly linked list
    CategoryNode* next; // Pointer to the next category node in the doubly linked list

    CategoryNode(){
        name = "n/a";
        prods = nullptr;
        prev = nullptr;
        next = nullptr;
    }

    CategoryNode(string s){
        name = s;
        prods = nullptr;
        prev = nullptr;
        next = nullptr;
    }

    // Copy constructor to create a new CategoryNode from an existing one
    // This will copy the name and create a new list of products by copying each product from the existing category
    // The new category will have its own list of products, not just pointers to the same products
    CategoryNode(const CategoryNode& other) {
        // COMPLETE THE CODE
    }

    ~CategoryNode() {
        // Destructor to clean up the product list
        RemoveProducts(); // Call the function to remove all products
        prods = nullptr; // Set prods to nullptr to avoid dangling pointer
    }

    // Function to remove all products from the category
    // This will delete all ProductNode objects in the doubly linked list of products
    void RemoveProducts() {
        // COMPLETE THE CODE
    }

    // Function to find a product by name in the category, case-sensitive search
    // Returns a pointer to the ProductNode if found, otherwise returns nullptr
    ProductNode* FindProductByName(string s) const{
        // COMPLETE THE CODE
    }

    // overload the = operator to assign one CategoryNode to another
    // This will copy the name and create a new list of products by copying each product from the existing category
    // The new category will have its own list of products, not just pointers to the same products
    CategoryNode& operator=(const CategoryNode& other) {
        if (this != &other) { // Check for self-assignment
            // COMPLETE THE CODE
        }
        return *this; // Return the current object
    }

    // overload the += operator to add a product to the current list of products in this category and return the updated category by reference
    // If the product already exists, it updates the quantity (new quantity is added to the current quantity) and overwrites old price
    // If the product does not exist, it inserts the new product in the doubly linked list of products in alphabetical order by name
    // If the list is empty, it simply adds the new product as the first element.
    CategoryNode& operator+=(const ProductNode& p) {
        // COMPLETE THE CODE
    }

    // overload the -= operator to remove a product from the current list of products in this category
    // If the product does not exist, it informs the user that the product was not found
    // If the product exists, it removes the product from the doubly linked list of products
    // If the product is the only one in the list, it sets the prods pointer to nullptr
    CategoryNode& operator-=(const string& productName) {
        // COMPLETE THE CODE
    }

    // Function to count the number of products in the category
    // Returns the count of products in the doubly linked list
    int CountProducts() const{
        int count = 0;
        ProductNode* temp = prods;
        while(temp != nullptr){
            count++;
            temp = temp->next;
        }
        return count;
    }

    // Overloaded << operator to print the category and its products
    friend ostream& operator<<(ostream& os, const CategoryNode& c) {
        ProductNode* temp = c.prods;
        int index = 1;

        os << "\n\n===================\n";
        os << "Category: " << c.name << " (" << c.CountProducts() << " products)\n";
        os << "===================\n";

        while(temp != nullptr){
            os << index++ << ". " << *temp << endl;
            temp = temp->next;
        }

        return os;
    }
};

#endif // CATEGORYNODE_H