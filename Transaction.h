#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <iostream>
#include <iomanip>

class Transaction {
public:
    std::string memberID; // ID of the member involved in the transaction
    std::string bookID;   // ID of the book involved in the transaction
    std::string date;     // Date of the transaction
    bool isBorrow;        // Whether the transaction is a borrow or return

    Transaction(); // Default constructor
    Transaction(const std::string& mID, const std::string& bID, const std::string& d, bool borrow);
    void displayTransaction() const; // Function to display transaction details
};

#endif // TRANSACTION_H
