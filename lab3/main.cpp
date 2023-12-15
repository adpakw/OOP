#include <iostream>
#include <cassert>

#include "Kitchen_cabinet.h"
#include "Home_appliances.h"
#include "Vector.h"
#include "Plan.h"

int main() {

    Kitchen_cabinet test = Kitchen_cabinet();
    assert(
            test.get_material()=="wood"&&

            test.get_position().get_x()==0 &&
            test.get_position().get_y()==0 &&
            test.get_position().get_z()==0 &&

            test.get_size().get_x()==1 &&
            test.get_size().get_y()==1 &&
            test.get_size().get_z()==1
    );

    test.set_material("wood");
    test.set_position( Vector(1, 2, 3));
    test.set_size( Vector(4, 5, 6));

    assert(
            test.get_material()=="wood" &&
            test.get_position().get_x()==1 &&
            test.get_position().get_y()==2 &&
            test.get_position().get_z()==3 &&

            test.get_size().get_x()==4 &&
            test.get_size().get_y()==5 &&
            test.get_size().get_z()==6
    );

    Kitchen_cabinet test2 = Kitchen_cabinet(
            Vector(1, 2, 3),
            Vector(4, 5, 6),
            "wood");

    assert(
            test2.get_material() == "wood" &&
            test2.get_position().get_x()==1 &&
            test2.get_position().get_y()==2 &&
            test2.get_position().get_z()==3 &&

            test2.get_size().get_x()==4 &&
            test2.get_size().get_y()==5 &&
            test2.get_size().get_z()==6
    );

    Kitchen_cabinet test3 = Kitchen_cabinet(test2);
    assert(
            test3.get_material()==test2.get_material() &&
            test3.get_position().get_x()==test2.get_position().get_x() &&
            test3.get_position().get_y()==test2.get_position().get_y() &&
            test3.get_position().get_z()==test2.get_position().get_z() &&

            test3.get_size().get_x()==test2.get_size().get_x() &&
            test3.get_size().get_y()==test2.get_size().get_y() &&
            test3.get_size().get_z()==test2.get_size().get_z()
    );


    Kitchen_cabinet one = Kitchen_cabinet(
            Vector(),
            Vector(1, 1, 1),
            "wood");

    Kitchen_cabinet two = Kitchen_cabinet(
            Vector(),
            Vector(2, 2, 2),
            "metal");

    Kitchen_cabinet three = Kitchen_cabinet(
            Vector(10, 10, 10),
            Vector(1, 1,1),
            "plastic");

    Kitchen_cabinet four = Kitchen_cabinet(
            Vector(1.5, 0, 0),
            Vector(0.1, 0.1, 0.1),
            "plastic");

    assert(one.isCollision(two)== true);
    assert(one.isCollision(three)== false);
    assert(one.isCollision(four)== true);

    Home_appliances appliance = Home_appliances();
    assert(
            appliance.get_name()=="default"&&
            appliance.get_state()== false&&

            appliance.get_position().get_x()==0 &&
            appliance.get_position().get_y()==0 &&
            appliance.get_position().get_z()==0 &&

            appliance.get_size().get_x()==1 &&
            appliance.get_size().get_y()==1 &&
            appliance.get_size().get_z()==1
    );

    appliance.set_name("Fridge");
    appliance.changeState();
    appliance.set_position( Vector(1, 2, 3));
    appliance.set_size( Vector(4, 5, 6));

    assert(
            appliance.get_name() == "Fridge" &&
            appliance.get_state() == true &&

            appliance.get_position().get_x()==1 &&
            appliance.get_position().get_y()==2 &&
            appliance.get_position().get_z()==3 &&

            appliance.get_size().get_x()==4 &&
            appliance.get_size().get_y()==5 &&
            appliance.get_size().get_z()==6
    );

    Home_appliances appliance2 = Home_appliances(
            Vector(1, 2, 3),
            Vector(4, 5, 6),
            "Fridge",
            true);

    assert(
            appliance2.get_name() == "Fridge" &&
            appliance2.get_state() == true &&

            appliance2.get_position().get_x()==1 &&
            appliance2.get_position().get_y()==2 &&
            appliance2.get_position().get_z()==3 &&

            appliance2.get_size().get_x()==4 &&
            appliance2.get_size().get_y()==5 &&
            appliance2.get_size().get_z()==6
    );

    Home_appliances appliance3 = Home_appliances(appliance2);
    assert(
            appliance3.get_name()==appliance2.get_name() &&
            appliance3.get_state()==appliance2.get_state() &&
            appliance3.get_position().get_x()==appliance2.get_position().get_x() &&
            appliance3.get_position().get_y()==appliance2.get_position().get_y() &&
            appliance3.get_position().get_z()==appliance2.get_position().get_z() &&

            appliance3.get_size().get_x()==appliance2.get_size().get_x() &&
            appliance3.get_size().get_y()==appliance2.get_size().get_y() &&
            appliance3.get_size().get_z()==appliance2.get_size().get_z()
    );

    Home_appliances applianceThree = Home_appliances(
            Vector(10, 10, 10),
            Vector(1, 1,1),
            "Fridge",
            false);

    Home_appliances applianceTwo = Home_appliances(
            Vector(),
            Vector(2, 2, 2),
            "Fridge",
            false);

    Home_appliances applianceFour = Home_appliances(
            Vector(1.5, 0, 0),
            Vector(0.1, 0.1, 0.1),
            "Fridge",
            false);

    assert(one.isCollision(applianceTwo) == true);
    assert(one.isCollision(applianceThree) == false);
    assert(one.isCollision(applianceFour) == true);

    Plan plan = Plan();

    plan.addItem(&one);
    plan.addItem(&two);
    plan.addItem(&applianceThree);

    assert(plan.get_size().get_x()==1);
    assert(plan.get_size().get_y()==1);
    assert(plan.get_size().get_z()==1);
    assert(plan.get_items().size() == 3);

    plan.set_size(Vector(0.5,0.5,0.5));

    assert(plan.get_size().get_x()==0.5);
    assert(plan.get_size().get_y()==0.5);
    assert(plan.get_size().get_z()==0.5);

    Plan plan2 = Plan(Vector(5,5,5));

    plan2.set_items(plan.get_items());

    plan2.removeItemByNumber(0);

    assert(plan2.get_items().size()==2);

    assert(plan.check() == false);
    assert(plan2.check() == true);

    std::cout<<"All testes has completed successfully"<<std::endl;

    return 0;
}
