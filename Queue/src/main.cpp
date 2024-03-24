#include "..\headers\Queue.h"
#include <iostream>

int main()
{
    Queue<int>  a{1,2,3,4};
    Queue<int>  b{1,2,3,4};
    std::cout<<a.front();

}