/*****************************
READ README.MD
- Best Regards; Macper

This source is a hundred percent programmed by Macper
Hashing system useful for storing passwords and mails of users.
You could although change it to whatever you would like to.
******************************/
#include <iostream>
#include <iomanip>
#include <functional>
#include <string>
#include <unordered_set>
//main code
struct userData1 {
    std::string userMail;
};

struct userData2 {
    std::string userPassword;
};

bool operator==(const userData1& lhs, const userData1& rhs) {
    return lhs.userMail == rhs.userMail;
}

bool operator==(const userData2& lhs, const userData2& rhs) {
    return lhs.userPassword == rhs.userPassword;
}

struct MyHash1
{
    std::size_t operator()(userData1 const& userData1) const noexcept
    {
        std::size_t h1 = std::hash<std::string>{}(userData1.userMail);
        return h1;
    }
};

struct MyHash2
{
    std::size_t operator()(userData2 const& userData2) const noexcept
    {
        std::size_t h2 = std::hash<std::string>{}(userData2.userPassword);
        return h2;
    }
};

//everything from here is not a part of the code, only testing the hashes (and user inputs)
int main()
{
    std::string mail;
    std::string password;
    std::cout << "Enter your Password: ";
    std::cin >> password;
    std::cout << "Enter your Mail: ";
    std::cin >> mail;

    userData1 obj1 = { mail };
    std::cout << "\nHashed Mail: (" << std::quoted(obj1.userMail) << ") = "
        << MyHash1{}(obj1) << "\n";

    userData2 obj2 = { password };
    std::cout << "\nHashed Password: (" << std::quoted(obj2.userPassword) << ") = "
        << MyHash2{}(obj2) << "\n";

    std::cout << "\nUpdates:\n- Hashing Password and Mail Seperatley\n- Solving Change Password issue\n- Removing std::unorganized users.\n";
} // End Code