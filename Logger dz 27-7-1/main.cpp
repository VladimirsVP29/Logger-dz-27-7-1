#include <iostream>
#include <vector>
#include <thread>
#include "logger.h"
#include "user.h"
#include "message.h"

int main() {
    Logger logger("log.txt");
    size_t count = 30;

    std::vector<User> users;
    std::vector<Message> messages;
    std::vector<std::thread> writeThreads{};
    std::vector<std::thread> readThreads{};
    std::string text;

    std::string name = "", login = "", pass = "";

    for (size_t i = 0; i < count; i++) {
        name = "user" + std::to_string(i + 1);
        login = "log" + std::to_string(i + 1);
        pass = "pass" + std::to_string(i + 1);

        User user(name, login, pass);
        users.emplace_back(user);

        text = "Welcome to chat, " + name;
        Message mes("admin", name, text);
        messages.emplace_back(mes);
    }

    for (int i = 0; i < messages.size(); i++) {
        writeThreads.emplace_back(std::move(std::thread(&Logger::write, &logger, i + 1, std::ref(messages[i]))));
    }

    for (int i = 0; i < count; i += 2) {
        readThreads.emplace_back(std::move(std::thread(&Logger::read, &logger, i + 1)));
    }

    for (auto& t : writeThreads)
        t.join();
    for (auto& t : readThreads)
        t.join();

    return 0;
}
