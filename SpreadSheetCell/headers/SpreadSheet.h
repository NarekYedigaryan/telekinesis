#ifndef S_H
#define S_H
#include "Cell.h"
#include <initializer_list>
#include <exception>
class SpreadSheet
{
private:
    Cell** cell;
    size_t m_row;
    size_t m_col;
    void allocator();
public:
    SpreadSheet();
    SpreadSheet(int x);
    SpreadSheet(std::initializer_list<Cell> arr);
    SpreadSheet(int x,int y);
    SpreadSheet(const SpreadSheet& other);
    SpreadSheet(SpreadSheet&& other);
    ~SpreadSheet();


    SpreadSheet& operator=(const SpreadSheet& other);
    SpreadSheet& operator=(SpreadSheet&& other);

    void add_row(int n);
    void add_column(int n);
    void resize_row(int n);
    void resize_column(int n);
    void resize(int n,int m);
    void delete_row(int n);
    void delete_column(int n);
    void copy_from(int row,int col,const SpreadSheet& other );
    SpreadSheet& slice(int row,int col);
    void print();
    void insert(int i, int j,Cell ob);
};

#endif //S_H