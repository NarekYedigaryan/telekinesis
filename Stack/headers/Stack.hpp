#ifndef STACK_HPP
#define STACK_HPP

#include "Stack.h"



template<typename T, typename Container>
Stack<T, Container>::Stack(const Stack& other) 
{
    for (const auto& elem : this->m_arr)
    {
        other.m_arr.push_back(elem); 
    }
}
template<typename T, typename Container>
Stack<T, Container>& Stack<T, Container>::operator=(const Stack& other) 
{
    if (this != &other) 
    {
        Stack<T, Container> temp(other); 
        temp.swap(*this); 
    }
    return *this;
}


template<typename T, typename Container>
Stack<T, Container>::Stack(Stack&& other) 
{
    for (const auto& elem : this->m_arr)
    {
        other.m_arr.push_back(elem); 
    }
    other.m_arr.clear();
}

template<typename T, typename Container>
Stack<T, Container>& Stack<T, Container>::operator=(Stack&& other) 
{
    if (this != &other) {
        m_arr = std::move(other.m_arr);
        other.m_arr.clear();
    }
    return *this;
}

template<typename T, typename Container>
Stack<T, Container>::Stack(std::initializer_list<value_type> arr) 
 : m_arr(arr) 
 { 
        for (const auto& elem : arr) {
            m_arr.push_back(elem);
        }
}

template<typename T, typename Container>
void Stack<T, Container>::push(const value_type& elem)
{ 
       m_arr.push_back(elem);
}


template<typename T, typename Container>
void Stack<T, Container>::pop()
{ 
       m_arr.pop_back();
}

template<typename T, typename Container>
Stack<T,Container>::value_type& Stack<T, Container>::top()
{ 
       return m_arr.back();
}
template<typename T, typename Container>
Stack<T,Container>::size_type Stack<T, Container>::size()
{ 
       return m_arr.size();
}

template<typename T, typename Container>
void Stack<T, Container>::swap(const Stack& arr)
{ 
       m_arr.swap(arr.m_arr);
}

template<typename T, typename Container>
bool Stack<T, Container>::empty()
{ 
       return m_arr.empty();
}

template< class T, class Container >
bool operator==(const Stack<T,Container>& ob1, const Stack<T,Container>& ob2) 
{
    return ob1.m_arr == ob2.m_arr;
}

template< class T, class Container >
bool operator!=(const Stack<T,Container>& ob1, const Stack<T,Container>& ob2) 
{
    return !(ob1.m_arr == ob2.m_arr);
}

template< class T, class Container >
bool operator<(const Stack<T,Container>& ob1, const Stack<T,Container>& ob2) 
{
    return ob1.m_arr < ob2.m_arr;
}

template< class T, class Container >
bool operator<=(const Stack<T,Container>& ob1, const Stack<T,Container>& ob2) 
{
    return ob1.m_arr <= ob2.m_arr;
}

template< class T, class Container >
bool operator>(const Stack<T,Container>& ob1, const Stack<T,Container>& ob2) 
{
    return ob1.m_arr > ob2.m_arr;
}

template< class T, class Container >
bool operator>=(const Stack<T,Container>& ob1, const Stack<T,Container>& ob2) 
{
    return ob1.m_arr >= ob2.m_arr;
}

#endif //STACK_HPP