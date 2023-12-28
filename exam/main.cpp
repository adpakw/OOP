#include <cassert>
#include <iostream>

#include "Article.h"
#include "Book.h"
#include "Journal.h"
#include "Library.h"
#include "Publication.h"

int main() {
  Publication onePub = Publication();
  onePub.show();
  std::cout << std::endl;

  Publication twoPub =
      Publication("twoPub", 2023, {"Pak A.D.", "Pushkin A.S."});
  twoPub.show();
  std::cout << std::endl;

  Publication threePub = Publication(twoPub);
  threePub.set_title("threePub");
  threePub.show();
  std::cout << std::endl;

  Book oneBook = Book();
  oneBook.show();
  std::cout << std::endl;

  Book twoBook = Book("1984", 1949, {"George Orwell"},
                      {"Chapter 1", "Chapter 2", "Chapter 3", "Chapter 4"});
  twoBook.show();
  std::cout << std::endl;

  Book threeBook = Book(twoBook);
  threeBook.set_chapters({"Chapter 1", "Chapter 2", "Chapter 3"});
  threeBook.show();
  std::cout << std::endl;

  Article oneArt = Article();
  oneArt.show();
  std::cout << std::endl;

  Article twoArt =
      Article("Implementation of algorithms in ROS", 2024, {"Pak A.D."}, 12324);
  twoArt.show();
  std::cout << std::endl;

  Article threeArt = Article(oneArt);
  threeArt.set_number(987654);
  threeArt.show();
  std::cout << std::endl;

  Journal oneJour = Journal();
  oneJour.show();
  std::cout << std::endl;

  oneJour.set_title("ROS");
  oneJour.set_year(2024);
  oneJour.append_article(&oneArt);
  oneJour.append_article(&twoArt);
  oneJour.append_article(&threeArt);
  oneJour.show();
  std::cout << std::endl;

  Library oneLib = Library();
  oneLib.add_Book(&threeBook);
  oneLib.add_Journal(&oneJour);
  oneLib.show(7);

  std::cout << std::endl;
  oneLib.show(15);
  return 0;
}