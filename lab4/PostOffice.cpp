#include "PostOffice.h"

const int PostOffice::getIndex() const { return index; }

const int PostOffice::getMails() const { return mails; }

PostOffice::PostOffice() {
  index = 0;
  mails = 0;
}

PostOffice::PostOffice(int index, int mails) {
  this->index = index;
  this->mails = mails;
}

bool PostOffice::operator==(const PostOffice &postOffice) const {
  return index == postOffice.index && mails == postOffice.mails;
}

std::ostream &operator<<(std::ostream &os, const PostOffice &postOffice) {
  os << postOffice.index << ' ' << postOffice.mails << '\n';
  return os;
}

std::istream &operator>>(std::istream &is, PostOffice &postOffice) {
  is >> postOffice.index >> postOffice.mails;
  return is;
}