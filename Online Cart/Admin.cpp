#include "Admin.h"
#include <iostream>

Admin::Admin(const std::string& id, const std::string& name, 
             const std::string& email, const std::string& dept)
    : User(id, name, email), department(dept) {}

void Admin::displayProfile() const {
    std::cout << "\nADMIN PROFILE\n";
    std::cout << "ID: " << id << "\nName: " << name 
              << "\nEmail: " << email << "\nDepartment: " << department << "\n";
}