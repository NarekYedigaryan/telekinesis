#ifndef VECTOR_H
#define VECTOR_H
#include <cstddef>
#include <initializer_list>
#include <execution>
#include <limits>


template<typename T>
class Vector
{
private:
    using size_type = std::size_t;
    using value_type=T;
private:
    size_type m_size;
    size_type m_cap;
    T* m_arr;

    void realloc();

public:
    Vector();
    Vector(size_type new_size,T val);
    Vector(const Vector& other);
    Vector(Vector&& other) noexcept;
    Vector(std::initializer_list<T> ilist);
    ~Vector();

public:
    constexpr Vector& operator=( Vector&& other ) noexcept;    
    constexpr Vector& operator=( const Vector& other );
    constexpr T& operator[]( size_type ind );

public:
    constexpr bool empty() const noexcept;
    constexpr size_type size() const  noexcept;
    constexpr size_type max_size() const noexcept;
    constexpr void reserve( size_type new_cap );
    constexpr size_type capacity() const noexcept;
    constexpr void shrink_to_fit();

public:
    constexpr void clear() noexcept;
    constexpr void insert(size_type pos,T val);
    constexpr void erase(size_type first,size_type last);
    constexpr void erase(size_type pos);
    constexpr void push_back( const T& value );
    constexpr void push_back( T&& value );
    constexpr void pop_back();
    void resize( size_type count );
    void resize( size_type count, const T& value );
    constexpr void swap( Vector& other ) noexcept;  
};

                 
#include "..\src\Vector.hpp"

#endif //VECTOR_H