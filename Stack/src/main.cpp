#include "../headers/stack.h"
#include <iostream>

int main()
{
    stack<int> st{1,2,3};
    stack<int> st1=st;
    // st.pop();
    // std::cout<<st.top();
     size_t size = st1.size();
    for (size_t i = 0; i < size; i++)
    {
        std::cout<<st1.top();
        st1.pop();
    }
    std::cout<<444;
    
}