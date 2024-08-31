#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include "Member.h"
#include "Transaction.h"

const int MAX_BOOKS = 100;     // Max number of books allowed
const int MAX_MEMBERS = 100;   // Max number of members allowed
const int MAX_TRANSACTIONS = 100; // Max number of transactions allowed

class Library {
public:
    Book books[MAX_BOOKS];           // Array to hold books
    Member members[MAX_MEMBERS];     // Array to hold members
    Transaction transactions[MAX_TRANSACTIONS]; // Array to hold transactions
    int bookCount;                   // Current count of books
    int memberCount;                 // Current count of members
    int transactionCount;            // Current count of transactions

    Library(); // Constructor to initialize the library
    void addBook(); // Function to add a new book
    void addMember(); // Function to add a new member
    void borrowBook(); // Function to borrow a book
    void returnBook(); // Function to return a book
    void viewBorrowingHistory(); // Function to view borrowing history
    void loadBooks(); // Load books from file
    void saveBooks(); // Save books to file
    void loadMembers(); // Load members from file
    void saveMembers(); // Save members to file
    void loadTransactions(); // Load transactions from file
    void saveTransactions(); // Save transactions to file
    std::string getCurrentDate(); // Get the current date
};

#endif // LIBRARY_H
