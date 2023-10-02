#include "client.h"
#include <iostream>
#include <fstream>

// Constructor: Reads client information from a file and initializes the Bank
Bank::Bank(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        exit(1);
    }

    file >> num_clients;
    client_info = new Client[num_clients];

    for (int i = 0; i < num_clients; ++i) {
        file >> client_info[i].client_name >> client_info[i].ssn >> client_info[i].bank_account >> client_info[i].balance;
    }

    file.close();
}

// Deep Copy Constructor
Bank::Bank(const Bank& other) {
    num_clients = other.num_clients;
    client_info = new Client[num_clients];

    for (int i = 0; i < num_clients; ++i) {
        client_info[i] = other.client_info[i];
    }
}

// Destructor: Cleans up dynamically allocated memory
Bank::~Bank() {
    delete[] client_info;
}

// Set the client information based on a given list
void Bank::set_client_info(const Client* clients, int num_clients) {
    delete[] client_info;
    this->num_clients = num_clients;
    client_info = new Client[num_clients];
    
    for (int i = 0; i < num_clients; ++i) {
        client_info[i] = clients[i];
    }
}

// Get a pointer to the client information
Client* Bank::get_client_info() {
    return client_info;
}

// Deposit money into a client's account and return the updated balance
double Bank::deposit(int account_number, double amount) {
    for (int i = 0; i < num_clients; ++i) {
        if (client_info[i].bank_account == account_number) {
            client_info[i].balance += amount;
            return client_info[i].balance;
        }
    }
    return -1.0; // Account not found
}

// Withdraw money from a client's account and return the updated balance
std::string Bank::withdraw(int account_number, double amount) {
    for (int i = 0; i < num_clients; ++i) {
        if (client_info[i].bank_account == account_number) {
            if (client_info[i].balance >= amount) {
                client_info[i].balance -= amount;
                return "Withdrawal successful. New balance: $" + std::to_string(client_info[i].balance);
            } else {
                return "Insufficient balance.";
            }
        }
    }
    return "Account not found.";
}

// Save all changes into a txt file
void Bank::saving_info(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }

    file << num_clients << std::endl;
    for (int i = 0; i < num_clients; ++i) {
        file << client_info[i].client_name << " " << client_info[i].ssn << " "
             << client_info[i].bank_account << " " << client_info[i].balance << std::endl;
    }

    file.close();
}

// Find a client's information by account number and print it
void Bank::find_client(int account_number) {
    for (int i = 0; i < num_clients; ++i) {
        if (client_info[i].bank_account == account_number) {
            std::cout << "Client Information:" << std::endl;
            std::cout << "Name: " << client_info[i].client_name << std::endl;
            std::cout << "SSN: " << client_info[i].ssn << std::endl;
            std::cout << "Account Number: " << client_info[i].bank_account << std::endl;
            std::cout << "Balance: $" << client_info[i].balance << std::endl;
            return;
        }
    }
    std::cout << "Client is not in the list." << std::endl;
}
