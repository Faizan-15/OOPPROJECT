#include "User.h"
#include <iostream>

User::User(const std::string& id, const std::string& name, const std::string& email)
    : id(id), name(name), email(email) {}