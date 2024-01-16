#ifndef JOURNAL_H
#define JOURNAL_H

#include "Article.h"
#include <vector>

class Journal {
private:
  std::string title;
  int year;
  std::vector<Article *> articles;

public:
  const std::string get_title() const;
  const int get_year() const;
  std::vector<Article *> get_articles() const;

  void set_title(std::string value);
  void set_year(int value);
  void set_articles(const std::vector<Article *> &articles);

  void append_article(Article *article);

  Journal();
  Journal(std::string title, int year, const std::vector<Article *> &articles);
  Journal(const Journal &journal);

  void show() const;
};

#endif