#include "../headers/stack.h"
using namespace g3;

template <typename T, typename Container>
stack<T,Container>::stack()
:m_arr()
{}

template <typename T, typename Container>
stack<T,Container>::stack(const stack& rhv)
:m_arr(rhv.m_arr)
{}

template <typename T, typename Container>
stack<T,Container>::stack(stack&& rhv)
:m_arr(std::move(rhv.m_arr))
{}

template <typename T, typename Container>
stack<T,Container>::stack(std::initializer_list<value_type> init)
:m_arr(init)
{}

template <typename T, typename Container>
template <typename InputIt>
stack<T,Container>::stack(InputIt first, InputIt last)
:m_arr(first,last)
{}


template <typename T, typename Container>
const stack<T,Container>& stack<T,Container>::operator=(const stack& rhv)
{
   if(this != &rhv)
   {
      m_arr = rhv.m_arr;
   }
   return *this;
}

template <typename T, typename Container>
const stack<T,Container>& stack<T,Container>::operator=(stack&& rhv)
{
  if(this != &rhv)
   {
     m_arr = std::move(rhv.m_arr);
     
   }
   return *this;
}

template <typename T, typename Container>
typename stack<T,Container>::reference stack<T,Container>::top()
{
    return m_arr.front();
}

template <typename T, typename Container>
typename stack<T,Container>::const_reference stack<T,Container>::top() const
{
    return m_arr.back();
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