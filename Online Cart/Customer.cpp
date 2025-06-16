#include "Customer.h"
#include <iostream>

Customer::Customer(const std::string& id, const std::string& name, 
                   const std::string& email, const std::string& address)
    : User(id, name, email), shippingAddress(address) {}

void Customer::displayProfile() const {
    std::cout << "\nCUSTOMER PROFILE\n";
    std::cout << "ID: " << id << "\nName: " << name 
              << "\nEmail: " << email << "\nAddress: " << shippingAddress << "\n";
}