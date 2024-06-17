#pragma once

#include <string>
#include <fstream>

class User
{
public:
    User() = default;
    User(const std::string& name, const std::string& login, const std::string& pass);
    ~User() = default;

    User(const User& other);
    User& operator = (const User& other);
    bool operator == (const User& other);

    friend std::fstream& operator >> (std::fstream& is, User& obj);
    friend std::ostream& operator << (std::ostream& os, const User& obj);

    std::string getUserLogin() const;
    std::string getUserName() const;

private:
    std::string name_;
    std::string login_;
    std::string pass_;

};
