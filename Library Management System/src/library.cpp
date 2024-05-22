  #include "../headers/library.h"
#include <iostream>

  void library::Add_book(book book)
  {
    books.push_back(book);
  }
  void library::Remove_book(book book)
  {
    for(auto it = books.begin(); it!=books.end();++ it)
    {
        if(it->get_author()==book.get_author() && it->get_ID()==book.get_ID() && it->get_title() == book.get_title())
        {
            books.erase(it);
            break;
        }
    }
  }
  bool library::Find_book(std::string title)
  {
    for(const auto& book : books)
    {
        if(book.get_title() == title)
        {
            return true;
        }
    }
    return false;
  }
  bool library::Find_book(std::string author)
  {
       for(const auto& book : books)
    {
        if(book.get_author() == author)
        {
            return true;
        }
    }
    return false;
  }