#include "Article.h"
#include <iostream>

const int Article::get_number() const { return number; }

void Article::set_number(int value) { number = value; }

Article::Article() : Publication() { number = 0; }
Article::Article(std::string title, int year,
                 const std::vector<std::string> &authors, int number)
    : Publication(title, year, authors) {
  this->number = number;
}
Article::Article(const Article &article) : Publication((Publication &)article) {
  this->number = article.get_number();
}

void Article::show() const {
  Publication::show();
  std::cout << "number = " << get_number() << std::endl;
}