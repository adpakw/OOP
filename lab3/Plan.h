#ifndef LAB3_PLAN_H
#define LAB3_PLAN_H

#include "Item.h"
#include "Vector.h"
#include <iostream>
#include <vector>

class Plan {
private:
  Vector size;
  std::vector<Item *> items;

public:
  Vector get_size() const;
  void set_size(const Vector &value);

  std::vector<Item *> get_items() const;
  void set_items(const std::vector<Item *> &items);

  Plan();
  Plan(const Vector &size);
  Plan(const Vector &size, const std::vector<Item *> &items);
  Plan(const Plan &plan);

  void addItem(Item *item);
  void removeItemByNumber(int number);
  bool check() const;

  void show() const;
};

#endif