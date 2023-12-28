#ifndef PUBLICATION_H
#define PUBLICATION_H

#include <string>
#include <vector>

class Publication {
protected:
  std::string title;
  int year;
  std::vector<std::string> authors;

public:
  const std::string get_title() const;
  const int get_year() const;
  std::vector<std::string> get_authors() const;

  void set_title(std::string value);
  void set_year(int value);
  void set_authors(const std::vector<std::string> &authors);

  Publication();
  Publication(std::string title, int year,
              const std::vector<std::string> &authors);
  Publication(const Publication &publication);

  virtual void show() const;
};

#endif