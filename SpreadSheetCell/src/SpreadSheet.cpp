#include "../headers/SpreadSheet.h"


    void SpreadSheet::allocator()
    {
       cell=new Cell*[m_row];
     for (int i = 0; i < m_row; i++)
     {
        cell[i]=new Cell[m_col];
     }
    }

    SpreadSheet::SpreadSheet()
    :m_row{2}
    ,m_col{2}
    {
      allocator();
    }

    SpreadSheet::SpreadSheet(int x)
    :m_row(x)
    ,m_col(x)
    {
         allocator();

    }
    SpreadSheet::SpreadSheet(std::initializer_list<Cell> arr) {
    m_col = 5; 
    m_row = (arr.size() + m_col - 1) / m_col; 

    allocator(); 

    int i = 0;
    int j = 0;
    for (auto& it : arr) {
        cell[i][j] = it;
        ++j;

        if (j == m_col) {
            ++i;
            j = 0;
        }
    }
}

    SpreadSheet::SpreadSheet(int x,int y)
    :m_row(x)
    ,m_col(y)
    {
        allocator();
    }

    SpreadSheet::SpreadSheet(const SpreadSheet& other)
    :m_row{other.m_row}
    ,m_col{other.m_col}
    {
       allocator();

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
        allocator();
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
      resize(m_row+n,m_col);
    }
    void SpreadSheet::add_column(int n)
    {
      resize(m_row,m_col+n);
    }
    void SpreadSheet::resize_row(int n)
    {
      resize(n,m_col);
    }
    void SpreadSheet::resize_column(int n)
    {
      resize(m_row,n);
    }
    void SpreadSheet::resize(int n,int m)
    {
      int new_row=m_row;
      int new_col=m_col;
      int tmp_row=(n<=m_row)?n:new_row;
      int tmp_col=(m<=m_col)?m:new_col;
     
       Cell** tmp=new Cell*[n];
       for (int i = 0; i < n; i++)
       {
        tmp[i]=new Cell[m];
       }

       for (int i = 0; i < tmp_row; i++)
       {
        for (int j = 0; j < tmp_col; j++)
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
       m_row=n;
       m_col=m;
    }
    void SpreadSheet::delete_row(int n)
    {
       if(n>=m_row)
       {
         throw std::out_of_range(" out of range");
       }
       resize(m_row-n,m_col);
    }
    void SpreadSheet::delete_column(int n)
    {
        if(n>=m_col)
       {
         throw std::out_of_range(" out of range");
       }
       resize(m_row,m_col-n);
    }

    void SpreadSheet::copy_from(int row,int col,const SpreadSheet& other )
    {
        this->resize(row,col);
        for (size_t i = 0; i < row; ++i)
        {
           for (size_t j = 0; j < col; ++j)
           {
              cell[i][j]=other.cell[i][j];
           }
        }
        
    }
    SpreadSheet& SpreadSheet::slice(int row,int col)
    {
         resize(m_row-row,m_col-col);
         return *this;
    }




void SpreadSheet::print()
{
   for (size_t i = 0; i < m_row; ++i)
   {
      for (size_t j = 0; j < m_col; ++j)
      {
         std::cout<<cell[i][j]<<" ";
      }
      std::cout<<std::endl;
   }
   
}

void SpreadSheet::insert(int i, int j,Cell ob)
{
   if(i>=m_row || j>=m_col || i<0 || j<0)
   {
      throw std::out_of_range("out of range");
   }
   cell[i][j]=ob;
}
