#include "Publication.h"
#include <iostream>

const std::string Publication::get_title() const { return title; }

const int Publication::get_year() const { return year; }

std::vector<std::string> Publication::get_authors() const { return authors; }

void Publication::set_title(std::string value) { title = value; }

void Publication::set_year(int value) { year = value; }

void Publication::set_authors(const std::vector<std::string> &authors) {
  this->authors = authors;
}

Publication::Publication() {
  title = "default";
  year = 0;
  authors = std::vector<std::string>();
}

Publication::Publication(std::string title, int year,
                         const std::vector<std::string> &authors) {
  this->title = title;
  this->year = year;
  this->authors = authors;
}

Publication::Publication(const Publication &publication) {
  this->title = publication.get_title();
  this->year = publication.get_year();
  this->authors = publication.get_authors();
}

void Publication::show() const {
  std::cout << "title: " << get_title() << "\nyear = " << get_year()
            << "\nauthors = ";
  for (auto it = authors.begin(); it != authors.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}
