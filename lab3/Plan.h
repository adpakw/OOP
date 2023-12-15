#ifndef LAB3_PLAN_H
#define LAB3_PLAN_H

#include <iostream>
#include <vector>
#include "Vector.h"
#include "Item.h"

class Plan {
private:
    Vector size;
    std::vector<Item*> items;

public:
    Vector get_size() const;
    void set_size(const Vector &value);

    Plan();
    Plan(const Vector &size);
    Plan(const Vector &size, const std::vector<Item*> &items);
    Plan(const Plan &plan);

    std::vector<Item*> get_items() const;
    void set_items(const std::vector<Item*> &items);

    void addItem(Item *item);
    void removeItemByNumber(int number);
    bool check();

    void show() const;
};


#endif