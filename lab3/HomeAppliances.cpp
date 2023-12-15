#include "HomeAppliances.h"
#include <iostream>

const std::string HomeAppliances::get_name() const { return name; }

void HomeAppliances::set_name(std::string value) { name = value; }

const bool HomeAppliances::get_state() const { return state; }

void HomeAppliances::set_state(bool state) { this->state = state; }

HomeAppliances::HomeAppliances() : Item() {
  name = "default";
  this->state = false;
}

HomeAppliances::HomeAppliances(const Vector &position, const Vector &size,
                               std::string name, bool state)
    : Item(position, size) {
  this->name = name;
  this->state = state;
}

HomeAppliances::HomeAppliances(const HomeAppliances &home_appliances)
    : Item((Item &)home_appliances) {
  this->name = home_appliances.name;
  this->state = home_appliances.state;
}

ItemType HomeAppliances::type() const { return ItemType::TAppliance; }

void HomeAppliances::show() const {
  Item::show();
  std::cout << "Name is " << get_name() << std::endl;
  std::cout << "State is " << get_state() << std::endl;
  std::cout << std::endl;
}

void HomeAppliances::changeState() { state = !state; }
