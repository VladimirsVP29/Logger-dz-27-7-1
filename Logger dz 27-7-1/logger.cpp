#include <iostream>
#include <chrono>
#include "logger.h"

Logger::Logger(const std::string& fileName) : fileName_(fileName)
{
	fileLog_.open(fileName, std::ios::in | std::ios::out | std::ios::trunc);
	if (!fileLog_.is_open())
		std::cout << "ERROR: log file " << fileName << " did't opent\n";
}

Logger::~Logger()
{
	fileLog_.close();
}

void Logger::writeStr(const Message& message)
{
	sharedMutex_.lock();
	fileLog_.seekp(0, std::ios::end);
	fileLog_ << message << "\n";
	sharedMutex_.unlock();
}

std::string Logger::readRow(int number)
{
	std::lock_guard<std::shared_mutex> lock(sharedMutex_);
	fileLog_.seekg(0, std::ios::beg);
	std::string row = "";
	int count = 1;
	while (!fileLog_.eof())
	{
		getline(fileLog_, row);
		if (count == number) {
			return row;
		}
		count++;
	}
	return "";
}

void Logger::write(int numberTh, const Message& message) {
	writeStr(message);
	sharedMutex_.lock();
	std::cout << numberTh << " write thread :\t" << message << "\n";
	sharedMutex_.unlock();
}

void Logger::read(int number) {
	std::this_thread::sleep_for(std::chrono::milliseconds(5));
	std::string row = readRow(number);

	if (!row.empty()) {
		sharedMutex_.lock();
		std::cout << "read thread: " << number << " row - \t" << row << "\n";
		sharedMutex_.unlock();
	}
	else {
		sharedMutex_.lock();
		std::cout << "read thread: " << number << " row not found\n";
		sharedMutex_.unlock();
	}
}
