#include "Bank.h"
#include "Customer.h"
#include "Account.h"
#include <iostream>

int main() {

    //---------------------------------------Creating  a Bank instance--------------------------------------
    Bank myBank;

    //--------------------------------------Main loop for the banking system ----------------------------
    while (true) {

        int choice;     //Showing the main menu
        std::cout << "==== Banking System Menu ====" << std::endl;

        // Menu options
        std::cout << "1. Add a new customer." << std::endl;
        std::cout << "2. Get account details." << std::endl;
        std::cout << "3. Perform transactions on account." << std::endl;
        std::cout << "4. Display all customers." << std::endl;  
        std::cout << "5. Exit." << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        //Handling user choice
        switch (choice) {

        case 1:     //------------Option 1- Adding a new customer and account-----------------------------
        {
            int id;
            std::string name;
            std::cout << "Enter customer ID: ";
            std::cin >> id;
            std::cout << "Enter customer name: ";
            std::cin.ignore();  // clear the buffer
            std::getline(std::cin, name);

            //Creating a new customer instance
            Customer newCustomer(id, name);

            Account newAccount(0.0, "Savings"); // Initializing new account with 0 balance and type "Savings"
            newCustomer.AddAccount(newAccount); // Adding created account to the lists of accounts
            myBank.AddCustomer(newCustomer); // Adding customer to the bank's list of customers
            std::cout << "Customer added successfully!" << std::endl;
            break;
        }

        case 2:     //------------Option 2- Show the details of a customer's account-----------------------
        {
            int id;
            std::cout << "Enter customer ID to get account details: ";
            std::cin >> id;

            //Search for customer in the list of customers
            Customer* cust = myBank.FindCustomer(id);

            //If customer is found, display the details, otherwise show an error
            if (cust) {
                cust->DisplayCustomerDetails();
            }
            else {
                std::cout << "Customer not found!" << std::endl;
            }
            break;
        }

        case 3:     //------------Option 3- Perform transactions on a custmer's account----------------------
        {
            int id, accNum;
            float amount;
            std::cout << "Enter customer ID: ";
            std::cin >> id;
            Customer* cust = myBank.FindCustomer(id);
            if (cust) {
                std::cout << "1. Deposit." << std::endl;
                std::cout << "2. Withdraw." << std::endl;
                std::cout << "3. Get Balance." << std::endl;
                std::cout << "Enter your transaction choice: ";
                int transactionChoice;
                std::cin >> transactionChoice;

                // Handling secondary menu choice of transactions
                switch (transactionChoice) {

                case 1: //Deposit into account
                    std::cout << "Enter account number: ";
                    std::cin >> accNum;
                    std::cout << "Enter deposit amount: ";
                    std::cin >> amount;
                    if (cust->Deposit(accNum, amount)) {
                        std::cout << "Amount deposited!" << std::endl;
                    }
                    else {
                        std::cout << "Failed to deposit amount. Check account number." << std::endl;
                    }
                    break;

                case 2: //Withdraw from account
                    std::cout << "Enter account number: ";
                    std::cin >> accNum;
                    std::cout << "Enter withdrawal amount: ";
                    std::cin >> amount;
                    if (cust->Withdraw(accNum, amount)) {
                        std::cout << "Amount withdrawn!" << std::endl;
                    }
                    else {
                        std::cout << "Failed to withdraw amount. Check account number or balance." << std::endl;
                    }
                    break;

                case 3: //Show account balance
                    std::cout << "Enter account number: ";
                    std::cin >> accNum;
                    float balance; 
                    balance = cust->GetBalance(accNum); 
                    if (balance >= 0) {
                        std::cout << "Account balance: " << balance << std::endl;
                    }
                    else {
                        std::cout << "Account not found!" << std::endl;
                    }
                    break;

                default: //Default to prevent invalid choice error
                    std::cout << "Invalid transaction choice!" << std::endl;
                    break;
                }
            }
            else {
                std::cout << "Customer not found!" << std::endl;
            }
            break;
        }

        //-------------------------------Option 4-displaying all customers----------------------------------
        case 4:
            myBank.DisplayAllCustomers();
            break;

        //---------------------------------Choice to exit the program--------------------------------------
        case 5:
            std::cout << "Thank you for using our banking system. Goodbye!" << std::endl;
            return 0;
        default:
            std::cout << "Invalid choice! Try again." << std::endl;
            break;
        }
    }
}
