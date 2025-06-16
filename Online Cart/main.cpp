#include <iostream>
#include "Customer.h"
#include "Admin.h"
#include "Product.h"

int main() {
    // Polymorphism example
    User* user1 = new Customer("C101", "Alice", "alice@email.com", "123 Main St");
    User* user2 = new Admin("A101", "Bob", "bob@admin.com", "Inventory");
    
    user1->displayProfile();
    user2->displayProfile();
    
    // Operator overloading example
    Product laptop("P100", "Laptop", 999.99, 10);
    Product discounted = laptop + 50.0;
    discounted.display();
    
    delete user1;
    delete user2;
    return 0;
}