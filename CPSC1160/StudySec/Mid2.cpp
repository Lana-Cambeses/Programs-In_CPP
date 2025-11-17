#include <iostream>
using namespace std;

/* class MyClass {
public:
    // 1) Overload operator new
    void* operator new(std::size_t size) {
        std::cout << "Allocating " << size << " bytes\n";
        return std::malloc(size);
    }

    // 2) Must also overload delete if you overload new
    void operator delete(void* ptr) {
        std::cout << "Freeing memory\n";
        std::free(ptr);
    }
}; */
