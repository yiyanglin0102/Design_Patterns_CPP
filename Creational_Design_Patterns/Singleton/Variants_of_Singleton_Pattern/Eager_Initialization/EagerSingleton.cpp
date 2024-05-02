#include <iostream>

class EagerSingleton {
private:
    static EagerSingleton instance;

    // Private constructor
    EagerSingleton() {
        std::cout << "EagerSingleton initialized." << std::endl;
    }

public:
    // Deleted copy constructor and assignment operator
    EagerSingleton(const EagerSingleton&) = delete;
    EagerSingleton& operator=(const EagerSingleton&) = delete;

    static EagerSingleton& getInstance() {
        return instance;
    }

    void doSomething() {
        std::cout << "Doing something." << std::endl;
    }
};

// Global static instance
EagerSingleton EagerSingleton::instance;

int main() {
    // The instance is already created and ready to use
    EagerSingleton::getInstance().doSomething();
    return 0;
}
