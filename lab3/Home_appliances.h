#ifndef LAB3_HOME_APPLIANCE_H
#define LAB3_HOME_APPLIANCE_H

#include <string>
#include "Item.h"

class Home_appliances final : public Item{
private:
    std::string name;
    bool state;
public:
    const std::string get_name() const;
    void set_name(std::string value);
    const bool get_state() const;
    void set_state(bool state);

    Home_appliances();
    Home_appliances(const Vector &position, const Vector &size, std::string name,bool state);
    Home_appliances(const Home_appliances &home_appliances);

    ItemType type() const override;
    void show() const override;

    void changeState();
};


#endif