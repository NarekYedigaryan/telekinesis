#ifndef LIBRARY_H
#define LIBRARY_H

#include "book.h"
#include <vector>
class library
{
private:
  std::vector<book> books;
public:
  void Add_book(book book);
  void Remove_book(book book);
  bool Find_book(std::string title);
  bool Find_book(std::string author);
};
#endif //LIBRARY_H