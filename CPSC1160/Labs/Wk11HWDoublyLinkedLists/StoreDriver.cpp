#include <iostream>
#include <string>
#include <fstream>
#include "ProductNode.h"
#include "CategoryNode.h"
#include "Store.h"

using namespace std;

void LoadStoreFromFile(Store& store, const string& filename) {
    // This function would read from a file (filename) and populate the store with categories and products.
    // filename begins with the name of the store on the first line.
    // each subsequent line contains a category name, product name, price, and quantity in the format:
    // CategoryName,ProductName,Price,Quantity
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file: " << filename << endl;
        return;
    }
    string line;
    getline(file, store.name); // Read the store name from the first line
    while (getline(file, line)) {
        size_t pos = line.find(',');
        if (pos == string::npos) 
            continue; // Skip if no comma found
        string categoryName = line.substr(0, pos);
        string productInfo = line.substr(pos + 1);
        
        pos = productInfo.find(',');
        if (pos == string::npos) 
            continue; // Skip if no comma found
        string productName = productInfo.substr(0, pos);
        
        size_t nextPos = productInfo.find(',', pos + 1);
        if (nextPos == string::npos) 
            continue; // Skip if no next comma found
        double price = stod(productInfo.substr(pos + 1, nextPos - pos - 1));
        
        int quantity = stoi(productInfo.substr(nextPos + 1));

        // cout << "Adding product: " << productName << " to category: " << categoryName << " with Price: $" << price << ", Quantity: " << quantity << endl;
        store.AddCategory(categoryName); // Ensure the category exists
        store.AddProductToCategory(categoryName, ProductNode(productName, price, quantity));
    }
    file.close();
    cout << "========Store loaded from file: " << store.name << "============" << endl;
}

void TestCategoryNode() {
    // Create a CategoryNode and add some products to it
    CategoryNode category("Electronics");
    category += ProductNode("Laptop", 999.99, 10);
    category += ProductNode("Smartphone", 499.99, 20);
    category += ProductNode("Tablet", 299.99, 15);

    cout << "Category after adding products:" << endl;
    cout << category << endl;

    // Find a product by name
    ProductNode* foundProduct = category.FindProductByName("Smartphone");
    if (foundProduct) {
        cout << "Found product: " << *foundProduct << endl;
    } else {
        cout << "Product not found." << endl;
    }

    // Remove a product
    category -= "Tablet";
    cout << "Category after removing Tablet:" << endl;
    cout << category << endl;

    // Count products
    int count = category.CountProducts();
    cout << "Number of products in category: " << count << endl;

    // Remove all products
    category.RemoveProducts();
    cout << "Category after removing all products:" << endl;
    cout << category << endl;
}
/***
// Expected Output of TestCategoryNode:
***Product Smartphone added with price: $499.99 and quantity: 20
***Product Tablet added with price: $299.99 and quantity: 15
Category after adding products:


===================
Category: Electronics (3 products)
===================
1. Name: Laptop, Price: $999.99, Quantity: 10
2. Name: Smartphone, Price: $499.99, Quantity: 20
3. Name: Tablet, Price: $299.99, Quantity: 15

Found product: Name: Smartphone, Price: $499.99, Quantity: 20
***Product Tablet removed.***
Category after removing Tablet:


===================
Category: Electronics (2 products)
===================
1. Name: Laptop, Price: $999.99, Quantity: 10
2. Name: Smartphone, Price: $499.99, Quantity: 20

Number of products in category: 2
Category after removing all products:


===================
Category: Electronics (0 products)
===================
***/


int main() {
    ///////////////////////////////////////////////////////////
    // // RUN TEST1 : TestCategoryNode separately to test CategoryNode functionality
    ///////////////////////////////////////////////////////////
    // TestCategoryNode(); // Test the CategoryNode functionality

    ///////////////////////////////////////////////////////////
    // // RUN TEST2 : TEST Store functionality
    ///////////////////////////////////////////////////////////
    // Store store;
    // LoadStoreFromFile(store, "store1.txt"); // Load store data from a file

    // // test every functionality of Store class
    // cout << "Store Name: " << store.name << endl;
    // cout << "Categories in Store:" << endl;
    // CategoryNode* currentCategory = store.categories;
    // while (currentCategory != nullptr) {
    //     cout << *currentCategory << endl; // Print each category
    //     currentCategory = currentCategory->next;
    // }
    // // Add a new category
    // store.AddCategory("Books");
    // cout << "After adding Books category:" << endl;
    // currentCategory = store.categories;
    // while (currentCategory != nullptr) {
    //     cout << *currentCategory << endl; // Print each category
    //     currentCategory = currentCategory->next;
    // }
    // // Add a product to an existing category
    // store.AddProductToCategory("Electronics", ProductNode("Smartwatch", 199.99, 5));
    // cout << "After adding Smartwatch to Electronics category:" << endl;
    // currentCategory = store.FindCategory("Electronics");
    // if (currentCategory) {
    //     cout << *currentCategory << endl; // Print the Electronics category
    // } else {
    //     cout << "Electronics category not found." << endl;
    // }
    // // Add a product to a non-existing category
    // store.AddProductToCategory("NonExistingCategory", ProductNode("TestProduct", 99.99, 1));
    // // Remove a product from a category
    // currentCategory = store.FindCategory("Electronics");
    // if (currentCategory) {
    //     *currentCategory -= "Smartwatch"; // Remove Smartwatch from Electronics
    //     cout << "After removing Smartwatch from Electronics category:" << endl;
    //     cout << *currentCategory << endl; // Print the Electronics category
    // } else {
    //     cout << "Electronics category not found." << endl;
    // }

    // // Remove a category
    // store.RemoveCategory("Books");
    // cout << "After removing Books category:" << endl;
    // currentCategory = store.categories;
    // while (currentCategory != nullptr) {
    //     cout << *currentCategory << endl; // Print each category
    //     currentCategory = currentCategory->next;
    // }
    // // Show products by category
    // store.ShowProductsByCategory("Electronics");
    // store.ShowProductsByCategory("Books"); // Should inform that Books category was not found
    // // Show products by a non-existing category
    // store.ShowProductsByCategory("NonExistingCategory"); // Should inform that the category was not found

    // // Show products by price range
    // store.ShowProductsByPriceRange(100.00, 500.00); // Should show products within the specified price range
    // store.ShowProductsByPriceRange(50.00, 100.00); // Should show products within the specified price range
    // store.ShowProductsByPriceRange(5.00, 20.00); // Should not find any products in this range

    // // Clean up the store
    // store.RemoveCategories(); // This will delete all categories and their products
    // cout << "\n\nAfter removing all categories:" << endl;
    // currentCategory = store.categories;
    // if (currentCategory == nullptr) {
    //     cout << "No categories left in the store." << endl; // Should be empty now
    // } else {
    //     while (currentCategory != nullptr) {
    //         cout << *currentCategory << endl; // Print each category
    //         currentCategory = currentCategory->next;
    //     }
    // }
    
}