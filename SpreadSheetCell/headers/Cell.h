#ifndef CELL_H
#define CELL_H

#include <iostream>
#include <string>

class Cell {
private:
    std::string str;

public:
    Cell() = default;
    Cell(const std::string& value);
    Cell(const Cell& other);
    Cell(int value);
    Cell(const char* ch);
    Cell(double value);
    Cell(Cell&& other) noexcept;
    ~Cell() = default;

    Cell& operator=(const Cell& other);
    Cell& operator=(Cell&& other) noexcept;

    operator int() const;
    operator double() const;
    operator std::string() const;
};

std::ostream& operator<<(std::ostream& os, const Cell& rhv);
std::istream& operator>>(std::istream& is, Cell& rhv);

#endif