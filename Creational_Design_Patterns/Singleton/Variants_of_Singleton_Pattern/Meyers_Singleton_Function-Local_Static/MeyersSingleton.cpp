#include <iostream>

class MeyersSingleton {
public:
    MeyersSingleton(const MeyersSingleton&) = delete;
    MeyersSingleton& operator=(const MeyersSingleton&) = delete;

    static MeyersSingleton& getInstance() {
        static MeyersSingleton instance;  // Guaranteed to be destroyed.
        return instance;
    }

    void doSomething() {
        std::cout << "Doing something." << std::endl;
    }
};

int main() {
    MeyersSingleton::getInstance().doSomething();
    return 0;
}
