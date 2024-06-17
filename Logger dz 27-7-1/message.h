#pragma once

#include <string>
#include <fstream>

class Message
{
public:
	Message() = default;
	Message(const std::string& sender, const std::string& receiver, const std::string& text);
	~Message() = default;

	Message(const Message& other);
	Message& operator = (const Message& other);

	friend std::fstream& operator >>(std::fstream& is, Message& obj);
	friend std::ostream& operator <<(std::ostream& os, const Message& obj);

	const std::string& getSender() const;
	const std::string& getReceiver() const;

private:
	std::string sender_;
	std::string receiver_;
	std::string text_;

};
