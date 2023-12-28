#ifndef ARTICLE_H
#define ARTICLE_H

#include "Publication.h"

class Article final : public Publication {
private:
  int number;

public:
  const int get_number() const;

  void set_number(int value);

  Article();
  Article(std::string title, int year, const std::vector<std::string> &authors,
          int number);
  Article(const Article &article);

  void show() const override;
};

#endif