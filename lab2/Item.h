#ifndef LAB1_ENTITY_H
#define LAB1_ENTITY_H

#include "Geometry.h"

class Item {
protected:
    Geometry position;
    Geometry size;
public:
    const Geometry get_position() const;
    void set_position(const Geometry &value);

    const Geometry get_size() const;
    void set_size(const Geometry &value);

    Item();
    Item(const Geometry &position, const Geometry &size);
    Item(const Item &item);

    virtual std::string type() const;
    virtual void show();

    virtual bool isCollision(const Item &item);
};


#endif