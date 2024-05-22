#include <iostream>
#include "../headers/forward_list.h"
#include <forward_list>

int main()
{
     forward_list<int> list{1,2,3,4,4,5,6,4,7};
     list.push_back(22);     
     list.print();
     
     
}