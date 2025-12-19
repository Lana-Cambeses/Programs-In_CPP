#ifndef STORE_H
#define STORE_H
#include <string>
#include <iostream>
#include "CategoryNode.h"

using namespace std;

class Store {
public:
    string name;
    CategoryNode* categories; // Pointer to the first category in the doubly linked list of categories in this store, nodes in this list are kept in alphabetical order by name!!!!!
    Store() {
        name = "n/a";
        categories = nullptr;
    }

    Store(string s) {
        name = s;
        categories = nullptr;
    }

    // Copy constructor to create a new Store from an existing one
    // This will copy the name and create a new list of categories by copying each category from the existing store
    // The new store will have its own list of categories, not just pointers to the same categories
    Store(const Store& other) {
        name = other.name;
        categories = nullptr; // Initialize categories to nullptr, will be populated later

        // Copy categories from the other store
        CategoryNode* temp = other.categories;
        while (temp != nullptr) {
            AddCategory(temp->name); // Use the AddCategory function to add categories
            temp = temp->next;
        }
    }

    ~Store() {
        // Destructor to clean up the category list
        RemoveCategories(); // Call the function to remove all categories
    }

    // Function to remove all categories from the store
    // This will delete all category nodes and their associated product lists
    // After this function is called, the categories pointer will be set to nullptr
    void RemoveCategories() {
        CategoryNode* current = categories;
        while (current != nullptr) {
            CategoryNode* toDelete = current;
            current = current->next;
            delete toDelete; // Free memory for each category node
        }
        categories = nullptr; // Set the category pointer to nullptr after deletion
    }

    // overload the = operator to assign one Store to another
    // This will copy the name and create a new list of categories by copying each category from the existing store
    // The new store will have its own list of categories, not just pointers to the same categories
    Store& operator=(const Store& other) {
        if (this != &other) { // Check for self-assignment
            RemoveCategories(); // Clean up current store
            name = other.name;
            categories = nullptr; // Initialize categories to nullptr, will be populated later

            // Copy categories from the other store
            CategoryNode* temp = other.categories;
            while (temp != nullptr) {
                AddCategory(temp->name); // Use the AddCategory function to add categories
                temp = temp->next;
            }
        }
        return *this; // Return the current object
    }

    // Finds a category by name in the store's category list
    // Returns a pointer to the category if found, or nullptr if not found.
    CategoryNode* FindCategory(string s){
        // COMPLETE THE CODE
    }

    // Adds a new category to the store
    // If the category already exists, it does not add it again but informs the user that the category already exists and shows the number of products in that category.
    // If the category does not exist, it creates a new category and adds it to the doubly linked list in alphabetical order by name.
    // If the list is empty, it simply adds the new category as the first element.
    void AddCategory(string s) {
       // COMPLETE THE CODE
    }

    // Removes a category from the store
    // If the category does not exist, it informs the user that the category was not found
    // If the category exists, it removes the category from the doubly linked list of categories
    // If the category is the only one in the list, it sets the categories pointer to nullptr
    void RemoveCategory(string s) {
        // COMPLETE THE CODE
    }

    // Adds a product to a category in the store
    // If the category does not exist, it informs the user that the category was not found
    // If the category exists, it adds the product to the doubly linked list of products in that category, keeping the list sorted by product name in alphabetical order.
    // If the product already exists in the category, it informs the user that the product already exists and adds the quantity to the existing product and sets the price to the new price.
    void AddProductToCategory(string categoryName, const ProductNode& p) {
        // COMPLETE THE CODE
    }

    // Display products filtered by category name
    // If the category does not exist, it informs the user that the category was not found
    void ShowProductsByCategory(string categoryName) {
        CategoryNode* category = FindCategory(categoryName);
        if (category) {
            cout << *category; // Use the overloaded << operator to print the category and its products
        } else {
            cout << "***Category " << categoryName << " not found.***" << endl;
        }
    }

    // Display products filtered by price range
    // It iterates through all categories and their products, checking if the product's price falls within the specified range.
    // If no products are found in the specified range, it informs the user that no products were found.
    // This function does not modify the store or its categories, it only displays the products that match the criteria.
    void ShowProductsByPriceRange(double minPrice, double maxPrice) {
       // COMPLETE THE CODE
    }
};
#endif