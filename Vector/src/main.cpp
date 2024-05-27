#include <vector.h>
// #include "../headers/vector.h"
#include <iostream>
#include <string>
#include <cassert>
using namespace g3;

void print_vector(const vector<int>& vec) {
    std::cout << "Size: " << vec.size() << ", Capacity: " << vec.capacity() << ", Elements: ";
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Test default constructor
    vector<int> vec1;
    std::cout << "vec1 (default constructor): ";
    print_vector(vec1);

    // Test constructor with size and value
    vector<int> vec2(5, 10);
    std::cout << "vec2 (constructor with size and value): ";
    print_vector(vec2);

    // Test initializer list constructor
    vector<int> vec3 = {1, 2, 3, 4, 5};
    std::cout << "vec3 (initializer list constructor): ";
    print_vector(vec3);

    // Test copy constructor
    vector<int> vec4 = vec3;
    std::cout << "vec4 (copy constructor): ";
    print_vector(vec4);

    // Test move constructor
    vector<int> vec5 = std::move(vec4);
    std::cout << "vec5 (move constructor): ";
    print_vector(vec5);
    std::cout << "vec4 after move: ";
    print_vector(vec4);

    // Test assignment operator
    vector<int> vec6;
    vec6 = vec5;
    std::cout << "vec6 (assignment operator): ";
    print_vector(vec6);

    
}
