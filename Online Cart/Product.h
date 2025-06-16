#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <iostream>

class Product {
private:
    std::string id;
    std::string name;
    double price;
    int stock;

public:
    Product(const std::string& id = "", const std::string& name = "", 
            double price = 0.0, int stock = 0);
    
    Product operator+(double discount) const;
    void display() const;
};

#endif