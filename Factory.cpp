#include <iostream>
#include <memory>
#include <string>

class Notification {
public:
    virtual void send(const std::string& message) = 0;

    virtual ~Notification() = default;
};


class EmailNotification : public Notification {
public:
    void send(const std::string& message) override {
        std::cout << "Sending the email`  " << message << '\n';
    }
};


class SMSNotification : public Notification {
public:
    void send(const std::string& message) override {
        std::cout << "Sending the sms`  " << message << '\n';
    }
};


class PushNotification : public Notification {
public:
    void send(const std::string& message) override {
        std::cout << "Sending the push notification: " << message << '\n';
    }
};

class NotificationFactory {
public:
    static std::unique_ptr<Notification> create(const std::string& type) {

        if (type == "email") {
            return std::make_unique<EmailNotification>();
        }

        else if (type == "sms") {
            return std::make_unique<SMSNotification>();
        }

        else if (type == "push") {
            return std::make_unique<PushNotification>();
        }

        return nullptr;
    }
};


int main() {

    auto notification = NotificationFactory::create("email");

    notification->send("Hello John");

    return 0;
}