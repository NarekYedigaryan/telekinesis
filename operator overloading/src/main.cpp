#include "../headers/vector2d.h"
#include <iostream>
int main()
{
    vector2d ob(2,3);
    vector2d ob1(3,4);
    vector2d result=ob+ob1;
    std::cout<<result.get_x();
    std::cout<<result.get_y();
    
}