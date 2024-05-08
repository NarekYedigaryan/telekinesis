#include "../headers/stack.h"
using namespace g3;

template <typename T, typename Container>
stack<T,Container>::stack()
:m_arr()
{}

template <typename T, typename Container>
stack<T,Container>::stack(const stack& rhv)
:m_arr()
{ 
     for (const auto& element : rhv.m_arr) 
     {
        m_arr.push_back(element); 
     }
}

template <typename T, typename Container>
stack<T,Container>::stack(stack&& rhv)
:m_arr(rhv.m_arr)
{}

template <typename T, typename Container>
stack<T,Container>::stack(std::initializer_list<value_type> init)
:m_arr()
{
  for (auto& i : init)
  {
    m_arr.push_back(i);
  }
}

template <typename T, typename Container>
template <typename InputIt>
stack<T,Container>::stack(InputIt first, InputIt last)
{
    for (InputIt it = first; it !=  last; it++)
    {
        m_arr.push_back(*it);
    }
}





template <typename T, typename Container>
const stack<T,Container>& stack<T,Container>::operator=(const stack& rhv)
{
   if(this != &rhv)
   {
      for (const auto& element : rhv.m_arr) 
     {
        m_arr.push_back(element); 
     }
   }
   return *this;
}

template <typename T, typename Container>
const stack<T,Container>& stack<T,Container>::operator=(stack&& rhv)
{
  if(this != &rhv)
   {
     m_arr = rhv.m_arr;
   }
   return *this;
}

template <typename T, typename Container>
typename stack<T,Container>::value_type* stack<T,Container>::begin()
{
    if (m_arr.empty()) 
        return nullptr;
    else
        return &m_arr[0]; 
}

template <typename T, typename Container>
typename stack<T,Container>::value_type* stack<T,Container>::end()
{
    if (m_arr.empty()) 
        return nullptr; 
    else
        return &m_arr[0] + m_arr.size()-1; 
}


template <typename T, typename Container>
typename stack<T,Container>::reference stack<T,Container>::top()
{
    return m_arr[m_arr.size()-1];
}

template <typename T, typename Container>
typename stack<T,Container>::const_reference stack<T,Container>::top() const
{
    return m_arr[m_arr.size()-1];
}


template <typename T, typename Container>
bool stack<T,Container>::empty() const
{
    return m_arr.empty();
}

template <typename T, typename Container>
typename stack<T,Container>::size_type  stack<T,Container>::size() const
{
    return m_arr.size();
}

template <typename T, typename Container>
void  stack<T,Container>::push(const_reference val)
{
    return m_arr.push_back(val);
}

template <typename T, typename Container>
void  stack<T,Container>::pop()
{
    return m_arr.pop_back();
}

template <typename T, typename Container>
bool  stack<T,Container>::operator==(const stack& other)
{
    return this->m_arr == other.m_arr;
}

template <typename T, typename Container>
bool  stack<T,Container>::operator!=(const stack& other)
{
    return this->m_arr != other.m_arr;
}

template <typename T, typename Container>
bool  stack<T,Container>::operator<(const stack& other)
{
    return this->m_arr < other.m_arr;
}

template <typename T, typename Container>
bool  stack<T,Container>::operator<=(const stack& other)
{
    return this->m_arr <= other.m_arr;
}

template <typename T, typename Container>
bool  stack<T,Container>::operator>(const stack& other)
{
    return this->m_arr > other.m_arr;
}

template <typename T, typename Container>
bool  stack<T,Container>::operator>=(const stack& other)
{
    return this->m_arr >= other.m_arr;
}