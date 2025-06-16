#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "User.h"

const int MAX_CART_ITEMS = 20;

class Customer : public User {
private:
    std::string shippingAddress;

public:
    Customer(const std::string& id, const std::string& name, 
             const std::string& email, const std::string& address);
    
    void displayProfile() const override;
};

#endif