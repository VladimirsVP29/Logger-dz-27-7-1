#pragma once

#include <string>
#include <fstream>
#include <shared_mutex>
#include "message.h"

class Logger
{
public:
	Logger(const std::string& fileLog);
	~Logger();

	void writeStr(const Message& message);
	std::string readRow(int number);

	void write(int numberTh, const Message& message);
	void read(int number);

private:
	std::string fileName_;
	std::fstream fileLog_;
	std::shared_mutex sharedMutex_;

};
