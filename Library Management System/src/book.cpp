#include "../headers/book.h"

  std::string book::get_title() const
  {
      return m_title;
  }
  std::string book::get_author() const
  {
      return m_author;
  }
  int book::get_ID() const 
  {
      return m_ID;
  }
  
  void book::set_title(std::string title)
  {
     m_title=title;
  }
  void book::set_author(std::string author)
  {
     m_author=author;
  }
  void book::set_ID(int ID)
  {
     m_ID=ID;
  }