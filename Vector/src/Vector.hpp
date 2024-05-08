#include "../headers/vector.h"

using namespace g3;

template <typename T, typename Allocator>
vector<T, Allocator>::vector() 
: size_()
, capacity_()
, arr_() 
{}

template <typename T, typename Allocator>
vector<T, Allocator>::vector(const vector& rhv) 
: size_(rhv.size())
, capacity_(rhv.capacity())
, arr_(allocator_type().allocate(capacity_)) 
{
    for(size_type i = 0 ; i<size_ ; ++i)
    {
        this->arr_[i] = rhv.arr_[i];
    }
}

template <typename T, typename Allocator>
vector<T, Allocator>::vector(vector&& rhv)
:size_(rhv.size())
,capacity_(rhv.capacity())
,arr_(rhv.arr_)
{
}
    
template <typename T, typename Allocator>
vector<T, Allocator>::vector(std::initializer_list<value_type> init)
:size_(0)
,capacity_(init.size())
,arr_(allocator_type().allocate(capacity_))
{
  for (const T& i : init)
  {
    push_back(i);
  }
  
}

template <typename T, typename Allocator>
vector<T, Allocator>::vector(size_type size, const_reference val)
    : size_(size), 
      capacity_(size), 
      arr_(allocator_type().allocate(capacity_)) 
{
    for (size_type i = 0; i < size_; ++i) {
        arr_[i] = val;
    }
}

template <typename T, typename Allocator>
template <typename InputIt>
vector<T, Allocator>::vector(InputIt first, InputIt last)
:size_()
,capacity_()
,arr_ (nullptr)
{

    for (InputIt it = first; it != last; ++it) {
        ++size_;
    }

    capacity_ = size_;
    arr_ = allocator_type().allocate(capacity_);

    size_type i = 0;
    for (InputIt it = first; it != last; ++it) 
    {
        arr_[i++] = *it;
    }
}

    
template <typename T, typename Allocator>
vector<T, Allocator>::~vector()
{
   clear();
}

template <typename T, typename Allocator>
const vector<T, Allocator>& vector<T, Allocator>::operator=(const vector& rhv) 
{
  if(this!=&rhv)
  {
    size_=rhv.size();
    capacity_=rhv.capacity();
    arr_=allocator_type().allocate(capacity_) ;
    for(size_type i = 0 ; i<size_ ; ++i)
    {
        this->arr_[i] = rhv.arr_[i];
    }
  }
    return *this;
}


template <typename T, typename Allocator>
const vector<T, Allocator>& vector<T, Allocator>::operator=(vector&& rhv)
{
  if(this!=&rhv)
  {
    size_=rhv.size();
    capacity_=rhv.capacity();
    arr_=rhv.arr_ ;
    
  }
    return *this;
}
  
template <typename T, typename Allocator>
typename vector<T, Allocator>::allocator_type vector<T, Allocator>::get_allocator() 
{
    return allocator_type();
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::reference vector<T, Allocator>::at(size_type pos)
 {
   if(pos>=size_ || pos<0)
   {
     throw std::out_of_range("Not correct position ");
   }
  std::cout<<"non const";

   return arr_[pos];
 }

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_reference vector<T, Allocator>::at(size_type pos) const
 {
   if(pos>=size_ || pos<0)
   {
     throw std::out_of_range("Not correct position ");
   }
  std::cout<<"const";

   return arr_[pos];

 } 


template <typename T, typename Allocator>
typename vector<T, Allocator>::reference vector<T, Allocator>::operator[](size_type pos)
{
   return arr_[pos];
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_reference vector<T, Allocator>::operator[](size_type pos) const
{
   return arr_[pos];
} 
     
template <typename T, typename Allocator>
typename vector<T, Allocator>::reference vector<T, Allocator>::front()
{
   return arr_[0];
} 

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_reference vector<T, Allocator>::front() const
{
   return arr_[0];
} 

template <typename T, typename Allocator>
typename vector<T, Allocator>::reference vector<T, Allocator>::back()
{
   return arr_[size_-1];
} 

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_reference vector<T, Allocator>::back() const
{
   return arr_[size_-1];
} 

template <typename T, typename Allocator>
typename vector<T, Allocator>::iterator vector<T, Allocator>::begin() 
{
    return iterator(arr_);
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_iterator vector<T, Allocator>::begin() const 
{
    return const_iterator(arr_);
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_iterator vector<T, Allocator>::cbegin() const 
{
    return const_iterator(arr_);
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::iterator vector<T, Allocator>::end() 
{
    return iterator(arr_ + size_);
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_iterator vector<T, Allocator>::end() const 
{
    return const_iterator(arr_ + size_);
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_iterator vector<T, Allocator>::cend() const 
{
    return const_iterator(arr_ + size_);
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::iterator vector<T, Allocator>::rbegin() 
{
    return iterator(arr_ + size_ - 1);
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_iterator vector<T, Allocator>::rbegin() const 
{
    return const_iterator(arr_ + size_ - 1);
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_iterator vector<T, Allocator>::crbegin() const 
{
    return const_iterator(arr_ + size_ - 1);
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::iterator vector<T, Allocator>::rend() 
{
    return iterator(arr_ - 1); 
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_iterator vector<T, Allocator>::rend() const 
{
    return const_iterator(arr_ - 1);
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_iterator vector<T, Allocator>::crend() const 
{
    return const_iterator(arr_ - 1); 
}

template <typename T, typename Allocator>
bool  vector<T, Allocator>::empty() const
{
return size_==0;
}
   

template <typename T, typename Allocator>
typename vector<T, Allocator>::size_type vector<T, Allocator>::size() const
{
    return size_;
}    
     
template <typename T, typename Allocator>
typename vector<T, Allocator>::size_type vector<T, Allocator>::capacity() const
{
    return capacity_;
}

template <typename T, typename Allocator>
void vector<T, Allocator>::reserve(size_type new_cap) 
{
    if (new_cap <= capacity_) {
        return;
    }

    T* tmp = allocator_type().allocate(new_cap);
    for (size_type i = 0; i < size_; ++i) {
        tmp[i] = std::move(arr_[i]); 
    }
    allocator_type().deallocate(arr_, capacity_);
    arr_ = tmp;
    capacity_ = new_cap;
}

template <typename T, typename Allocator>
void vector<T, Allocator>::clear() noexcept
{
  delete[] arr_;
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::iterator vector<T, Allocator>::insert(const_iterator pos, const_reference val) 
{
    size_type index = pos - begin(); 
    if (size_ >= capacity_) 
    {
        reserve(size_ + 1); 
    }
    std::move_backward(arr_ + index, arr_ + size_, arr_ + size_ + 1);
    arr_[index] = val; 
    ++size_;
    return begin() + index;
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::iterator vector<T, Allocator>::insert(const_iterator pos, size_type count, const_reference val) 
{
    size_type index = pos - begin(); 
    if (size_ + count > capacity_) {
        reserve(size_ + count); 
    }
    std::move_backward(arr_ + index, arr_ + size_, arr_ + size_ + count);
    for (size_type i = 0; i < count; ++i) {
        arr_[index + i] = val;
    }
    size_ += count; 
    return begin() + index; 
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::iterator vector<T, Allocator>::insert(const_iterator pos, std::initializer_list<value_type> init) 
{
    size_type index = pos - begin(); 
    size_type count = init.size();
    if (size_ + count > capacity_) {
        reserve(size_ + count); 
    }
    std::move_backward(arr_ + index, arr_ + size_, arr_ + size_ + count);
    std::copy(init.begin(), init.end(), arr_ + index);
    size_ += count; 
    return begin() + index;
}

template <typename T, typename Allocator>
template <typename InputIt>
typename vector<T, Allocator>::iterator vector<T, Allocator>::insert(const_iterator pos, InputIt first, InputIt last) 
{
    size_type index = pos - begin(); 
    size_type count = std::distance(first, last);
    if (size_ + count > capacity_) {
        reserve(size_ + count);
    }
    std::move_backward(arr_ + index, arr_ + size_, arr_ + size_ + count);
    std::copy(first, last, arr_ + index);
    size_ += count; 
    return begin() + index; 
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::iterator vector<T, Allocator>::erase(const_iterator pos) 
{
    size_type index = pos - begin(); 
    std::move(arr_ + index + 1, arr_ + size_, arr_ + index);
    --size_; 
    return begin() + index; 
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::iterator vector<T, Allocator>::erase(const_iterator first, const_iterator last) {
    size_type start_index = first - begin(); 
    size_type count = last - first; 
    std::move(arr_ + start_index + count, arr_ + size_, arr_ + start_index);
    size_ -= count;
    return begin() + start_index;
}

template <typename T, typename Allocator>
void vector<T, Allocator>:: push_back(const_reference val)
{
   if(size_==capacity_)
   {
     reserve(capacity_*2);
   }    
   arr_[size_]=val;
   ++size_;
}
    
template <typename T, typename Allocator>
void vector<T, Allocator>::pop_back() 
{
    if (size_ > 0) {
        --size_; 
        arr_[size_].~T(); 
    }
}

template <typename T, typename Allocator>
void vector<T, Allocator>::resize(size_type new_size, const_reference val) 
{
    if (new_size < size_) {
        size_ = new_size;
    } else if (new_size > size_) {
        if (new_size > capacity_) {
            reserve(new_size); 
        }
        for (size_type i = size_; i < new_size; ++i) {
            arr_[i] = val;
        }
        size_ = new_size; 
    }
}

template <typename T, typename Allocator>
bool vector<T, Allocator>::operator==(const vector& other) const
{
  if(this->size() != other.size())
  {
    return false;
  }
  for (size_t i = 0; i < this->size(); i++)
  {
    if(this->arr_[i] != other.arr_[i])
    {
      return false;
    }
  }
  return true;
}

template <typename T, typename Allocator>
bool vector<T, Allocator>::operator!=(const vector& other) const 
{
    if (size_ != other.size_) {
        return true;
    }
    for (size_type i = 0; i < size_; ++i) {
        if (arr_[i] != other.arr_[i]) {
            return true;
        }
    }
    return false;
}

template <typename T, typename Allocator>
bool vector<T, Allocator>::operator<(const vector& other) const 
{
    size_type min_size = std::min(size_, other.size_);
    for (size_type i = 0; i < min_size; ++i) 
    {
        if (arr_[i] < other.arr_[i]) 
        {
            return true;  
        } 
        else if (arr_[i] > other.arr_[i]) 
        {
            return false;
        }
    }

    return size_ < other.size_;
}

template <typename T, typename Allocator>
bool vector<T, Allocator>::operator<=(const vector& other) const 
{
    return (*this < other) || (*this == other);
}

template <typename T, typename Allocator>
bool vector<T, Allocator>::operator>(const vector& other) const 
{
    return !(*this <= other);
}

template <typename T, typename Allocator>
bool vector<T, Allocator>::operator>=(const vector& other) const 
{
    return (*this > other) || (*this == other);
}

template <typename T, typename Allocator>
int vector<T, Allocator>::compare(const vector& other) const 
{
    if (size_ < other.size_) return -1;
    if (size_ > other.size_) return 1;

    for (size_type i = 0; i < size_; ++i) {
        if (arr_[i] < other.arr_[i]) return -1;
        if (arr_[i] > other.arr_[i]) return 1;
    }

    return 0;
}

template <typename T, typename Allocator>
vector<T, Allocator>::const_iterator::const_iterator(pointer ptr)
    : ptr(ptr) {}

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_iterator
vector<T, Allocator>::const_iterator::operator+(size_type n) const {
    return const_iterator(ptr + n);
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_iterator
vector<T, Allocator>::const_iterator::operator-(size_type n) const {
    return const_iterator(ptr - n);
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_iterator&
vector<T, Allocator>::const_iterator::operator++() {
    ++ptr;
    return *this;
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_iterator
vector<T, Allocator>::const_iterator::operator++(int) {
    const_iterator old = *this;
    ++ptr;
    return old;
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_iterator&
vector<T, Allocator>::const_iterator::operator--() {
    --ptr;
    return *this;
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_iterator
vector<T, Allocator>::const_iterator::operator--(int) {
    const_iterator old = *this;
    --ptr;
    return old;
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_reference
vector<T, Allocator>::const_iterator::operator*() const {
    return *ptr;
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_pointer
vector<T, Allocator>::const_iterator::operator->() const {
    return ptr;
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_reference
vector<T, Allocator>::const_iterator::operator[](size_type pos) const {
    return *(ptr + pos);
}

template <typename T, typename Allocator>
bool vector<T, Allocator>::const_iterator::operator==(
    const const_iterator& other) const {
    return ptr == other.ptr;
}

template <typename T, typename Allocator>
bool vector<T, Allocator>::const_iterator::operator!=(
    const const_iterator& other) const {
    return !(*this == other);
}

template <typename T, typename Allocator>
bool vector<T, Allocator>::const_iterator::operator<(
    const const_iterator& other) const {
    return ptr < other.ptr;
}

template <typename T, typename Allocator>
bool vector<T, Allocator>::const_iterator::operator<=(
    const const_iterator& other) const {
    return ptr <= other.ptr;
}

template <typename T, typename Allocator>
bool vector<T, Allocator>::const_iterator::operator>(
    const const_iterator& other) const {
    return ptr > other.ptr;
}

template <typename T, typename Allocator>
bool vector<T, Allocator>::const_iterator::operator>=(
    const const_iterator& other) const {
    return ptr >= other.ptr;
}

template <typename T, typename Allocator>
vector<T, Allocator>::iterator::iterator(pointer ptr)
    : const_iterator(ptr) {}

template <typename T, typename Allocator>
typename vector<T, Allocator>::iterator
vector<T, Allocator>::iterator::operator+(size_type n) const {
    return iterator(const_iterator::ptr + n);
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::iterator
vector<T, Allocator>::iterator::operator-(size_type n) const {
    return iterator(const_iterator::ptr - n);
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::iterator&
vector<T, Allocator>::iterator::operator++() {
    ++const_iterator::ptr;
    return *this;
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::iterator
vector<T, Allocator>::iterator::operator++(int) {
    iterator old = *this;
    ++const_iterator::ptr;
    return old;
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::iterator&
vector<T, Allocator>::iterator::operator--() {
    --const_iterator::ptr;
    return *this;
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::iterator
vector<T, Allocator>::iterator::operator--(int) {
    iterator old = *this;
    --const_iterator::ptr;
    return old;
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::reference
vector<T, Allocator>::iterator::operator*() {
    return *const_iterator::ptr;
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::pointer
vector<T, Allocator>::iterator::operator->() {
    return const_iterator::ptr;
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::reference
vector<T, Allocator>::iterator::operator[](size_type pos) const {
    return *(const_iterator::ptr + pos);
}

template <typename T, typename Allocator>
vector<T, Allocator>::const_reverse_iterator::const_reverse_iterator(pointer ptr)
    : ptr(ptr) {}

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_reverse_iterator
vector<T, Allocator>::const_reverse_iterator::operator+(size_type n) const {
    return const_reverse_iterator(ptr - n);
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_reverse_iterator
vector<T, Allocator>::const_reverse_iterator::operator-(size_type n) const {
    return const_reverse_iterator(ptr + n);
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_reverse_iterator&
vector<T, Allocator>::const_reverse_iterator::operator++() {
    --ptr;
    return *this;
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_reverse_iterator
vector<T, Allocator>::const_reverse_iterator::operator++(int) {
    const_reverse_iterator old = *this;
    --ptr;
    return old;
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_reverse_iterator&
vector<T, Allocator>::const_reverse_iterator::operator--() {
    ++ptr;
    return *this;
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_reverse_iterator
vector<T, Allocator>::const_reverse_iterator::operator--(int) {
    const_reverse_iterator old = *this;
    ++ptr;
    return old;
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_reference
vector<T, Allocator>::const_reverse_iterator::operator*() const {
    return *ptr;
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_pointer
vector<T, Allocator>::const_reverse_iterator::operator->() const {
    return ptr;
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_reference
vector<T, Allocator>::const_reverse_iterator::operator[](size_type pos) const {
    return *(ptr - pos);
}

template <typename T, typename Allocator>
bool vector<T, Allocator>::const_reverse_iterator::operator==(
    const const_reverse_iterator& other) const {
    return ptr == other.ptr;
}

template <typename T, typename Allocator>
bool vector<T, Allocator>::const_reverse_iterator::operator!=(
    const const_reverse_iterator& other) const {
    return !(*this == other);
}

template <typename T, typename Allocator>
bool vector<T, Allocator>::const_reverse_iterator::operator<(
    const const_reverse_iterator& other) const {
    return ptr > other.ptr;
}

template <typename T, typename Allocator>
bool vector<T, Allocator>::const_reverse_iterator::operator<=(
    const const_reverse_iterator& other) const {
    return ptr >= other.ptr;
}

template <typename T, typename Allocator>
bool vector<T, Allocator>::const_reverse_iterator::operator>(
    const const_reverse_iterator& other) const {
    return ptr < other.ptr;
}

template <typename T, typename Allocator>
bool vector<T, Allocator>::const_reverse_iterator::operator>=(
    const const_reverse_iterator& other) const {
    return ptr <= other.ptr;
}

template <typename T, typename Allocator>
vector<T, Allocator>::reverse_iterator::reverse_iterator(pointer ptr)
    : const_reverse_iterator(ptr) {}

template <typename T, typename Allocator>
typename vector<T, Allocator>::reverse_iterator
vector<T, Allocator>::reverse_iterator::operator+(size_type n) const {
    return reverse_iterator(const_reverse_iterator::ptr - n);
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::reverse_iterator
vector<T, Allocator>::reverse_iterator::operator-(size_type n) const {
    return reverse_iterator(const_reverse_iterator::ptr + n);
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::reverse_iterator&
vector<T, Allocator>::reverse_iterator::operator++() {
    --const_reverse_iterator::ptr;
    return *this;
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::reverse_iterator
vector<T, Allocator>::reverse_iterator::operator++(int) {
    reverse_iterator old = *this;
    --const_reverse_iterator::ptr;
    return old;
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::reverse_iterator&
vector<T, Allocator>::reverse_iterator::operator--() {
    ++const_reverse_iterator::ptr;
    return *this;
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::reverse_iterator
vector<T, Allocator>::reverse_iterator::operator--(int) {
    reverse_iterator old = *this;
    ++const_reverse_iterator::ptr;
    return old;
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::reference
vector<T, Allocator>::reverse_iterator::operator*() {
    return *const_reverse_iterator::ptr;
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::pointer
vector<T, Allocator>::reverse_iterator::operator->() {
    return const_reverse_iterator::ptr;
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::reference
vector<T, Allocator>::reverse_iterator::operator[](size_type pos) const {
    return *(const_reverse_iterator::ptr - pos);
}

     
