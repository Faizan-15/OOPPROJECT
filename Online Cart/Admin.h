#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"

class Admin : public User {
private:
    std::string department;

public:
    Admin(const std::string& id, const std::string& name, 
          const std::string& email, const std::string& dept);
    
    void displayProfile() const override;
};

#endif