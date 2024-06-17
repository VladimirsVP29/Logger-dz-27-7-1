#include "user.h"

User::User(const std::string& name, const std::string& login, const std::string& pass)
     : name_(name), login_(login), pass_(pass) {}
User::User(const User& other) 
     : name_(other.name_), login_(other.login_), pass_(other.pass_) {}

User& User::operator = (const User& other) {

    if (this == &other) {
        return *this;
    }

    name_ = other.name_;
    login_ = other.login_;
    pass_ = other.pass_;

    return *this;
}

bool User::operator == (const User& other) {

    return (this->name_ == other.name_ && this->login_ == other.login_ && this->pass_ == other.pass_);
}

std::fstream& operator >> (std::fstream& is, User& obj)
{
    is >> obj.name_;
    is >> obj.login_;
    is >> obj.pass_;
    return is;
}

std::ostream& operator << (std::ostream& os, const User& obj) {
    os << obj.name_ << " ";
    os << obj.login_ << " ";
    os << obj.pass_;
    return os;
}

std::string User::getUserLogin() const { return login_; }
std::string User::getUserName() const { return name_; }
