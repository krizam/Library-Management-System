#include "Library.h"
#include <fstream>
#include <ctime>

// Constructor to set up the library
Library::Library() : bookCount(0), memberCount(0), transactionCount(0) {
    loadBooks(); // Load existing books
    loadMembers(); // Load existing members
    loadTransactions(); // Load existing transactions
}

// Load books from a text file
void Library::loadBooks() {
    std::ifstream inFile("books.txt");
    if (!inFile) return; // If file doesn't exist, just return

    Book book;
    while (inFile >> book.bookID >> std::ws && std::getline(inFile, book.title) &&
           std::getline(inFile, book.author) && inFile >> book.year >> book.isBorrowed) {
        books[bookCount++] = book; // Add book to the array
    }
    inFile.close(); // Close the file
}

// Save books to a text file
void Library::saveBooks() {
    std::ofstream outFile("books.txt");
    for (int i = 0; i < bookCount; ++i) {
        outFile << books[i].bookID << std::endl
                << books[i].title << std::endl
                << books[i].author << std::endl
                << books[i].year << std::endl
                << books[i].isBorrowed << std::endl;
    }
    outFile.close(); // Close the file
}

// Load members from a text file
void Library::loadMembers() {
    std::ifstream inFile("members.txt");
    if (!inFile) return; // If file doesn't exist, just return

    Member member;
    while (inFile >> member.memberID >> std::ws && std::getline(inFile, member.name) &&
           std::getline(inFile, member.contact)) {
        members[memberCount++] = member; // Add member to the array
    }
    inFile.close(); // Close the file
}

// Save members to a text file
void Library::saveMembers() {
    std::ofstream outFile("members.txt");
    for (int i = 0; i < memberCount; ++i) {
        outFile << members[i].memberID << std::endl
                << members[i].name << std::endl
                << members[i].contact << std::endl;
    }
    outFile.close(); // Close the file
}

// Load transactions from a text file
void Library::loadTransactions() {
    std::ifstream inFile("transactions.txt");
    if (!inFile) return; // If file doesn't exist, just return

    Transaction transaction;
    while (inFile >> transaction.memberID >> transaction.bookID >> transaction.date >> transaction.isBorrow) {
        transactions[transactionCount++] = transaction; // Add transaction to the array
    }
    inFile.close(); // Close the file
}

// Save transactions to a text file
void Library::saveTransactions() {
    std::ofstream outFile("transactions.txt");
    for (int i = 0; i < transactionCount; ++i) {
        outFile << transactions[i].memberID << std::endl
                << transactions[i].bookID << std::endl
                << transactions[i].date << std::endl
                << transactions[i].isBorrow << std::endl;
    }
    outFile.close(); // Close the file
}

// Add a new book to the library
void Library::addBook() {
    Book book;
    std::cout << "Enter Book ID: ";
    std::cin >> book.bookID;
    std::cout << "Enter Title: ";
    std::cin.ignore(); // Clear the input buffer
    std::getline(std::cin, book.title);
    std::cout << "Enter Author: ";
    std::getline(std::cin, book.author);
    std::cout << "Enter Year: ";
    std::cin >> book.year;
    book.isBorrowed = false; // Set the book as not borrowed
    books[bookCount++] = book; // Add the book to the array
    std::cout << "Book added successfully!" << std::endl;
}

// Add a new member to the library
void Library::addMember() {
    Member member;
    std::cout << "Enter Member ID: ";
    std::cin >> member.memberID;
    std::cout << "Enter Name: ";
    std::cin.ignore(); // Clear the input buffer
    std::getline(std::cin, member.name);
    std::cout << "Enter Contact: ";
    std::getline(std::cin, member.contact);
    members[memberCount++] = member; // Add the member to the array
    std::cout << "Member added successfully!" << std::endl;
}

// Borrow a book from the library
void Library::borrowBook() {
    std::string memberID, bookID;
    std::cout << "Enter Member ID: ";
    std::cin >> memberID;
    std::cout << "Enter Book ID: ";
    std::cin >> bookID;

    // Check if the book exists
    for (int i = 0; i < bookCount; ++i) {
        if (books[i].bookID == bookID) {
            // If the book is already borrowed, let the user know
            if (books[i].isBorrowed) {
                std::cout << "Oops! This book is already borrowed." << std::endl;
                return;
            }
            // Check if the member exists
            for (int j = 0; j < memberCount; ++j) {
                if (members[j].memberID == memberID) {
                    books[i].isBorrowed = true; // Mark the book as borrowed
                    Transaction transaction(memberID, bookID, getCurrentDate(), true);
                    transactions[transactionCount++] = transaction; // Record the transaction
                    std::cout << "Book borrowed successfully!" << std::endl;
                    return;
                }
            }
            std::cout << "Hmm, I can't find that member." << std::endl;
            return;
        }
    }
    std::cout << "Sorry, I couldn't find that book." << std::endl;
}

// Return a book to the library
void Library::returnBook() {
    std::string memberID, bookID;
    std::cout << "Enter Member ID: ";
    std::cin >> memberID;
    std::cout << "Enter Book ID: ";
    std::cin >> bookID;

    // Check if the book exists
    for (int i = 0; i < bookCount; ++i) {
        if (books[i].bookID == bookID) {
            // If the book is not borrowed, let the user know
            if (!books[i].isBorrowed) {
                std::cout << "This book was never borrowed." << std::endl;
                return;
            }
            books[i].isBorrowed = false; // Mark the book as returned
            Transaction transaction(memberID, bookID, getCurrentDate(), false);
            transactions[transactionCount++] = transaction; // Record the transaction
            std::cout << "Book returned successfully!" << std::endl;
            return;
        }
    }
    std::cout << "Sorry, I couldn't find that book." << std::endl;
}

// View the borrowing history for a member
void Library::viewBorrowingHistory() {
    std::string memberID;
    std::cout << "Enter Member ID: ";
    std::cin >> memberID;
    std::cout << "\nBorrowing History for Member ID " << memberID << ":\n";
    std::cout << "-----------------------------------------------------\n";
    std::cout << "| " << std::setw(10) << "Member ID"
              << "| " << std::setw(10) << "Book ID"
              << "| " << std::setw(10) << "Date"
              << "| " << std::setw(10) << "Type"
              << " |\n";
    std::cout << "-----------------------------------------------------\n";
    
    // Display all transactions for the specified member
    for (int i = 0; i < transactionCount; ++i) {
        if (transactions[i].memberID == memberID) {
            transactions[i].displayTransaction();
        }
    }
    std::cout << "-----------------------------------------------------\n";
}

// Get the current date in a readable format
std::string Library::getCurrentDate() {
    time_t t = time(0); // Get the current time
    struct tm* now = localtime(&t); // Convert to local time
    char buf[80];
    strftime(buf, sizeof(buf), "%Y-%m-%d", now); // Format the date
    return std::string(buf); // Return as a string
}
