#ifndef LAB3_ITEM_H
#define LAB3_ITEM_H

#include "Vector.h"
#include "ItemType.h"

class Item {
protected:
    Vector position;
    Vector size;
public:
    const Vector get_position() const;
    void set_position(const Vector &value);

    const Vector get_size() const;
    void set_size(const Vector &value);

    Item();
    Item(const Vector &position, const Vector &size);
    Item(const Item &item);

    virtual ItemType type() const;
    virtual void show() const;

    virtual bool isCollision(const Item &item) const;
    // virtual bool Item::is_in_air();
};


#endif