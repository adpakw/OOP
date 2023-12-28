#ifndef BOOK_H
#define BOOK_H

#include "Publication.h"
#include <string>
#include <vector>

class Book final : public Publication {
private:
  std::vector<std::string> chapters;

public:
  std::vector<std::string> get_chapters() const;

  void set_chapters(const std::vector<std::string> &chapters);

  Book();
  Book(std::string title, int year, const std::vector<std::string> &authors,
       const std::vector<std::string> &chapters);
  Book(const Book &book);

  void show() const override;
};

#endif