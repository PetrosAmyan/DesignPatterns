#include <iostream>
#include <string>

class Logger {
private:
    Logger() {
        std::cout << "Constructor of Logger class\n";
    }

public:
    Logger(const Logger&) = delete;

    Logger& operator=(const Logger&) = delete;

    static Logger& getInstance() {
        static Logger obj;
        return obj;
    }

    void printInfo(const std::string& message) {
        std::cout << "info message is " << message << '\n';
    }
};

int main() {

    Logger& obj1 = Logger::getInstance();
    Logger& obj2 = Logger::getInstance();

    obj1.printInfo("Start of application");
    obj2.printInfo("User logged into app");

    std::cout << (&obj1 == &obj2) << '\n';

    return 0;
}