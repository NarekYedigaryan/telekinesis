   #include "../headers/vector2d.h"
   #include <exception>
   vector2d::vector2d(int xx,int yy)
   {
      x=xx;
      y=yy;
   }

   vector2d vector2d::operator+(const vector2d& other)
   {
    vector2d ob{this->x+other.x,this->y+other.y};
    return ob;
   }

   vector2d vector2d::operator-(const vector2d& other)
   {
    vector2d ob{this->x-other.x,this->y-other.y};
    return ob;
   }

   vector2d vector2d::operator*(const vector2d& other)
   {
     vector2d ob{this->x*other.x,this->y*other.y};
    return ob;

   }

   vector2d vector2d::operator*(int num)
   {
     vector2d ob(this->x*num,this->y*num);
    return ob;

   }

   vector2d vector2d::operator/(int num)
   {
    if(num==0)
     throw std::exception();
     vector2d ob(this->x/num,this->y/num);
    return ob;

     
   }

   int vector2d::get_x()
   {
    return x;
   }
   int vector2d::get_y()
   {
    return y;
   }