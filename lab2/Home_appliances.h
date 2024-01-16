#ifndef LAB2_HOME_APPLIANCE_H
#define LAB2_HOME_APPLIANCE_H

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
    Home_appliances(const Geometry &position, const Geometry &size, std::string name,bool state);
    Home_appliances(const Home_appliances &home_appliances);

    std::string type() const override;
    void show() override;

    void changeState();
};


#endif