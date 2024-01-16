#include <iostream>

#include "KitchenCabinet.h"

void KitchenCabinet::set_material(std::string value) { material = value; }

void KitchenCabinet::set_position(const Vector &value) { position = value; }

void KitchenCabinet::set_size(const Vector &value) {
  if (value.get_x() > 0 && value.get_y() > 0 && value.get_z() > 0) {
    size = Vector(value);
  } else {
    std::cout << "Wrong size";
  }
}

const Vector KitchenCabinet::get_position() const { return position; }

const Vector KitchenCabinet::get_size() const { return size; }

const std::string KitchenCabinet::get_material() const { return material; }

KitchenCabinet::KitchenCabinet() {
  material = "wooden";
  position = Vector();
  size = Vector(1, 1, 1);
}

KitchenCabinet::KitchenCabinet(std::string material, const Vector &position,
                               const Vector &size) {
  this->material = material;
  this->position = Vector(position);
  this->size = Vector(size);
}

KitchenCabinet::KitchenCabinet(const KitchenCabinet &kitchen_cabinet) {
  this->material = kitchen_cabinet.material;
  this->position = Vector(kitchen_cabinet.position);
  this->size = Vector(kitchen_cabinet.size);
}

void KitchenCabinet::print_() const {
  std::cout << "Material:" << get_material() << std::endl;
  std::cout << "Position:";
  get_position().print_();
  std::cout << std::endl;
  std::cout << "Size:";
  get_size().print_();
  std::cout << std::endl;
}

bool KitchenCabinet::hasCollision(const KitchenCabinet &kitchen_cabinet) const {
  return (((abs(get_position().get_x() - kitchen_cabinet.position.get_x()) <
            get_size().get_x() + kitchen_cabinet.size.get_x()) &&
           (abs(get_position().get_y() - kitchen_cabinet.position.get_y()) <
            get_size().get_y() + kitchen_cabinet.size.get_y()) &&
           (abs(get_position().get_z() - kitchen_cabinet.position.get_z()) <
            get_size().get_z() + kitchen_cabinet.size.get_z())) ||
          ((get_position().distance(kitchen_cabinet.get_position()) < 2 &&
            get_material() != kitchen_cabinet.get_material()) ||
           (get_material() == kitchen_cabinet.get_material())));
}

bool KitchenCabinet::isInAir() const { return get_position().get_z() != 0; }