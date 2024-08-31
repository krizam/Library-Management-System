#include <iostream>
#include "Library.h"

int main() {
    Library library; // Create a library instance

    int choice;
    do {
        // Display menu options
        std::cout << "\nWelcome to the Library Management System!\n";
        std::cout << "1. Add a new book\n";
        std::cout << "2. Add a new member\n";
        std::cout << "3. Borrow a book\n";
        std::cout << "4. Return a book\n";
        std::cout << "5. View a member's borrowing history\n";
        std::cout << "6. Exit\n";
        std::cout << "What's your choice? ";
        std::cin >> choice;

        // Handle the user's choice
        switch (choice) {
            case 1:
                library.addBook();
                library.saveBooks(); // Save the updated book list
                break;
            case 2:
                library.addMember();
                library.saveMembers(); // Save the updated member list
                break;
            case 3:
                library.borrowBook();
                library.saveBooks(); // Save the updated book list
                library.saveTransactions(); // Save the updated transaction list
                break;
            case 4:
                library.returnBook();
                library.saveBooks(); // Save the updated book list
                library.saveTransactions(); // Save the updated transaction list
                break;
            case 5:
                library.viewBorrowingHistory();
                break;
            case 6:
                std::cout << "Thanks for using the Library Management System! Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Oops! That's not a valid choice. Please try again." << std::endl;
        }
    } while (choice != 6);

    // Save everything before exiting
    library.saveBooks();
    library.saveMembers();
    library.saveTransactions();

    return 0; // End of the program
}
