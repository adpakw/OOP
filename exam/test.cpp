#include <iostream>
#include <map>
#include <string>
#include <vector>

// Базовый класс для публикаций
class Publication {
protected:
  std::string title;
  int year;

public:
  Publication(std::string title, int year) : title(title), year(year) {}
  virtual ~Publication() {}

  virtual void
  display() = 0; // Чисто виртуальная функция для отображения информации
};

// Класс для книги
class Book : public Publication {
  std::vector<std::string> authors;
  std::vector<std::string> chapters;

public:
  Book(std::string title, int year, std::vector<std::string> authors,
       std::vector<std::string> chapters)
      : Publication(title, year), authors(authors), chapters(chapters) {}

  void display() override {
    std::cout << "Book: " << title << " (" << year << ")\nAuthors: ";
    for (const auto &author : authors) {
      std::cout << author << " ";
    }
    std::cout << "\nChapters: ";
    for (const auto &chapter : chapters) {
      std::cout << chapter << " ";
    }
    std::cout << std::endl;
  }
};

// Класс для статьи
class Article {
  std::vector<std::string> authors;
  std::string title;

public:
  Article(std::vector<std::string> authors, std::string title)
      : authors(authors), title(title) {}

  void display() {
    std::cout << "Article: " << title << "\nAuthors: ";
    for (const auto &author : authors) {
      std::cout << author << " ";
    }
    std::cout << std::endl;
  }
};

// Класс для журнала
class Journal : public Publication {
  int issue;
  std::vector<Article> articles;

public:
  Journal(std::string title, int year, int issue, std::vector<Article> articles)
      : Publication(title, year), issue(issue), articles(articles) {}

  void display() override {
    std::cout << "Journal: " << title << " (" << year << "), Issue " << issue
              << std::endl;
    for (const auto &article : articles) {
      article.display();
    }
  }
};

// Класс для управления библиотекой
class Library {
  std::vector<Book> books;
  std::vector<Journal> journals;

public:
  void addBook(const Book &book) { books.push_back(book); }

  void addJournal(const Journal &journal) { journals.push_back(journal); }

  void displayAll() {
    for (const auto &book : books) {
      book.display();
    }
    for (const auto &journal : journals) {
      journal.display();
    }
  }

  // Дополнительные методы для управления доступом
};

int main() {
  // Пример использования
  Library library;
  library.addBook(
      Book("Book1", 2020, {"Author1", "Author2"}, {"Chapter1", "Chapter2"}));
  library.addJournal(
      Journal("Journal1", 2021, 1, {Article({"Author3"}, "Article1")}));

  library.displayAll();

  return 0;
}
