#include "Journal.h"
#include <iostream>

const std::string Journal::get_title() const { return title; }

const int Journal::get_year() const { return year; }

void Journal::set_title(std::string value) { title = value; }

void Journal::set_year(int value) { year = value; }

std::vector<Article *> Journal::get_articles() const { return articles; }

void Journal::set_articles(const std::vector<Article *> &articles) {
  this->articles = articles;
}

void Journal::append_article(Article *article) { articles.push_back(article); }

Journal::Journal() {
  title = "default";
  year = 0;
  articles = std::vector<Article *>();
}
Journal::Journal(std::string title, int year,
                 const std::vector<Article *> &articles) {
  this->title = title;
  this->year = year;
  this->articles = articles;
}
Journal::Journal(const Journal &journal) {
  this->title = journal.get_title();
  this->year = journal.get_year();
  this->articles = journal.get_articles();
}

void Journal::show() const {
  std::cout << "title: " << get_title() << "\nyear = " << get_year()
            << "\narticles: " << std::endl;
  for (auto it = articles.begin(); it != articles.end(); ++it) {
    (*it)->show();
  }
}