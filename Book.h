#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
#include <iomanip>

class Book {
public:
    std::string bookID; // Unique identifier for the book
    std::string title;  // Title of the book
    std::string author; // Author of the book
    int year;          // Year of publication
    bool isBorrowed;   // Status of the book, whether it's borrowed or not

    Book(); // Constructor to initialize a book
    void displayBook() const; // Function to display book details
};

#endif // BOOK_H
