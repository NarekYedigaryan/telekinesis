#ifndef QUEUE_H
#define QUEUE_H

#include <vector>
#include <initializer_list>



template<typename T,typename Container=std::vector<T>>
class Queue
{
private:
  using value_type=T;
  using size_type=size_t;
private:
  Container m_arr;
public:
  Queue();
  Queue(const Queue& other);
  Queue(Queue&& other);
  Queue& operator=(const Queue& other);
  Queue& operator=(Queue&& other);
  Queue(std::initializer_list<value_type> arr);
  ~Queue()=default;
  void push(const value_type& elem);
  void pop();
  value_type& front();
  size_type size();
  void swap(const Queue& arr);
  bool empty();

};

#include "Queue.hpp"
#endif //QUEUE_H