#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include "Journal.h"
#include "Library.h"
#include <vector>

class Library {
private:
  std::vector<Book *> books;
  std::vector<Journal *> journals;

public:
  void add_Book(Book *book);
  void add_Journal(Journal *journal);

  Library();
  Library(const Library &library);

  void show(int days)
      const; // day - сколько дней прошло с момента выдачи прав доступа
};

#endif