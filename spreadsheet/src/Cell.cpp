#include "../headers/Cell.h"

Cell::Cell(const Cell& rhv)
:val(rhv.val)
{}

Cell::Cell(Cell&& rhv)
:val(std::move(rhv.val))
{}

Cell::Cell(int value)
:val(std::to_string(value))
{}

Cell::Cell(double value)
:val(std::to_string(value))
{}

Cell::Cell(char value)
:val(std::to_string(value))
{}

Cell::Cell(bool value)
:val(std::to_string(value))
{}

Cell::Cell(std::string value)
:val(value)
{}


Cell::Cell(const std::vector<int>& value) 
{
    std::stringstream ss;
    for (const auto& num : value) 
    {
        ss << num << " ";
    }
    val = ss.str();
}

const Cell& Cell::operator=(const Cell& rhv)
{
    if(this != &rhv)
    {
        val = rhv.val;
    }
    return *this;
} 

const Cell& Cell::operator=(Cell&& rhv)
{
    if(this != &rhv)
    {
        val = std::move(rhv.val);
    }
    return *this;
} 

const Cell& Cell::operator=(int rhv) 
{
    val = std::to_string(rhv);
    return *this;
}
 

const Cell& Cell::operator=(double rhv)
{
    if (std::stod(val) != rhv)
    {
        val = std::to_string(rhv);
    }
    return *this;
}



const Cell& Cell::operator=(char rhv)
{
    val = std::to_string(rhv);
    return *this;
}


const Cell& Cell::operator=(bool rhv)
{
    val = rhv ? "true" : "false";
    return *this;
}


const Cell& Cell::operator=(std::string rhv)
{
    
       val = rhv;
    
    return *this;
} 

const Cell& Cell::operator=(const std::vector<int>& rhv)
{
    
        std::stringstream ss;
        for (const auto& num : val) 
        {
        ss << num << " ";
        }
        val = ss.str();
    
        return *this;
} 

Cell::operator int() const
{
    return std::stoi(val); 
}

Cell::operator double() const
{
    return std::stod(val); 
}

Cell::operator char() const
{
    return val.empty() ? '\0' : val[0];
}

Cell::operator bool() const
{
    return (val == "true") || (val == "1");
}

Cell::operator std::string() const
{
    return val; 
}


Cell::operator std::vector<int>() const
{
    std::vector<int> result;
    std::istringstream iss(val); 
    
    int num;
    while (iss >> num) {
        result.push_back(num);
    }
    
    return result;
}

std::string Cell::getValue() const 
{
        return val;
}

bool operator==(const Cell& lhv, const Cell& rhv) 
{
    return lhv.operator std::string() == rhv.operator std::string(); 
}

bool operator!=(const Cell& lhv, const Cell& rhv) 
{
    return !(lhv.operator std::string() == rhv.operator std::string()); 
}

std::ostream& operator<<(std::ostream& out, const Cell& ob)
{
   out << ob.operator std::string();
   return out;
}

std::istream& operator>>(std::istream& in, Cell& ob)
{
   std::string res;
   in >> res;
   ob = Cell(res);
   return in;
}
