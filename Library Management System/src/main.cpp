#include <iostream>
#include "../headers/library.h"

int main() {
    library my_library;

    book book1, book2, book3;
    book1.set_title("Book 1");
    book1.set_author("Author 1");
    book1.set_ID(1);

    book2.set_title("Book 2");
    book2.set_author("Author 2");
    book2.set_ID(2);

    book3.set_title("Book 3");
    book3.set_author("Author 1");
    book3.set_ID(3);

    my_library.Add_book(book1);
    my_library.Add_book(book2);
    my_library.Add_book(book3);

    std::cout << "Books found by title:" << std::endl;
    if (my_library.Find_book("Book 1")) {
        std::cout << "Book found!" << std::endl;
    } else {
        std::cout << "Book not found!" << std::endl;
    }

    // Find books by author
    std::cout << "Books found by author:" << std::endl;
    if (my_library.Find_book("Author 2")) {
        std::cout << "Book found!" << std::endl;
    } else {
        std::cout << "Book not found!" << std::endl;
    }

    return 0;
}
