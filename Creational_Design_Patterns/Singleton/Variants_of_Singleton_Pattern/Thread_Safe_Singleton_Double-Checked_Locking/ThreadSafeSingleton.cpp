#include <iostream>
#include <mutex>

class ThreadSafeSingleton {
private:
    static ThreadSafeSingleton* instance;
    static std::mutex mutex;

    // Private constructor
    ThreadSafeSingleton() {
        std::cout << "ThreadSafeSingleton initialized." << std::endl;
    }

public:
    // Deleted copy constructor and assignment operator
    ThreadSafeSingleton(const ThreadSafeSingleton&) = delete;
    ThreadSafeSingleton& operator=(const ThreadSafeSingleton&) = delete;

    static ThreadSafeSingleton* getInstance() {
        if (instance == nullptr) {
            std::lock_guard<std::mutex> lock(mutex);
            if (instance == nullptr) {
                instance = new ThreadSafeSingleton();
            }
        }
        return instance;
    }

    void doSomething() {
        std::cout << "Doing something." << std::endl;
    }
};

// Initialize static members
ThreadSafeSingleton* ThreadSafeSingleton::instance = nullptr;
std::mutex ThreadSafeSingleton::mutex;

int main() {
    ThreadSafeSingleton::getInstance()->doSomething();
    return 0;
}
