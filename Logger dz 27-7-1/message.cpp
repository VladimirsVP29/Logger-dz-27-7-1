#include "message.h"

Message::Message(const std::string& sender, const std::string& receiver, const std::string& text) 
        : sender_(sender), receiver_(receiver), text_(text) {}

Message::Message(const Message& other) 
        : sender_(other.sender_), receiver_(other.receiver_), text_(other.text_) {}

Message& Message::operator = (const Message& other) {

    if (this == &other) {
        return *this;
    }

    sender_ = other.sender_;
    receiver_ = other.receiver_;
    text_ = other.text_;

    return *this;
}

std::fstream& operator >>(std::fstream& is, Message& obj) {
    is >> obj.sender_;
    is >> obj.receiver_;
    is.seekg(1, std::ios_base::cur);
    std::getline(is, obj.text_);
    return is;
}

std::ostream& operator <<(std::ostream& os, const Message& obj) {
    os << obj.sender_ << " ";
    os << obj.receiver_ << " ";
    os << obj.text_;
    return os;
}

const std::string& Message::getSender() const { return sender_; }
const std::string& Message::getReceiver() const { return receiver_; }
