#include "../headers/SpreadSheet.h"

    SpreadSheet::SpreadSheet()
    :m_row{2}
    ,m_col{2}
    {
        cell=new Cell*[m_row];
     for (int i = 0; i < m_row; i++)
     {
        cell[i]=new Cell[m_col];
     }
      
    }

    SpreadSheet::SpreadSheet(int x)
    :m_row(x)
    ,m_col(x)
    {
        cell=new Cell*[m_row];
     for (int i = 0; i < m_row; i++)
     {
        cell[i]=new Cell[m_col];
     }

    }

    SpreadSheet::SpreadSheet(int x,int y)
    :m_row(x)
    ,m_col(y)
    {
        cell=new Cell*[m_row];
     for (int i = 0; i < m_row; i++)
     {
        cell[i]=new Cell[m_col];
     }

    }

    SpreadSheet::SpreadSheet(const SpreadSheet& other)
    :m_row{other.m_row}
    ,m_col{other.m_col}
    {
        cell=new Cell*[m_row];
     for (int i = 0; i < m_row; i++)
     {
        cell[i]=new Cell[m_col];
     }

    for (int i = 0; i < m_row; i++)
    {
        for (int j = 0; j < m_col; j++)
        {
            cell[i][j]=other.cell[i][j];
        }
        
    }
    }

    SpreadSheet::SpreadSheet(SpreadSheet&& other)
    :m_row{other.m_row}
    ,m_col{other.m_col}
    ,cell{other.cell}
    {
        cell=new Cell*[m_row];
        for (int i = 0; i < m_row; i++)
        {
           cell[i]=new Cell[m_col];
        }

    for (int i = 0; i < m_row; i++)
    {
        for (int j = 0; j < m_col; j++)
        {
           cell[i][j]=other.cell[i][j];
        }
        
    }
        other.m_row=0;
        other.m_col=0;
        other.cell=nullptr;
    }
    SpreadSheet::~SpreadSheet()
    {
       for (size_t i = 0; i < m_row; i++)
       {
        delete[] cell[i];
       }
       delete[] cell;
    }

    SpreadSheet& SpreadSheet::operator=(const SpreadSheet& other)
    {
    if(this!=&other)
    {
        m_row=other.m_row;
        m_col=other.m_col;

       for (int i = 0; i < m_row; i++)
       {
           for (int j = 0; j < m_col; j++)
           {
            cell[i][j]=other.cell[i][j];
           }
        
       }
     }
         return *this;
    }
    SpreadSheet& SpreadSheet::operator=(SpreadSheet&& other)
    {
       if(this!=&other)
       {
        m_row=other.m_row;
        m_col=other.m_col;
        cell=other.cell;

        other.m_row=0;
        other.m_col=0;
        other.cell=nullptr;
       }
     return *this;
    }

    void SpreadSheet::add_row(int n)
    {
       int new_row = m_row+n;
       Cell** tmp=new Cell*[new_row];
       for (int i = 0; i < new_row; i++)
       {
        cell[i]=new Cell[m_col];
       }

       for (int i = 0; i < m_row; i++)
       {
        for (int j = 0; j < m_col; j++)
        {
            tmp[i][j]=cell[i][j];
        }
        
       }
       
       for (size_t i = 0; i < m_row; i++)
       {
          delete[] cell[i];
       }
       delete[] cell;
       cell=tmp;
       tmp=nullptr;
       m_row=new_row;
    }
    // void SpreadSheet::add_column(int n)
    // {

    // }
    // void SpreadSheet::resize_row(int n)
    // {

    // }
    // void SpreadSheet::resize_column(int n)
    // {

    // }
    // void SpreadSheet::resize(int n,int m)
    // {

    // }
    // void SpreadSheet::delete_row(int n)
    // {

    // }
    // void SpreadSheet::delete_column(int n)
    // {

    // }

    // void SpreadSheet::copy_from(int n,int m,const SpreadSheet& other )
    // {

    // }
    // void SpreadSheet::slice(int row,int col)
    // {

    // }

// std::ostream& SpreadSheet::operator<<(std::ostream& os,const SpreadSheet& s)
// {

// }
