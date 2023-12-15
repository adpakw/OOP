#ifndef LAB3_HOMEAPPLIANCE_H
#define LAB3_HOMEAPPLIANCE_H

#include "Item.h"
#include <string>

class HomeAppliances final : public Item {
private:
  std::string name;
  bool state;

public:
  const std::string get_name() const;
  void set_name(std::string value);
  const bool get_state() const;
  void set_state(bool state);

  HomeAppliances();
  HomeAppliances(const Vector &position, const Vector &size, std::string name,
                 bool state);
  HomeAppliances(const HomeAppliances &home_appliances);

  ItemType type() const override;
  void show() const override;
  void changeState();
};

#endif