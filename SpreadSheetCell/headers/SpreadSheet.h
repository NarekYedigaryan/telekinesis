#ifndef S_H
#define S_H
#include "Cell.h"

class SpreadSheet
{
private:
    Cell** cell;
    size_t m_row;
    size_t m_col;
public:
    SpreadSheet();
    SpreadSheet(int x);
    SpreadSheet(int x,int y);
    SpreadSheet(const SpreadSheet& other);
    SpreadSheet(SpreadSheet&& other);
    ~SpreadSheet();

    SpreadSheet& operator=(const SpreadSheet& other);
    SpreadSheet& operator=(SpreadSheet&& other);

    void add_row(int n);
    // void add_column(int n);
    // void resize_row(int n);
    // void resize_column(int n);
    // void resize(int n,int m);
    // void delete_row(int n);
    // void delete_column(int n);
    // void copy_from(int n,int m,const SpreadSheet& other );
    // void slice(int row,int col);
};
// std::ostream& operator<<(std::ostream& os,const SpreadSheet& s);

#endif //S_H