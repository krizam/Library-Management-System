#include "Member.h"

// Constructor to set default values
Member::Member() {}

// Display the member's information in a nice format
void Member::displayMember() const {
    std::cout << "| " << std::setw(10) << memberID
              << "| " << std::setw(20) << name
              << "| " << std::setw(25) << contact
              << " |" << std::endl;
}
