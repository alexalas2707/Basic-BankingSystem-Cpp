#include "Bank.h"
#include <iostream>

// Fucntion to add a customer to the bank's list of customers
void Bank::AddCustomer(const Customer& cust) {
    customers.push_back(cust);
}

// Display the details of all customers in the bank's list
void Bank::DisplayAllCustomers() const {
    for (const auto& cust : customers) {
        cust.DisplayCustomerDetails();
        std::cout << "-------------------------" << std::endl;
    }
}

// Search and return a pointer to a customer based on a given customer ID
// If not found, returns null pointer
Customer* Bank::FindCustomer(int id) {
    for (auto& cust : customers) {
        if (cust.GetCustomerID() == id) {
            return &cust;
        }
    }
    return nullptr;
}
