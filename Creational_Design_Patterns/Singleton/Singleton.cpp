#include <iostream>
#include <mutex>

class Singleton {
private:
    // Private Static Instance pointer
    static Singleton* instance;
    // Private constructor to prevent instantiation
    Singleton() {}

    // Mutex for thread-safe implementation
    static std::mutex mutex;

public:
    // Delete the copy and move constructors and assign operators
    Singleton(Singleton const&) = delete;             // Copy construct
    Singleton(Singleton&&) = delete;                  // Move construct
    Singleton& operator=(Singleton const&) = delete;  // Copy assign
    Singleton& operator=(Singleton &&) = delete;      // Move assign

    // Static method for accessing the instance
    static Singleton* getInstance() {
        std::lock_guard<std::mutex> lock(mutex);
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }

    // Example method to demonstrate functionality
    void doSomething() {
        std::cout << "Doing something." << std::endl;
    }
};

// Initialize pointer to zero so that it can be initialized in first call to getInstance
Singleton* Singleton::instance = nullptr;
std::mutex Singleton::mutex;

int main() {
    // Get the Singleton instance and call a method
    Singleton::getInstance()->doSomething();
    return 0;
}
