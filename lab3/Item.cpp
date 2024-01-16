#include "Item.h"
#include <iostream>

const Vector Item::get_position() const { return position; }

void Item::set_position(const Vector &value) { position = value; }

const Vector Item::get_size() const { return size; }

void Item::set_size(const Vector &value) {
  if (value.get_x() > 0 && value.get_y() > 0 && value.get_z() > 0) {
    size = Vector(value);
  } else {
    std::cout << "Inappropriate value";
  }
}

Item::Item() {
  position = Vector();
  size = Vector(1, 1, 1);
}

Item::Item(const Vector &position, const Vector &size) {
  this->position = Vector(position);
  this->size = Vector(size);
}

Item::Item(const Item &item) {
  this->position = Vector(item.position);
  this->size = Vector(item.size);
}

ItemType Item::type() const { return ItemType::TItem; }

void Item::show() const {
  std::cout << GetItemTypeString(type()) << std::endl;
  std::cout << "Position is ";
  get_position().print_();
  std::cout << std::endl;

  std::cout << "Size is ";
  get_size().print_();
  std::cout << std::endl;
}

bool Item::hasCollision(const Item &item) const {
  return ((abs(get_position().get_x() - item.position.get_x()) <
           get_size().get_x() + item.size.get_x()) &&
          (abs(get_position().get_y() - item.position.get_y()) <
           get_size().get_y() + item.size.get_y()) &&
          (abs(get_position().get_z() - item.position.get_z()) <
           get_size().get_z() + item.size.get_z()));
}

bool Item::isInAir() const { return get_position().get_z() != 0; }