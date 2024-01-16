#include "Book.h"
#include <iostream>

std::vector<std::string> Book::get_chapters() const { return chapters; }

void Book::set_chapters(const std::vector<std::string> &chapters) {
  this->chapters = chapters;
}

Book::Book() : Publication() { chapters = std::vector<std::string>(); }

Book::Book(std::string title, int year, const std::vector<std::string> &authors,
           const std::vector<std::string> &chapters)
    : Publication(title, year, authors) {
  this->chapters = chapters;
}

Book::Book(const Book &book) : Publication((Publication &)book) {
  this->chapters = book.get_chapters();
}

void Book::show() const {
  Publication::show();
  std::cout << "chapters: ";
  for (auto it = chapters.begin(); it != chapters.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}