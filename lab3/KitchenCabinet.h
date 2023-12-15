#ifndef LAB2_KITCHEN_CABINET_H
#define LAB2_KITCHEN_CABINET_H

#include "Item.h"
#include "Vector.h"
#include <string>

class KitchenCabinet final : public Item {
private:
  std::string material;

public:
  const std::string get_material() const;
  void set_material(std::string value);

  KitchenCabinet();
  KitchenCabinet(const Vector &position, const Vector &size,
                 std::string material);
  KitchenCabinet(const KitchenCabinet &kitchenCabinet);

  ItemType type() const override;
  void show() const override;

  bool hasCollision(const Item &item) const override;
  bool isInAir() const override;
};

#endif