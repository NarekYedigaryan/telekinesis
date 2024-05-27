#include <vector.h>
#include <iostream>
#include <string>
#include <cassert>

using namespace g3;

void test_vector()
{
    // Test constructor with initializer list
    vector<int> arr = {99, 1, 2, 9, 3, 4};
    assert(arr.size() == 6);
    assert(arr[0] == 99);

    // Test copy constructor
    vector<int> arr_copy(arr);
    assert(arr_copy.size() == arr.size());
    for (size_t i = 0; i < arr.size(); ++i)
    {
        assert(arr_copy[i] == arr[i]);
    }

    // Test move constructor
    vector<int> arr_move(std::move(arr_copy));
    assert(arr_copy.size() == 0);
    assert(arr_move.size() == arr.size());
    for (size_t i = 0; i < arr.size(); ++i)
    {
        assert(arr_move[i] == arr[i]);
    }

    // Test initializer list constructor
    vector<int> arr_init = {5, 10, 15};
    assert(arr_init.size() == 3);
    assert(arr_init[0] == 5);

    // Test size and default value constructor
    vector<int> arr_default(5, 42);
    assert(arr_default.size() == 5);
    for (size_t i = 0; i < 5; ++i)
    {
        assert(arr_default[i] == 42);
    }

    // Test range constructor
    vector<int> arr_range(arr_init.begin(), arr_init.end());
    assert(arr_range.size() == arr_init.size());
    for (size_t i = 0; i < arr_range.size(); ++i)
    {
        assert(arr_range[i] == arr_init[i]);
    }

    // Test assignment operator
    vector<int> arr_assign;
    arr_assign = arr_default;
    assert(arr_assign.size() == arr_default.size());
    for (size_t i = 0; i < arr_default.size(); ++i)
    {
        assert(arr_assign[i] == arr_default[i]);
    }

    // Test move assignment operator
    vector<int> arr_move_assign;
    arr_move_assign = std::move(arr_default);
    assert(arr_default.size() == 0);
    assert(arr_move_assign.size() == 5);
    for (size_t i = 0; i < 5; ++i)
    {
        assert(arr_move_assign[i] == 42);
    }

    // Test element access
    assert(arr_move_assign.at(0) == 42);
    arr_move_assign[0] = 24;
    assert(arr_move_assign.at(0) == 24);
    assert(arr_move_assign.front() == 24);
    assert(arr_move_assign.back() == 42);

    // Test iterators
    vector<int>::iterator it = arr_move_assign.begin();
    assert(*it == 24);
    ++it;
    assert(*it == 42);

    vector<int>::const_iterator cit = arr_move_assign.cbegin();
    assert(*cit == 24);
    ++cit;
    assert(*cit == 42);

    // Test capacity
    assert(!arr_move_assign.empty());
    assert(arr_move_assign.size() == 5);
    arr_move_assign.reserve(10);
    assert(arr_move_assign.capacity() >= 10);

    // Test clear
    arr_move_assign.clear();
    assert(arr_move_assign.empty());

   // Test insert
    vector<int> arr_insert = {1, 2, 3,4,5,6,7,8,9};
    arr_insert.insert(arr_insert.crend(),7);
    assert(arr_insert.size() == 4);
    assert(arr_insert[0] == 0);

   

    // Test erase
    arr_insert.erase(arr_insert.cbegin());
    assert(arr_insert.size() == 7);
    assert(arr_insert[0] == 5);

    arr_insert.erase(arr_insert.cbegin(), arr_insert.cbegin() + 2);
    assert(arr_insert.size() == 5);
    assert(arr_insert[0] == 6);

    // Test push_back and pop_back
    arr_insert.push_back(7);
    assert(arr_insert.size() == 6);
    assert(arr_insert.back() == 7);

    arr_insert.pop_back();
    assert(arr_insert.size() == 5);
    assert(arr_insert.back() == 4);

    // Test resize
    arr_insert.resize(3);
    assert(arr_insert.size() == 3);
    arr_insert.resize(5, 9);
    assert(arr_insert.size() == 5);
    assert(arr_insert[3] == 9);

    // Test comparison operators
    vector<int> arr_cmp1 = {1, 2, 3};
    vector<int> arr_cmp2 = {1, 2, 3};
    vector<int> arr_cmp3 = {4, 5, 6};

    assert(arr_cmp1 == arr_cmp2);
    assert(arr_cmp1 != arr_cmp3);
    assert(arr_cmp1 < arr_cmp3);
    assert(arr_cmp1 <= arr_cmp2);
    assert(arr_cmp3 > arr_cmp1);
    assert(arr_cmp3 >= arr_cmp2);

    std::cout << "All tests passed!" << std::endl;
}

int main()
{
    test_vector();
    
    return 0;
}
