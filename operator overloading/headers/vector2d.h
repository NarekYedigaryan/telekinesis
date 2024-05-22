#ifndef VECTOR2D_H
#define VECTOR2D_H

class vector2d
{
private:
   int x;
   int y;
public:
   vector2d(int xx,int yy);
   vector2d operator+(const vector2d& other);
   vector2d operator-(const vector2d& other);
   vector2d operator*(const vector2d& other);
   vector2d operator*(int num);
   vector2d operator/(int num);
   
   int get_x();
   int get_y();
};
#endif