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
, arr_(alloc_.allocate(capacity_)) 
{

    for(size_type i = 0 ; i<size_ ; ++i)
    {   
        new(&arr_[i]) T(rhv.arr_[i]);
    }
}

template <typename T, typename Allocator>
vector<T, Allocator>::vector(vector&& rhv)
    : size_(rhv.size_)
    , capacity_(rhv.capacity_)
    , arr_(std::move(rhv.arr_))
{
    rhv.size_ = 0; 
    rhv.capacity_ = 0; 
    rhv.arr_ = nullptr; 
}


template <typename T, typename Allocator>
vector<T, Allocator>::vector(std::initializer_list<value_type> init)
: size_(init.size())
, capacity_(init.size())
, arr_(alloc_.allocate(capacity_)) 
{
    size_type ind = 0;
    for (const T& i : init) {
            new(&arr_[ind++]) T(i);  
        }
}


template <typename T, typename Allocator>
vector<T, Allocator>::vector(size_type size, const_reference val)
    : size_(size), 
      capacity_(size), 
      arr_(alloc_.allocate(capacity_)) 
{
    for (size_type i = 0; i < size_; ++i) 
    {
        alloc_.construct(&this->arr_[i],val);
    }
}

template <typename T, typename Allocator>
template <typename InputIt>
vector<T, Allocator>::vector(InputIt first, InputIt last)
: size_()
, capacity_()
, arr_(nullptr)
{
    for (InputIt it = first; it != last; ++it) 
    {
        size_++;
    }

    capacity_ = size_; 
    arr_ = alloc_.allocate(capacity_);

    size_type i = 0;
    for (InputIt it = first; it != last; ++it) 
    {
       std::allocator_traits<Allocator>::construct(alloc_, &arr_[i++], it);
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
    arr_=alloc_.allocate(capacity_) ;
    for(size_type i = 0 ; i<size_ ; ++i)
    {
        new(&this->arr_[i]) T(rhv.arr_[i]);
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
    return alloc_;
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::reference vector<T, Allocator>::at(size_type pos)
{
   if(pos>=size_)
   {
     throw std::out_of_range("Not correct position ");
   }
   return arr_[pos];
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_reference vector<T, Allocator>::at(size_type pos) const
 {
   if(pos>=size_ || pos<0)
   {
     throw std::out_of_range("Not correct position ");
   }
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
   if (size_ == 0) {
        throw std::out_of_range("vector is empty");
    }
    return arr_[0];
} 

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_reference vector<T, Allocator>::front() const
{
    if (size_ == 0) {
        throw std::out_of_range("vector is empty");
    }
    return arr_[0];
} 

template <typename T, typename Allocator>
typename vector<T, Allocator>::reference vector<T, Allocator>::back() 
{
    if (size_ == 0) {
        throw std::out_of_range("vector is empty");
    }
    return arr_[size_ - 1];
}


template <typename T, typename Allocator>
typename vector<T, Allocator>::const_reference vector<T, Allocator>::back() const
{
    if (size_ == 0) {
        throw std::out_of_range("vector is empty");
    }
    return arr_[size_ - 1];
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
    void vector<T, Allocator>::reserve(size_type new_cap) {
        if (new_cap <= capacity_) {
            return; 
        }
        size_type sizee = size_;
        T* tmp = alloc_.allocate(new_cap);
        for (size_type i = 0; i < size_; ++i) {
            
             std::allocator_traits<Allocator>::construct(alloc_, &tmp[i], std::move(arr_[i]));
        }
        clear();

        arr_ = tmp;
        capacity_ = new_cap;
        size_ = sizee;
    }


template <typename T, typename Allocator>
void vector<T, Allocator>::clear() noexcept 
{
    for (size_type i = 0; i < size_; ++i) 
    {
       std::allocator_traits<Allocator>::destroy(alloc_, &arr_[i]);
    }
    alloc_.deallocate(arr_, capacity_); 
    size_ = 0;
    capacity_ = 0; 
}


template <typename T, typename Allocator>
typename vector<T, Allocator>::iterator 
vector<T, Allocator>::insert(const_iterator pos, const_reference val) 
{
    size_type index = pos - cbegin(); 
    if (size_ >= capacity_) 
    {
        reserve(size_ + 1); 
    }
    for (size_type i = size_; i > index; --i) {
        arr_[i] = std::move(arr_[i - 1]);
    }
    arr_[index] = val; 
    ++size_;
    return begin() + index;
}


template <typename T, typename Allocator>
typename vector<T, Allocator>::iterator vector<T, Allocator>::insert(const_iterator pos, size_type count, const_reference val) 
{
    size_type index = pos - cbegin();
    if (size_ + count > capacity_) {
        reserve(size_ + count);
    }
    for (size_type i = size_ + count - 1; i >= index + count; --i) {
        arr_[i] = std::move(arr_[i - count]);
    }
    for (size_type i = 0; i < count; ++i) {
        arr_[index + i] = val;
    }
    size_ += count;
    return begin() + index;
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::iterator vector<T, Allocator>::insert(const_iterator pos, std::initializer_list<value_type> init) 
{
    size_type index = pos - cbegin();
    size_type count = init.size();
    if (size_ + count > capacity_) {
        reserve(size_ + count);
    }
    for (size_type i = size_ + count - 1; i >= index + count; --i) {
        arr_[i] = std::move(arr_[i - count]);
    }
    std::copy(init.begin(), init.end(), arr_ + index);
    size_ += count;
    return begin() + index;
}

template <typename T, typename Allocator>
template <typename InputIt>
typename vector<T, Allocator>::iterator vector<T, Allocator>::insert(const_iterator pos, InputIt first, InputIt last) 
{
    size_type index = pos - cbegin();
    size_type count = std::distance(first, last);
    if (size_ + count > capacity_) {
        reserve(size_ + count);
    }
    for (size_type i = size_ + count - 1; i >= index + count; --i) {
        arr_[i] = std::move(arr_[i - count]);
    }
    std::copy(first, last, arr_ + index);
    size_ += count;
    return begin() + index;
}


template <typename T, typename Allocator>
typename vector<T, Allocator>::iterator vector<T, Allocator>::erase(const_iterator pos) 
{
    size_type index = pos - cbegin();
    for (size_type i = index; i < size_ - 1; ++i) {
        arr_[i] = std::move(arr_[i + 1]);
    }
    --size_;
    return begin() + index;
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::iterator vector<T, Allocator>::erase(const_iterator first, const_iterator last) 
{
    size_type start_index =cbegin() - first;
    size_type count = cbegin() - last; 
    for (size_type i = start_index; i < size_ - count; ++i) {
        arr_[i] = std::move(arr_[i + count]);
    }
    size_ -= count;
    return begin() + start_index;
}




template <typename T, typename Allocator>
void vector<T, Allocator>:: push_back(const_reference val)
{
   if(size_==capacity_)
   {
    capacity_ *= 2;
     reserve(capacity_);
   }    
   arr_[size_]=val;
   ++size_;
}
    
template <typename T, typename Allocator>
void vector<T, Allocator>::pop_back() 
{
    if (size_ > 0) 
    {
        std::allocator_traits<Allocator>::destroy(alloc_, &arr_[size_ - 1]);  
        --size_; 
    }
}

template <typename T, typename Allocator>
void vector<T, Allocator>::resize(size_type new_size, const_reference val) 
{
    if (new_size < size_) 
    {
        for (size_t i = size_ - 1; i >= new_size; --i) 
        {
            std::allocator_traits<Allocator>::destroy(alloc_, &arr_[i]);
        }
        size_ = new_size;
    } 
    else if (new_size > size_) 
    {
        if (new_size > capacity_) {
            reserve(new_size);
        }
        for (size_type i = size_; i < new_size; ++i) 
        {
           this->arr_[i]=val; 
        }
        size_ = new_size;
    }
}


template <typename T, typename Allocator>
bool vector<T, Allocator>::operator==(const vector& other) const 
{
    if (size() != other.size()) 
    {
        return false;
    }
    for (size_type i = 0; i < other.size(); ++i) 
    {
        if (arr_[i] != other.arr_[i]) 
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
    for (size_type i = 0; i < size_; ++i) 
    {
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
const typename vector<T, Allocator>::const_iterator&
vector<T, Allocator>::const_iterator::operator=(const const_iterator& other) {
    ptr = other.ptr;
    return *this;
}

template <typename T, typename Allocator>
const typename vector<T, Allocator>::const_iterator&
vector<T, Allocator>::const_iterator::operator=(const_iterator&& other) {
    ptr = std::move(other.ptr);
    return *this;
}
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
typename vector<T, Allocator>::size_type
vector<T, Allocator>::const_iterator::operator-(const_iterator other) const {
    return ptr - other.ptr;
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
const typename vector<T, Allocator>::iterator&
vector<T, Allocator>::iterator::operator=(const iterator& other) {
    if (this != &other) {
        arr_ = other.arr_;
    }
    return *this;
}

template <typename T, typename Allocator>
const typename vector<T, Allocator>::iterator&
vector<T, Allocator>::iterator::operator=(iterator&& other) {
    if (this != &other) {
        arr_ = std::move(other.arr_);
    }
    return *this;
}


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
typename vector<T, Allocator>::size_type
vector<T, Allocator>::iterator::operator-(const_iterator n) const {
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
const typename vector<T, Allocator>::const_reverse_iterator&
vector<T, Allocator>::const_reverse_iterator::operator=(const const_reverse_iterator& other) {
    if (this != &other) 
    {
        ptr = other.ptr;
    }
    return *this;
}

template <typename T, typename Allocator>
const typename vector<T, Allocator>::const_reverse_iterator&
vector<T, Allocator>::const_reverse_iterator::operator=(const_reverse_iterator&& other) {
    if (this != &other) 
    {
         ptr = std::move(other.ptr);
    }
    return *this;
}


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
const typename vector<T, Allocator>::reverse_iterator&
vector<T, Allocator>::reverse_iterator::operator=(const reverse_iterator& other) {
    if (this != &other) {
        ptr = other.ptr;
    }
    return *this;
}

template <typename T, typename Allocator>
const typename vector<T, Allocator>::reverse_iterator&
vector<T, Allocator>::reverse_iterator::operator=(reverse_iterator&& other) {
    if (this != &other) {
        ptr = std::move(other.ptr);
    }
    return *this;
}

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

     
