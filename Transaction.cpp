#include "Transaction.h"

// Default constructor
Transaction::Transaction() : isBorrow(false) {}

// Constructor to initialize a transaction with details
Transaction::Transaction(const std::string& mID, const std::string& bID, const std::string& d, bool borrow)
    : memberID(mID), bookID(bID), date(d), isBorrow(borrow) {}

// Display the transaction details
void Transaction::displayTransaction() const {
    std::cout << "| " << std::setw(10) << memberID
              << "| " << std::setw(10) << bookID
              << "| " << std::setw(10) << date
              << "| " << std::setw(10) << (isBorrow ? "Borrow" : "Return")
              << " |" << std::endl;
}
