#ifndef CLIENT_H
#define CLIENT_H

#include <string>

// Define the Client struct
struct Client {
    std::string client_name;
    std::string ssn;
    double bank_account;
    double balance;
};

// Define the Bank class
class Bank {
private:
    int num_clients;
    Client* client_info;

public:
    // Constructor
    Bank(const std::string& filename);

    // Deep Copy Constructor
    Bank(const Bank& other);

    // Destructor
    ~Bank();

    // Public member functions
    void set_client_info(const Client* clients, int num_clients);
    Client* get_client_info();
    double deposit(int account_number, double amount);
    std::string withdraw(int account_number, double amount);
    void saving_info(const std::string& filename);
    void find_client(int account_number);
};

#endif // CLIENT_H
