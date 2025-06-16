#include "Product.h"

Product::Product(const std::string& id, const std::string& name, 
                 double price, int stock)
    : id(id), name(name), price(price), stock(stock) {}

Product Product::operator+(double discount) const {
    return Product(id, name, price - discount, stock);
}

void Product::display() const {
    std::cout << "Product: " << name << " (ID: " << id 
              << "), Price: $" << price << ", Stock: " << stock << "\n";
}