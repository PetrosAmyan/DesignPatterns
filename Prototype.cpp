#include <iostream>
#include <memory>
#include <string>


class Character {
private:
    std::string name;
    int health;
    std::string weapon;

public:
    Character(std::string name, int health, std::string weapon)
        : name(name), health(health), weapon(weapon) {}

    std::unique_ptr<Character> clone() const {
        return std::make_unique<Character>(*this);
    }

    void set_name(const std::string& newName) {
        name = newName;
    }

    void set_weapon(const std::string& newWeapon) {
        weapon = newWeapon;
    }

    void printInfo() const {
        std::cout << "Name of character is " << name << '\n';
        std::cout << "Health of character is " << health << '\n';
        std::cout << "Weapon of character is " << weapon << '\n';
    }
};

int main() {

		auto warrior = std::make_unique<Character>("Warrior", 100, "Sword");

    std::cout << "Original character:\n";
    warrior->printInfo();

    auto warrior2 = warrior->clone();

    warrior2->set_name("Warrior Clone");
    warrior2->set_weapon("Axe");

    std::cout << "Cloned character:\n";
    warrior2->printInfo();

    std::cout << "Original after cloning:\n";
    warrior->printInfo();

    return 0;
}