
#ifndef LAB4_POSTOFFICE_H
#define LAB4_POSTOFFICE_H


#include <istream>

class PostOffice {
private:
    int index;
    int mails;
public:
    const int getIndex() const;
    const int getMails() const;

    PostOffice();
    PostOffice(int index, int mails);

    bool operator == (const PostOffice &postOffice) const;

    friend std::ostream& operator<<(std::ostream &os, const PostOffice &postOffice);
    friend  std::istream& operator>>(std::istream &is, PostOffice &postOffice);
};


#endif 