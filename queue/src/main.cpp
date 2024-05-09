#include "../headers/queue.h"
#include <iostream>
using namespace g3;

int main()
{
     queue<int> ob{1,2,3,4};
     ob.push(23);
    std::cout<<ob.back();

  
  
}