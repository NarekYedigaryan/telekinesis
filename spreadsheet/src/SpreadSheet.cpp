#include "../headers/SpreadSheet.h"

void SpreadSheet::allocate()
{
     cell = new Cell*[m_row];
     for (size_t i = 0; i < m_row; i++)
     {
        cell[i] = new Cell[m_col];
     }
     
}

SpreadSheet::SpreadSheet()
:m_col(2)
,m_row(2)
{
   allocate();
}

SpreadSheet::SpreadSheet(const SpreadSheet& rhv)
:m_col(rhv.m_col)
,m_row(rhv.m_row)
{
   allocate();
   for (size_t i = 0; i < m_row; i++)
   {
      for (size_t j = 0; j < m_col; j++)
      {
        cell[i][j] = rhv.cell[i][j];
      }
   }
}

SpreadSheet::SpreadSheet(SpreadSheet&& rhv)
:m_col(rhv.m_col)
,m_row(rhv.m_row)
,cell(std::move(rhv.cell))
{
   allocate();
   rhv.m_col = 0;
   rhv.m_row = 0;
   rhv.cell = nullptr;
}

SpreadSheet::SpreadSheet(size_t size)
:m_col(size)
,m_row(size)
{
   allocate();
}

SpreadSheet::SpreadSheet(size_t row, size_t col)
:m_col(col)
,m_row(row)
{
   allocate();
}

SpreadSheet::~SpreadSheet()
{
   clear();
}

const SpreadSheet& SpreadSheet::operator=(const SpreadSheet& rhv)
{
    if(this != &rhv)
    {
       m_col = rhv.m_col;
       m_row = rhv.m_row;
       allocate();
       for (size_t i = 0; i < m_row; i++)
       {
          for (size_t j = 0; j <m_col; j++)
          {
              cell[i][j] = rhv.cell[i][j];
          }
       }
    }
    return *this;
}

const SpreadSheet& SpreadSheet::operator=(SpreadSheet&& rhv)
{
     if(this != &rhv)
    {
       m_col = rhv.m_col;
       rhv.m_col = 0;
       m_row = rhv.m_row;
       rhv.m_row = 0;
       cell = rhv.cell;
    }
    return *this;
}

SpreadSheet::Column SpreadSheet::operator[](size_t pos)
{
    if (pos >= m_col) {
        throw std::out_of_range("Column index out of range");
    }
    return Column(cell[pos]);
}

const SpreadSheet::Column SpreadSheet::operator[](size_t pos) const
{
    if (pos >= m_col) {
        throw std::out_of_range("Column index out of range");
    }
    return Column(cell[pos]);
}


void SpreadSheet::clear() noexcept
{
    for (size_t i = 0; i < m_row; i++)
    {
       delete[] cell[i];
    }
    delete[] cell;
    m_col = 0;
    m_row = 0;
    cell = nullptr;
}

size_t SpreadSheet::row() const
{
    return m_row;
}

size_t SpreadSheet::col() const
{
    return m_col;
}


void SpreadSheet::mirrorH()
{
    for (size_t i = 0; i < m_col; ++i) 
    {
        for (size_t j = 0; j < m_row / 2; ++j) 
        {
            std::swap(cell[i][j], cell[i][m_row - j - 1]);
        }
    }
}

void SpreadSheet::mirrorV()
{
    for (size_t i = 0; i < m_row; ++i) 
    {
        for (size_t j = 0; j < m_col / 2; ++j) 
        {
            std::swap(cell[j][i], cell[m_col - j - 1][i]);
        }
    }
}

void SpreadSheet::mirrorD()
{
    if (m_row != m_col) {
        throw std::logic_error("Matrix must be square");
    }

    for (size_t i = 0; i < m_row; ++i) 
    {
        for (size_t j = i + 1; j < m_col; ++j) 
        {
            std::swap(cell[i][j], cell[j][i]);
        }
    }
}


void SpreadSheet::mirrorSD()
{
    if (m_row != m_col) {
        throw std::logic_error("Matrix must be square");
    }

    for (size_t i = 0; i < m_row; ++i) 
    {
        for (size_t j = 0; j < m_col - i; ++j) 
        {
            std::swap(cell[i][j], cell[m_row - j - 1][m_col - i - 1]);
        }
    }
}

void SpreadSheet::rotate(int cnt)
{
    cnt = (cnt % 4 + 4) % 4;

    for (int k = 0; k < cnt; ++k) 
    {
        mirrorH();
        mirrorD();
    }
}

void SpreadSheet::removeRow(size_t row) 
{
    mirrorH();
    rotate(2);

    for (size_t i = row; i < m_row - 1; ++i) 
    {
        for (size_t j = 0; j < m_col; ++j) 
        {
            cell[i][j] = cell[i + 1][j];
        }
    }
    --m_row;
    rotate(2);
    mirrorH();
}

void SpreadSheet::removeRows(std::initializer_list<size_t> rows) {
    for (auto row : rows) 
    {
        removeRow(row);
    }
}

void SpreadSheet::removeCol(size_t col) 
{
    mirrorV();
    rotate(2);
    for (size_t i = 0; i < m_row; ++i) 
    {
        for (size_t j = col; j < m_col - 1; ++j) 
        {
            cell[i][j] = cell[i][j + 1];
        }
    }
    --m_col;
    rotate(2);
    mirrorV();
}

void SpreadSheet::removeCols(std::initializer_list<size_t> cols) 
{
    for (auto col : cols) 
    {
        removeCol(col);
    }
}

void SpreadSheet::resizeRow(size_t r) {
    resize(r, m_col);
}

void SpreadSheet::resizeCol(size_t c) {
    resize(m_row, c);
}


void SpreadSheet::resize(size_t r, size_t c) 
{
    if (r == m_row && c == m_col) 
    {
        return;
    }

    Cell** newCells = new Cell*[r]; 
    size_t minRows = std::min(m_row, r); 
    for (size_t i = 0; i < minRows; ++i) 
    {
        Cell* newRow = new Cell[c]; 
        size_t minCols = std::min(m_col, c);

        for (size_t j = 0; j < minCols; ++j) 
        {
            newRow[j] = cell[i][j];
        }

        if (c > m_col) 
        {
            for (size_t j = m_col; j < c; ++j) 
            {
                newRow[j] = Cell(); 
            }
        }

        delete[] cell[i]; 
        newCells[i] = newRow; 
    }

    if (r > m_row) 
    {
        for (size_t i = m_row; i < r; ++i) 
        {
            newCells[i] = new Cell[c](); 
        }
    }

    if (r < m_row) 
    {
        for (size_t i = r; i < m_row; ++i) 
        {
            delete[] cell[i];
        }
    }

    delete[] cell;
    cell = newCells; 
    m_row = r; 
    m_col = c; 
}

SpreadSheet SpreadSheet::slice(std::initializer_list<size_t> rows, std::initializer_list<size_t> cols) 
{
    SpreadSheet sliced(rows.size(), cols.size());

    size_t newRowIdx = 0;
    for (auto row : rows) 
    {
        size_t newColIdx = 0;
        for (auto col : cols) 
        {
            sliced.cell[newRowIdx][newColIdx] = cell[row][col];
            ++newColIdx;
        }
        ++newRowIdx;
    }

    return sliced;
}


SpreadSheet::Column::Column(Cell* col)
:col(col)
{}

Cell& SpreadSheet::Column::operator[](size_t pos)
{
   return col[pos];
}
const Cell& SpreadSheet::Column::operator[](size_t pos) const
{
   return col[pos];
}

bool operator==(const SpreadSheet& lhv, const SpreadSheet& rhv) 
{
    if (lhv.row() != rhv.row() || lhv.col() != rhv.col()) 
    {
        return false;
    }

    for (size_t i = 0; i < lhv.row(); ++i) 
    {
        for (size_t j = 0; j < lhv.col(); ++j) 
        {
            if (lhv.cell[i][j] != rhv.cell[i][j]) 
            {
                return false;
            }
        }
    }

    return true;
}

bool operator!=(const SpreadSheet& lhv, const SpreadSheet& rhv) 
{
    return !(lhv == rhv);
}

int arr[10] = {31, 32, 35, 33, 31, 34, 35, 36, 33, 32};


std::ostream& operator<<(std::ostream& out, const SpreadSheet& ob) 
{
    std::vector<int> columnWidths(ob.col(), 0);

    for (size_t i = 0; i < ob.row(); ++i) 
    {
        for (size_t j = 0; j < ob.col(); ++j) 
        {
            int cellWidth = static_cast<int>(ob.cell[i][j].getValue().size());
            columnWidths[j] = std::max(columnWidths[j], cellWidth);
        }
    }

    size_t totalWidth = std::accumulate(columnWidths.begin(), columnWidths.end(), 0);
    totalWidth += columnWidths.size() * 2 + 1;

    out << std::left;

    for (size_t i = 0; i < ob.row(); ++i) 
    {
        out << std::string(totalWidth, '-') << std::endl;
        out << '|';
        for (size_t j = 0; j < ob.col(); ++j) 
        {
            int colorCode = arr[std::stoi(ob.cell[i][j].getValue()) % 10];
            std::ostringstream oss;
            oss << "\033[" << colorCode << "m";
            out << oss.str()
                << std::setw(columnWidths[j] + 1)
                << ob.cell[i][j].getValue()
                << "\033[0m"
                << '|';
        }
        out << std::endl;
    }
    out << std::string(totalWidth, '-') << std::endl;

    return out;
}
