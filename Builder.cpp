#include <iostream>
#include <string>



class Computer {
private:
    std::string cpu;
    int ram;
    int storage;
    std::string gpu;
    bool wifi;
    bool bluetooth;

    Computer(
        const std::string& cpu,
        int ram,
        int storage,
        const std::string& gpu,
        bool wifi,
        bool bluetooth
    )
        : cpu(cpu),
          ram(ram),
          storage(storage),
          gpu(gpu),
          wifi(wifi),
          bluetooth(bluetooth)
    {}

public:

    void printInfo() const {
        std::cout << "CPU is ` " << cpu << '\n';
        std::cout << "RAM is ` " << ram << " GB\n";
        std::cout << "Storage is ` " << storage << " GB\n";
        std::cout << "GPU is `  " << gpu << '\n';
        std::cout << "Wi-Fi`  " << (wifi ? "Yes" : "No") << '\n';
        std::cout << "Bluetooth`  " << (bluetooth ? "Yes" : "No") << '\n';
    }

    class Builder {
    private:
        std::string cpu;
        int ram = 0;
        int storage = 0;
        std::string gpu = "None";
        bool wifi = false;
        bool bluetooth = false;

    public:

        Builder(const std::string& cpu)
            : cpu(cpu)
        {}

        Builder& setRAM(int ram) {
            this->ram = ram;
            return *this;
        }

        Builder& setStorage(int storage) {
            this->storage = storage;
            return *this;
        }

        Builder& setGPU(const std::string& gpu) {
            this->gpu = gpu;
            return *this;
        }

        Builder& setWiFi(bool wifi) {
            this->wifi = wifi;
            return *this;
        }

        Builder& setBluetooth(bool bluetooth) {
            this->bluetooth = bluetooth;
            return *this;
        }

        Computer build() {
            return Computer(
                cpu,
                ram,
                storage,
                gpu,
                wifi,
                bluetooth
            );
        }
    };
};

int main() {

    Computer game_PC =
        Computer::Builder("Intel I5")
            .setRAM(32)
            .setStorage(1000)
            .setGPU("R 4500")
            .setWiFi(true)
            .setBluetooth(true)
            .build();

    game_PC.printInfo();

    return 0;
}