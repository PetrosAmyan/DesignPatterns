#include <iostream>
#include <memory>

using namespace std;

class Button {
public:
    virtual void render() = 0;
    virtual ~Button() = default;
};


class Checkbox {
public:
    virtual void render() = 0;
    virtual ~Checkbox() = default;
};


class WindowsButton : public Button {
public:
    void render() override {
        cout << "Rendering button of window\n";
    }
};


class WindowsCheckbox : public Checkbox {
public:
    void render() override {
        cout << "Rendering checkbox of windows\n";
    }
};


class LinuxButton : public Button {
public:
    void render() override {
        cout << "Rendering button of Linux\n";
    }
};


class LinuxCheckbox : public Checkbox {
public:
    void render() override {
        cout << "Rendering checkbox of linux\n";
    }
};


class GUIFactory {
public:
    virtual unique_ptr<Button> createButton() = 0;

    virtual unique_ptr<Checkbox> createCheckbox() = 0;

    virtual ~GUIFactory() = default;
};


class WindowsFactory : public GUIFactory {
public:

    unique_ptr<Button> createButton() override {
        return make_unique<WindowsButton>();
    }

    unique_ptr<Checkbox> createCheckbox() override {
        return make_unique<WindowsCheckbox>();
    }
};


class LinuxFactory : public GUIFactory {
public:

    unique_ptr<Button> createButton() override {
        return make_unique<LinuxButton>();
    }

    unique_ptr<Checkbox> createCheckbox() override {
        return make_unique<LinuxCheckbox>();
    }
};


// Here is client code

class Application {
private:
    unique_ptr<Button> button;
    unique_ptr<Checkbox> checkbox;

public:

    Application(GUIFactory& factory) {

        button = factory.createButton();
        checkbox = factory.createCheckbox();
    }

    void render() {

        button->render();
        checkbox->render();
    }
};


int main() {

    WindowsFactory factory;

    // here application does not know that this is windows
    Application app(factory);

    app.render();

    return 0;
}