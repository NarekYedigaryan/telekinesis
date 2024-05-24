#include "../headers/vector.h"

using namespace g3;

int main()
{
    vector<int> arr={99,1,2,9,3,4};
    vector<int> arr5(arr.begin(),arr.end());
    // std::cout<<*arr.begin();
    // arr.push_back(9);
    // arr.pop_back();
    // std::cout<<arr.capacity()<<std::endl;
    // std::cout<<arr.size();

    for (size_t i = 0; i < arr5.size(); i++)
    {
      std::cout<<arr5[i];
    }

    // vector<int> arr1=arr;
    // for (size_t i = 0; i < arr1.size(); i++)
    // {
    //   std::cout<<arr1[i];
    // }
    
    // if(arr1<=arr)
    // {
    //     std::cout<<"true";
    // }
    // else{
    //     std::cout<<"false";
        
    // }

    // vector<int> arr2(arr.begin(),arr.end());
    // for (size_t i = 0; i < arr2.size(); i++)
    // {
    //   std::cout<<arr2[i];
    // }
    
    // vector<int> arr3(3,5);
    // for (size_t i = 0; i < arr3.size(); i++)
    // {
    //   std::cout<<arr3[i];
    // }
    // if(arr == arr1)
    // {
    //     std::cout<<"yes";
    // }
     
}