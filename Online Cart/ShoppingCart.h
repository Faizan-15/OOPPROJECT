// ShoppingCart.h
#pragma once
#include "Product.h"

const int MAX_CART_ITEMS = 20;

class ShoppingCart {
private:
    Product items[MAX_CART_ITEMS]; // Fixed-size array
    int itemCount;

public:
    ShoppingCart() : itemCount(0) {}

    void addItem(const Product& product);
    void removeItem(const std::string& productId);
    double calculateTotal() const;
    void displayCart() const;
};