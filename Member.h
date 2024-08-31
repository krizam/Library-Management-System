#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <iostream>
#include <iomanip>

class Member {
public:
    std::string memberID; // Unique identifier for the member
    std::string name;     // Name of the member
    std::string contact;  // Contact information

    Member(); // Constructor to initialize a member
    void displayMember() const; // Function to display member details
};

#endif // MEMBER_H
