#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "Queue.h"

template<typename T, typename Container>
Queue<T, Container>::Queue() 
: m_arr(nullptr) 
{}

template<typename T, typename Container>
Queue<T, Container>::Queue(const Queue& other) 
{
    for (const auto& elem : this->m_arr)
    {
        other.m_arr.push_back(elem); 
    }
}
template<typename T, typename Container>
Queue<T, Container>& Queue<T, Container>::operator=(const Queue& other) 
{
    if (this != &other) 
    {
        Queue<T, Container> temp(other); 
        temp.swap(*this); 
    }
    return *this;
}


template<typename T, typename Container>
Queue<T, Container>::Queue(Queue&& other) 
{
    for (const auto& elem : this->m_arr)
    {
        other.m_arr.push_back(elem); 
    }
    other.m_arr.clear();
}

template<typename T, typename Container>
Queue<T, Container>& Queue<T, Container>::operator=(Queue&& other) 
{
    if (this != &other) {
        m_arr = std::move(other.m_arr);
        other.m_arr.clear();
    }
    return *this;
}

template<typename T, typename Container>
Queue<T, Container>::Queue(std::initializer_list<value_type> arr) 
 : m_arr(arr) 
 { 
        for (const auto& elem : arr) {
            m_arr.push_back(elem);
        }
}

template<typename T, typename Container>
void Queue<T, Container>::push(const value_type& elem)
{ 
       m_arr.push_back(elem);
}


template<typename T, typename Container>
void Queue<T, Container>::pop()
{ 
       m_arr.pop_back();
}

template<typename T, typename Container>
Queue<T,Container>::value_type& Queue<T, Container>::front()
{ 
       return m_arr.back();
}
template<typename T, typename Container>
Queue<T,Container>::size_type Queue<T, Container>::size()
{ 
       return m_arr.size();
}

template<typename T, typename Container>
void Queue<T, Container>::swap(const Queue& arr)
{ 
       m_arr.swap(arr.m_arr);
}

template<typename T, typename Container>
bool Queue<T, Container>::empty()
{ 
       return m_arr.empty();
}

template< class T, class Container >
bool operator!=(Queue<T,Container> ob1, Queue<T,Container> ob2) 
{
    return ob1 != ob2;
}

template< class T, class Container >
bool operator<(Queue<T,Container> ob1, Queue<T,Container> ob2) 
{
    return ob1 < ob2;
}

template< class T, class Container >
bool operator<=(Queue<T,Container> ob1, Queue<T,Container> ob2) 
{
    return ob1 <= ob2;
}

template< class T, class Container >
bool operator>(Queue<T,Container> ob1, Queue<T,Container> ob2) 
{
    return ob1 > ob2;
}

template< class T, class Container >
bool operator>=(Queue<T,Container> ob1, Queue<T,Container> ob2) 
{
    return ob1 >= ob2;
}

#endif //QUEUE_HPP