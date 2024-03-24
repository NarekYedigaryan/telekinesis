#ifndef STACK_H
#define STACK_H

#include <vector>
#include <initializer_list>



template<typename T,typename Container=std::vector<T>>
class Stack
{
private:
  using value_type=T;
  using size_type=size_t;
private:
  Container m_arr;
public:
  Stack()=default;
  Stack(const Stack& other);
  Stack(Stack&& other);
  Stack& operator=(const Stack& other);
  Stack& operator=(Stack&& other);
  Stack(std::initializer_list<value_type> arr);
  ~Stack()=default;
  void push(const value_type& elem);
  void pop();
  value_type& top();
  size_t size();
  void swap(const Stack& arr);
  bool empty();

};

#include "Stack.hpp"
#endif //STACK_H