#include <iostream>

#include "KitchenCabinet.h"

const std::string KitchenCabinet::get_material() const { return material; }

void KitchenCabinet::set_material(std::string value) { material = value; }

KitchenCabinet::KitchenCabinet() : Item() { material = "wood"; }

KitchenCabinet::KitchenCabinet(const Vector &position, const Vector &size,
                               std::string material)
    : Item(position, size) {
  this->material = material;
}

KitchenCabinet::KitchenCabinet(const KitchenCabinet &kitchenCabinet)
    : Item((Item &)kitchenCabinet) {
  this->material = kitchenCabinet.material;
}

ItemType KitchenCabinet::type() const { return ItemType::TCabinet; }

void KitchenCabinet::show() const {
  Item::show();
  std::cout << "Material is " << get_material() << std::endl;
  std::cout << std::endl;
}

bool KitchenCabinet::hasCollision(const Item &item) const {
  return (
      (Item::hasCollision(item)) ||
      (item.type() == ItemType::TCabinet &&
       ((get_position().distance(((KitchenCabinet &)item).get_position()) < 2 &&
         get_material() != ((KitchenCabinet &)item).get_material()) ||
        (get_material() == ((KitchenCabinet &)item).get_material()))));
}

bool KitchenCabinet::isInAir() const { return get_position().get_z() != 0; }