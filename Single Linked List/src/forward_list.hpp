#include "..\headers\forward_list.h"  

//Ctors
template<typename T, template<typename> class Allocator>
forward_list<T, Allocator>::forward_list()
:head(nullptr), size(0)
{}

template<typename T, template<typename> class Allocator>
forward_list<T, Allocator>::forward_list(value_type num)
:head(nullptr),size()
{
    head=allocator.allocate(1);
    allocator.construct(head,num);
    size = 1;
}

template<typename T, template<typename> class Allocator>
forward_list<T, Allocator>::forward_list(std::initializer_list<T> list)
: head(nullptr), size(0)
{
   for(const T& elem:list)
   {
     push_back(elem);
   }
}
template<typename T, template<typename> class Allocator>
forward_list<T, Allocator>::forward_list(const forward_list& other)
: head(nullptr), size(other.size)
{
    if (other.head != nullptr) {
        head = allocator.allocate(1); 
        allocator.construct(head, other.head->val); 
        
        Node* current = head;
        Node* otherCurrent = other.head->next;

        while (otherCurrent != nullptr) {
            current->next = allocator.allocate(1); 
            allocator.construct(current->next, otherCurrent->val); 
            current = current->next;
            otherCurrent = otherCurrent->next;
        }
    }
}


template<typename T, template<typename> class Allocator>
forward_list<T, Allocator>::forward_list(forward_list&& other)
:head(nullptr)
{
    this->head=other.head;
    this->size=other.size;

    other.head=nullptr;
    other.size=0;
}

template<typename T, template<typename> class Allocator>
forward_list<T, Allocator>& forward_list<T, Allocator>::operator=(const forward_list& other)
{
    if (this != &other) {
        clear(); 

        Node* otherCurrent = other.head;
        Node** currentPtr = &head; 
        while (otherCurrent != nullptr) 
        {
            *currentPtr = allocator.allocate(1);
            allocator.construct(*currentPtr, otherCurrent->val); 
            currentPtr = &((*currentPtr)->next); 
            otherCurrent = otherCurrent->next; 
        }

        size = other.size; 
    }
    return *this;
}


template<typename T, template<typename> class Allocator>
forward_list<T, Allocator>& forward_list<T, Allocator>::operator=(forward_list&& other) noexcept
{
    if (this != &other) 
    {
        clear(); 
        head=other.head;
        size=other.size;

        other.head=nullptr;
        other.size=0;
       
    }
    return *this;
}

template<typename T, template<typename> class Allocator>
forward_list<T, Allocator>::~forward_list()
{
   clear();
}

 
 //Functions
 template<typename T, template<typename> class Allocator>
 typename forward_list<T, Allocator>::reference forward_list<T, Allocator>::front()
 {
     if(head==nullptr)
     {
        throw std::out_of_range("List is empty");
     }

     return head->val;
     ++size;
 }

template<typename T, template<typename> class Allocator>
bool forward_list<T, Allocator>::empty() const noexcept
{
  return (head==nullptr)?true:false;
}
template<typename T, template<typename> class Allocator>
typename forward_list<T, Allocator>::size_type forward_list<T, Allocator>::max_size() const noexcept
{
   return std::numeric_limits<size_type>::max();
}

template<typename T, template<typename> class Allocator>
void forward_list<T, Allocator>::clear() noexcept
{
    while (head != nullptr)
    {
        Node* temp = head;
        head = head->next;
        allocator.destroy(temp); 
        allocator.deallocate(temp, 1);
    }
    size = 0;   
}


template<typename T, template<typename> class Allocator>
void forward_list<T, Allocator>::push_front(const value_type& value)
{
    Node* newNode = allocator.allocate(1);
    allocator.construct(newNode,value);
    newNode->next = head;
    head = newNode;
    ++size;  
}
template<typename T, template<typename> class Allocator>
void forward_list<T, Allocator>::push_front( value_type&& value )
{
    Node* newNode = allocator.allocate(1);
    allocator.construct(newNode,value);
    newNode->next = head;
    head = newNode;
    ++size;  
}

template<typename T, template<typename> class Allocator>
void forward_list<T, Allocator>::pop_front()
{
   if (head) 
   {
       Node* temp = head;
       head = head->next;
       allocator.destroy(temp);
       allocator.deallocate(temp,1);
       --size;
   }

}


template<typename T, template<typename> class Allocator>
void forward_list<T, Allocator>::resize( size_type count )
{
    resize(count,0);
}

template<typename T, template<typename> class Allocator>
void forward_list<T, Allocator>::resize(size_type count, const value_type& value)
{
    if (count == size) {
        return;
    } else if (count < size) {
        Node* tmp = head;
        while (count > 1) {
            tmp = tmp->next;
            --count;
        }
        while (tmp->next != nullptr) {
            Node* temp = tmp->next;
            tmp->next = tmp->next->next;
            allocator.destroy(temp); 
            allocator.deallocate(temp, 1); 
        }
    } else {
        if (!head) {
            head = allocator.allocate(1); 
            allocator.construct(head, value); 
            --count;
        }
        Node* tmp = head;
        while (tmp->next != nullptr) {
            tmp = tmp->next;
        }
        int addition = count - size;
        for (int i = 0; i < addition; ++i) {
            Node* newNode = allocator.allocate(1); 
            allocator.construct(newNode, value); 
            tmp->next = newNode; 
            tmp = tmp->next;
        }
    }
    
    size = count; 
}

template<typename T, template<typename> class Allocator>
void forward_list<T, Allocator>::remove(const value_type& value)
{
    if (head == nullptr) {
        return; 
    }

    Node* tmp = head;
    Node* prev = nullptr;

    while (tmp != nullptr)
    {
        if (tmp->val == value)
        {
            if (prev == nullptr) 
            {
                head = tmp->next;
                allocator.destroy(tmp);
                allocator.deallocate(tmp, 1);
                tmp = head; 
                --size; 
            }
            else 
            {
                prev->next = tmp->next;
                allocator.destroy(tmp);
                allocator.deallocate(tmp, 1);
                tmp = prev->next;
                --size; 
            }
        }
        else
        {
            prev = tmp;
            tmp = tmp->next;
        }
    }
}

// template<typename T, template<typename> class Allocator>
// void forward_list<T, Allocator>::reverse() noexcept
// {

// }

template<typename T, template<typename> class Allocator>
typename forward_list<T, Allocator>::size_type forward_list<T, Allocator>::unique() {
    size_type removed = 0;
    if (head == nullptr || head->next == nullptr) {
        return removed; 
    }

    Node* current = head;
    while (current->next != nullptr) {
        if (current->val == current->next->val) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            ++removed;
            --size;
        } else {
            current = current->next;
        }
    }
    return removed;
}

// template<typename T, template<typename> class Allocator>
// void forward_list<T, Allocator>::sort()
// {

// }
template<typename T, template<typename> class Allocator>
void forward_list<T, Allocator>::push_back(T elem)
{
    if (head == nullptr)
    {
        head = allocator.allocate(1);
        allocator.construct(head, elem);
    }
    else
    {
        Node* current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = allocator.allocate(1);
        current = current->next; 
        allocator.construct(current, elem);
    }
    ++size;
}



template<typename T, template<typename> class Allocator>
T forward_list<T, Allocator>::first()
{
    if(head==nullptr)
    {
        throw std::logic_error("The list is mepty");
    }
    return head->val;
}

template<typename T, template<typename> class Allocator>
void forward_list<T, Allocator>::print()
{
    Node* current=head;
    while(current)
    {
      std::cout<<current->val<<" ";
      current=current->next;
    }
    
}