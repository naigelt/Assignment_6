#include <iostream>
#include <fstream>
#include <string>

class Writable {
public:
    virtual void writeState(const std::string& filename) = 0;
    virtual ~Writable() {}
};

class Readable {
public:
    virtual void readState(const std::string& filename) = 0;
    virtual ~Readable() {}
};

class Laptop : public Writable, public Readable {
private:
    std::string brand;
    int storage;
    double screenSize;

public:
    Laptop(const std::string& brand, int storage, double screenSize)
        : brand(brand), storage(storage), screenSize(screenSize) {}

    void writeState(const std::string& filename) override {
        std::ofstream file(filename);
        if (file) {
            file << brand << "\n" << storage << "\n" << screenSize;
        }
        file.close();
    }

    void readState(const std::string& filename) override {
        std::ifstream file(filename);
        if (file) {
            file >> brand >> storage >> screenSize;
        }
        file.close();
    }

    void printState() const {
        std::cout << "Brand: " << brand << ", Storage: " << storage << " GB, Screen Size: " << screenSize << " inches" << std::endl;
    }
};

int main() {
    Laptop myLaptop("Dell", 512, 15.6);

    myLaptop.writeState("laptop_state.txt");

    Laptop anotherLaptop("", 0, 0);
    anotherLaptop.readState("laptop_state.txt");

    std::cout << "Laptop state read from file:" << std::endl;
    anotherLaptop.printState();

    return 0;
}
