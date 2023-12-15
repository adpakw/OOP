#include <string>
// #include <vector>
#include "Plan.h"

#include "ItemType.h"

bool Plan::check() {
    bool result = true;
    if(items.size()==1){
        return result;
    }
    for (int i = 0; i < items.size()-1; ++i) {
        for (int j = i + 1; j < items.size(); ++j) {
            if(items[i]->isCollision(*items[j])){
                result = false;
                break;
            }
        }
        if(result){
            break;
        }
    }

    if(result){
        for (int i = 0; i < items.size(); ++i) {
            if(items[i]->type()==ItemType::TAppliance){
                if(items[i]->get_position().get_y()==0){
                    result = false;
                    break;
                }
            }
        }
        if(result){
            for(auto item: items){
                double min_x = 0;
                double max_x = size.get_x();
                double min_y = 0;
                double max_y = size.get_y();
                double min_z = 0;
                double max_z = size.get_z();

                auto pos = item->get_position();
                auto size = item->get_size();

                double other_min_x = pos.get_x() - size.get_x();
                double other_max_x = pos.get_x() + size.get_x();
                double other_min_y = pos.get_y() - size.get_y();
                double other_max_y = pos.get_y() + size.get_y();
                double other_min_z = pos.get_z() - size.get_z();
                double other_max_z = pos.get_z() + size.get_z();

                if(min_x >= other_min_x && max_x <= other_max_x &&
                   min_y >= other_min_y && max_y <= other_max_y &&
                   min_z >= other_min_z && max_z <= other_max_z){
                    result = false;
                    break;
                }
            }
        }
    }
    return result;
}

Vector Plan::get_size() const {
    return size;
}

void Plan::set_size(const Vector &value) {
    if(value.get_x()>0 && value.get_y()>0 && value.get_z()>0){
        size =  Vector(value);
    }
    else{
        std::cout<<"Inappropriate value";
    }
}

std::vector<Item*> Plan::get_items() const {
    return items;
}

void Plan::addItem(Item *entity) {
    items.push_back(entity);
}

void Plan::removeItemByNumber(int number) {
    items.erase(items.cbegin()+number);
}

Plan::Plan() {
    size = Vector(1, 1, 1);
    items = std::vector<Item*>();
}

Plan::Plan(const Vector &size, const std::vector<Item*> &items) {
    this->size = size;
    this->items = items;
}

Plan::Plan(const Plan &plan) {
    this->size = Vector(plan.size);
    std::copy(plan.items.begin(), plan.items.end(), this->items.begin());
}

Plan::Plan(const Vector &size) {
    this->size = size;
    items = std::vector<Item*>();
}

void Plan::set_items(const std::vector<Item*> &items) {
    this->items = items;
}

void Plan::show() const {
    std::cout<<"Plan"<<std::endl;

    std::cout<<"Size is ";
    get_size().print_();
    std::cout<<std::endl;

    std::cout<<"Size of container is "<<items.size()<<std::endl;

    std::cout<<std::endl;

    for(auto item: items){
        item->show();
    }
}