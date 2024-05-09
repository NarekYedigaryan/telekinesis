#include "../headers/queue.h"

using namespace g3;

template <typename T, typename Container>
queue<T,Container>::queue(const queue& rhv)
:m_arr(rhv.m_arr)
{}

template <typename T, typename Container>
queue<T,Container>::queue(queue&& rhv)
:m_arr(std::move(rhv.m_arr))
{}

template <typename T, typename Container>
queue<T,Container>::queue(std::initializer_list<value_type> init)
:m_arr(init)
{}

template <typename T, typename Container>
template <typename InputIt>
queue<T,Container>::queue(InputIt first, InputIt last)
:m_arr(first,last)
{}


template <typename T, typename Container>
const queue<T,Container>& queue<T,Container>::operator=(const queue& rhv)
{
   if(this != &rhv)
   {
      m_arr = rhv.m_arr;
   }
   return *this;
}

template <typename T, typename Container>
const queue<T,Container>& queue<T,Container>::operator=(queue&& rhv)
{
  if(this != &rhv)
   {
     m_arr = std::move(rhv.m_arr);
     
   }
   return *this;
}

template <typename T, typename Container>
typename queue<T,Container>::reference queue<T,Container>::front()
{
    return m_arr.front();
}

template <typename T, typename Container>
typename queue<T,Container>::const_reference queue<T,Container>::front() const
{
       return m_arr.front();
}

template <typename T, typename Container>
typename queue<T,Container>::reference queue<T,Container>::back()
{
    return m_arr.back();
}

template <typename T, typename Container>
typename queue<T,Container>::const_reference queue<T,Container>::back() const
{
       return m_arr.back();
}


template <typename T, typename Container>
bool queue<T,Container>::empty() const
{
    return m_arr.empty();
}

template <typename T, typename Container>
typename queue<T,Container>::size_type  queue<T,Container>::size() const
{
    return m_arr.size();
}

template <typename T, typename Container>
void  queue<T,Container>::push(const_reference val)
{
    return m_arr.push_back(val);
}

template <typename T, typename Container>
void  queue<T,Container>::pop()
{
    return m_arr.pop_back();
}

template <typename T, typename Container>
bool  queue<T,Container>::operator==(const queue& other)
{
    return this->m_arr == other.m_arr;
}

template <typename T, typename Container>
bool  queue<T,Container>::operator!=(const queue& other)
{
    return this->m_arr != other.m_arr;
}

template <typename T, typename Container>
bool  queue<T,Container>::operator<(const queue& other)
{
    return this->m_arr < other.m_arr;
}

template <typename T, typename Container>
bool  queue<T,Container>::operator<=(const queue& other)
{
    return this->m_arr <= other.m_arr;
}

template <typename T, typename Container>
bool  queue<T,Container>::operator>(const queue& other)
{
    return this->m_arr > other.m_arr;
}

template <typename T, typename Container>
bool  queue<T,Container>::operator>=(const queue& other)
{
    return this->m_arr >= other.m_arr;
}

