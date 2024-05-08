#ifndef __STACK__H__
#define __STACK__H__

#include <initializer_list>
#include <vector>

namespace g3
{

template <typename T, typename Container = std::vector<T>>
class stack
{
public:
    using container_type = Container;
    using value_type = T;
    using size_type = std::size_t;
    using reference = value_type&;
    using const_reference = const value_type&;

public:
   
    stack();
    stack(const stack& rhv);
    stack(stack&& rhv);
    stack(std::initializer_list<value_type> init);
    template <typename InputIt>
    stack(InputIt first, InputIt last);
    ~stack() = default;

    const stack& operator=(const stack<T, Container>& other);
    const stack& operator=(stack&& rhv);
    value_type* begin();
    value_type* end();
public:
    reference top();
    const_reference top() const;

    bool empty() const;
    size_type size() const;

    void push(const_reference val);
    void pop();

public:

    bool operator==(const stack& other);
    bool operator!=(const stack& other);
    bool operator<(const stack& other);
    bool operator<=(const stack& other);
    bool operator>(const stack& other);
    bool operator>=(const stack& other);


private:
    Container m_arr;
};


}

#include "../src/stack.hpp"
#endif