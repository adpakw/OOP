#ifndef LAB1_KITCHEN_CABINET_H
#define LAB1_KITCHEN_CABINET_H

#include "Vector.h"
#include <string>

class KitchenCabinet {
private:
  std::string material;
  Vector position;
  Vector size;

public:
  void set_material(std::string value);
  void set_position(const Vector &value);
  void set_size(const Vector &value);

  const std::string get_material() const;
  const Vector get_position() const;
  const Vector get_size() const;

  KitchenCabinet();
  KitchenCabinet(std::string material, const Vector &position,
                 const Vector &size);
  KitchenCabinet(const KitchenCabinet &kitchen_cabinet);

  void print_() const;
  bool hasCollision(const KitchenCabinet &kitchen_cabinet) const;
  bool isInAir() const;
};

#endif