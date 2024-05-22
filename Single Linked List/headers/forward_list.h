#ifndef FORWARDLIST_H
#define FORWARDLIST_H
#include <initializer_list>
#include <memory>
#include <iostream>
#include <limits>

template<typename T, template <typename> class Allocator = std::allocator>
class forward_list 
{
public:
   using value_type = T;
   using size_type = size_t;
   using const_reference =	const value_type&;
   using reference =	value_type&;

private:
    struct Node {
        value_type val;
        typename Allocator<Node>::pointer next;
        template<typename... Args>
        Node(Args&&... args) : next(nullptr), val(std::forward<Args>(args)...) {}
    };

private:
    typename Allocator<Node>::pointer head;
    size_type size;

    Allocator<Node> allocator;
public:
   forward_list();
   forward_list(value_type num);
   forward_list(std::initializer_list<T> list);
   forward_list(const forward_list& other);
   forward_list(forward_list&& other);
   forward_list& operator=(const forward_list& other);
   forward_list& operator=(forward_list&& other) noexcept;
   ~forward_list();
public:
   // void assign( size_type count, const value_type& value );
   reference front();
   // iterator begin() noexcept;    
   // const_iterator begin() const noexcept;
   // const_iterator cbegin() const noexcept;
   // iterator end() noexcept;
   // const_iterator end() const noexcept;
   // const_iterator cend() const noexcept;
   bool empty() const noexcept;
   size_type max_size() const noexcept;
   void clear() noexcept;
   // iterator insert_after( const_iterator pos, const value_type& value );
   // iterator insert_after( const_iterator pos, value_type&& value );
   // iterator erase_after( const_iterator pos );
   // iterator erase_after( const_iterator first, const_iterator last );
   void push_front( const value_type& value );
   void push_front( value_type&& value );
   void pop_front();
   void resize( size_type count );
   void resize( size_type count, const value_type& value );
   // void swap( forward_list& other ) noexcept;
   // void merge( forward_list& other );
   // void merge( forward_list&& other );
   // void splice_after( const_iterator pos, forward_list& other );
   void remove( const value_type& value );
   // size_type remove( const value_type& value );
   // void reverse() noexcept;
   size_type unique();
   // void sort();
   void push_back(value_type elem);
   value_type first();
   void print();
};

#include "..\src\forward_list.hpp"
#endif //FORWARDLIST