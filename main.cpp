#include <iostream>
#include <string>
#include <fstream>
#include "client.h"
//inlcude all needed libraries


using namespace std;


int main()
 {
    ifstream inputFile("client_info.txt");
    if (!inputFile) {
        cout << "Error: Could not open the file." << endl;
        return 1;
    }

    int numClients;
    inputFile >> numClients;
    Bank bank(numClients);

    for (int i = 0; i < numClients; i++)
    {
        string name, ssn;
        double account, balance;
        inputFile >> name >> ssn >> account >> balance;
        bank.set_client_info(i, name, ssn, account, balance);
    }

    int choice;
    while (true)
     {
        cout << "Bank Management System" << endl;
        cout << "1. View Client Information" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Display All Clients" << endl;
        cout << "5. Find Client by Name" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
       
string ClientName;
        switch (choice)
         {
            case 1:
                int index;
                cout << "Enter client index (1-" << numClients << "): ";
                cin >> index;
                bank.get_client_info(index - 1);
                break;
            case 2:
                cout << "Enter client index (1-" << numClients << "): ";
                cin >> index;
                double depositAmount;
                cout << "Enter deposit amount: ";
                cin >> depositAmount;
                bank.deposit(index - 1, depositAmount);
                break;
            case 3:
                cout << "Enter client index (1-" << numClients << "): ";
                cin >> index;
                double withdrawAmount;
                cout << "Enter withdrawal amount: ";
                cin >> withdrawAmount;
                bank.withdraw(index - 1, withdrawAmount);
                break;
            case 4:
                bank.saving_info();
                break;
            case 5:
               
                cout << "Enter client name: ";
                cin.ignore();
                getline(cin, ClientName);
                bank.find_client(ClientName);
                break;
            case 6:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
