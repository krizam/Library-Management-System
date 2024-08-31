#include "Book.h"

// Constructor to set default values
Book::Book() : year(0), isBorrowed(false) {}

// Display the book's information in a nice format
void Book::displayBook() const {
    std::cout << "| " << std::setw(10) << bookID
              << "| " << std::setw(25) << title
              << "| " << std::setw(20) << author
              << "| " << std::setw(5) << year
              << "| " << std::setw(8) << (isBorrowed ? "Yes" : "No")
              << " |" << std::endl;
}
