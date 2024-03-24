#ifndef VECTOR_HPP
#define VECTOR_HPP
#include "Vector.h"


//Ctors
template<typename T>
Vector<T>::Vector()
    : m_size()   
    , m_cap()   
    ,  m_arr(new T[m_cap]) 
{}


template<typename T>
Vector<T>::Vector(size_type new_size,T val)
:m_size(new_size)
,m_cap(new_size+5)
,m_arr(new T[m_cap])
{
   for (int i = 0; i < m_size; i++)
   {
      m_arr[i]=val;
   }
   
}



template<typename T>
Vector<T>::Vector(const Vector& other)
:m_size(other.m_size)
,m_cap(other.m_cap)
,m_arr(new T[other.m_cap])
{
    for (int i = 0; i < m_size; ++i) 
    {
        this->m_arr[i] = other.m_arr[i];
    }
}

template<typename T>
Vector<T>::Vector(Vector&& other) noexcept
:m_size(other.m_size)
,m_cap(other.m_cap)
,m_arr(new T[other.m_cap])
{
  
   other.m_size();
   other.m_cap();
   other.m_arr();
  
}
template<typename T>
Vector<T>::Vector(std::initializer_list<T> ilist) 
: m_size(ilist.size())
, m_cap(ilist.size()) 
, m_arr()
{
    this->reserve(ilist.size());
    for (const T& item : ilist) 
    {
        this->push_back(item);
    }
   
   
}
template<typename T>
Vector<T>::~Vector()
{
   delete[] m_arr;
}


// Operators
template<typename T>
constexpr Vector<T>& Vector<T>::operator=(Vector&& other) noexcept {
    if (this != &other) {
        delete[] m_arr;  

        m_arr = other.m_arr;
        m_size = other.m_size;
        m_cap = other.m_cap;

        other.m_arr();
        other.m_size();
        other.m_cap();
    }
    return *this;
}


template<typename T>
constexpr Vector<T>& Vector<T>::operator=( const Vector& other )
{
   if(this!=&other)
   {
      delete[] m_arr;
      m_cap=other.m_cap;
      m_size=other.m_size;
      m_arr=new T[m_cap];
   }
   return *this;
}


template<typename T>
constexpr T& Vector<T>::operator[]( size_type ind )
{
   if(ind<0 || ind>=m_size)
   {
      throw std::out_of_range("index");
   }
   else
   {
      return m_arr[ind];
   }
}


// Capacity
template<typename T>
constexpr bool Vector<T>::empty() const noexcept
{
   return m_size==0;
   
}

template<typename T>
constexpr size_type Vector<T>::size() const noexcept 
{
    return m_size;
}

template<typename T>
constexpr size_type Vector<T>::max_size() const noexcept
{
   return std::numeric_limits<T>::max();
}

template<typename T>
constexpr void Vector<T>::reserve( size_type new_cap )
{
   m_cap=new_cap-5;
   realloc();
}

template<typename T>
constexpr size_type Vector<T>::capacity() const noexcept
{
   return m_cap;
}

template<typename T>
constexpr void Vector<T>::shrink_to_fit() 
{
  reserve(m_size);
  m_cap=m_size;
}
//Modifiers
template<typename T>
constexpr void Vector<T>::clear() noexcept
{
   delete[] m_arr;
   m_size=0;
}

template<typename T>
constexpr void Vector<T>::insert(size_type pos,T val)
{
   if(m_size+1==m_cap ||m_size==m_cap)
   {
      realloc();
   }
    ++m_size;
   for (int i = m_size-1; i >pos; --i)
   {
      T tmp=m_arr[i];
      m_arr[i]=m_arr[i-1];
      m_arr[i-1]=tmp;
   }
   m_arr[pos]=val;
}

template<typename T>
constexpr void Vector<T>::erase(size_type first,size_type last)
{
   int ind=first;
    for (int i =last+1 ; i <m_size ; i++)
    {
      
      m_arr[ind++]=m_arr[i];
      
    }
    m_size=last-first+2;
}

template<typename T>
constexpr void Vector<T>::erase(size_type pos)
{
   for (int i = pos; i < m_size-1; i++)
   {
      T tmp=m_arr[i];
      m_arr[i]=m_arr[i+1];
      m_arr[i+1]=tmp;
   }
   --m_size;
}

template<typename T>
constexpr void Vector<T>::push_back(T&& val)
{
   if(m_cap==m_size)
   {
      realloc();
      m_arr[m_size]=val;
      ++m_size;
   }
   else
   {
      m_arr[m_size]=val;
      ++m_size;
   }
   
}

template<typename T>
constexpr void Vector<T>::push_back(const T& val)
{
   if(m_cap == m_size)
   {
      realloc();
   }
   m_arr[m_size] = val;
   ++m_size;
}

template<typename T>
constexpr void Vector<T>::pop_back()
{
   --m_size;
}

template<typename T>
void Vector<T>::resize( size_type count )
{
   if(count<=m_size)
   {
      m_size=count;
   }
   else
   {
       size_type originalSize = m_size;
        reserve(count);
        for (size_type i = originalSize; i < count; ++i)
        {
            m_arr[i] = 0;
        }
        m_size = count;
   }
   m_size=count;
}

template<typename T>
void Vector<T>::resize( size_type count , const T& value)
{
   if(count<=m_size)
   {
      m_size=count;
   }
   else
   {
       size_type originalSize = m_size;
        reserve(count);
        for (size_type i = originalSize; i < count; ++i)
        {
            m_arr[i] = value;
        }
        m_size = count;
   }
   m_size=count;
}

template<typename T>
constexpr void Vector<T>::swap(Vector<T>& other) noexcept
{
    if (this == &other)
        return; 

    int thisSize = this->size();
    int otherSize = other.size();
    int maxSize = std::max(thisSize, otherSize);
    for (int i = 0; i < maxSize; ++i)
    {
        if (i < thisSize && i < otherSize)
        {
            std::swap(this->m_arr[i], other.m_arr[i]);
        }
        else if (i < thisSize)
        {
            other.push_back(this->m_arr[i]);
        }
        else
        {
            this->push_back(other.m_arr[i]);
        }
    }
    this->resize(otherSize);
    other.resize(thisSize);
}



template<typename T>
void Vector<T>::realloc()
{
      m_cap+=5;
      T* tmp=new T[m_cap];
      for (int i = 0; i < m_size; i++)
      {
         tmp[i]=m_arr[i];
      }
      delete[] m_arr;
      m_arr=tmp;
      
}
template< template T >
bool Vector<T>::operator==( const std::vector<T>& ob1,const std::vector<T>& ob2)
{
   if(ob1.size()!=ob2.size())
   {
      return false;
   }
   for(int i=0;i<ob1.size();++i)
   {
      if(ob1[i]!=ob2[i])
      {
      return false;
      }
   }
   return true;
}

#endif //VECTOR_HPP