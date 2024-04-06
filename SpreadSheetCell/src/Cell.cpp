
#include "../headers/Cell.h"
#include <stdexcept>

Cell::Cell(const std::string& value)
    : str(value) {}

Cell::Cell(const Cell& other)
    : str(other.str) {}

Cell::Cell(Cell&& other) noexcept
    : str(std::move(other.str)) {}

Cell::Cell(int value)
    : str(std::to_string(value)) {}
Cell::Cell(const char* ch)
:str(ch)
{}

Cell::Cell(double value)
    : str(std::to_string(value)) {}

Cell& Cell::operator=(const Cell& other) {
    if (this != &other) {
        this->str = other.str;
    }
    return *this;
}

Cell& Cell::operator=(Cell&& other) noexcept {
    if (this != &other) {
        this->str = std::move(other.str);
    }
    return *this;
}

Cell::operator int() const {
    return std::stoi(str);
}

Cell::operator double() const {
    return std::stod(str);
}


Cell::operator std::string() const {
    return str;
}

std::ostream& operator<<(std::ostream& is,const Cell& rhv) {
    is << rhv.operator std::string();
    return is;
}

std::istream& operator>>(std::istream& is, Cell& rhv) {
    std::string input;
    is >> input;
    rhv = Cell(input); 
    return is;
} 