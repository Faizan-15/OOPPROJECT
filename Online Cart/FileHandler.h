// FileHandler.h
#pragma once
#include "Product.h"
#include "Customer.h"

class FileHandler {
public:
    // Load products from file into an array
    static int loadProducts(const std::string& filename, Product products[], int maxProducts);

    // Save customers to file
    static void saveCustomer(const std::string& filename, const Customer& customer);
};