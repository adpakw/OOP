#include <iostream>
#include "Home_appliances.h"

const std::string Home_appliances::get_name() const {
    return name;
}

void Home_appliances::set_name(std::string value) {
    name = value;
}

const bool Home_appliances::get_state() const {
    return state;
}

void Home_appliances::set_state(bool state) {
    this->state = state;
}

Home_appliances::Home_appliances():
Item() {
    name="default";
    this->state = false;
}

Home_appliances::Home_appliances(const Geometry &position, const Geometry &size, std::string name, bool state):
Item(position, size)
{
    this->name = name;
    this->state = state;
}

Home_appliances::Home_appliances(const Home_appliances &home_appliances):
Item((Item&) home_appliances){
    this->name = home_appliances.name;
    this->state = home_appliances.state;
}

std::string Home_appliances::type() const {
    return "Appliance";
}

void Home_appliances::show() {
    Item::show();
    std::cout<<"Name is "<<get_name()<<std::endl;
    std::cout<<"State is "<<get_state()<<std::endl;
    std::cout<<std::endl;
}

void Home_appliances::changeState() {
    state = !state;
}
