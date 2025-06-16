#ifndef USER_H
#define USER_H

#include <string>

class User {
protected:
    std::string id;
    std::string name;
    std::string email;

public:
    User(const std::string& id, const std::string& name, const std::string& email);
    virtual ~User() = default;
    virtual void displayProfile() const = 0;
    
    std::string getId() const { return id; }
    std::string getName() const { return name; }
    std::string getEmail() const { return email; }
};

#endif