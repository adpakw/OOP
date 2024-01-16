#include "Library.h"
#include <iostream>

void Library::add_Book(Book *book) { books.push_back(book); }
void Library::add_Journal(Journal *journal) { journals.push_back(journal); }

Library::Library() {
  books = std::vector<Book *>();
  journals = std::vector<Journal *>();
}
Library::Library(const Library &library) {
  std::copy(library.books.begin(), library.books.end(), this->books.begin());
  std::copy(library.journals.begin(), library.journals.end(),
            this->journals.begin());
}

void Library::show(int days) const {
  if (days <= 14) {
    std::cout << "Library" << std::endl;
    for (auto it = books.begin(); it != books.end(); ++it) {
      (*it)->show();
    }
    for (auto it = journals.begin(); it != journals.end(); ++it) {
      (*it)->show();
    }
  } else {
    std::cout << "You don't have access!" << std::endl;
  }
}