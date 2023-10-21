#include <iostream>
#include <cassert>

#include "Kitchen_cabinet.h"
#include "Geometry.h"

int main() {

    Kitchen_cabinet test = Kitchen_cabinet();
    assert(
            test.get_material()=="wooden"&&

            test.get_position().get_x()==0 &&
            test.get_position().get_y()==0 &&
            test.get_position().get_z()==0 &&

            test.get_size().get_x()==1 &&
            test.get_size().get_y()==1 &&
            test.get_size().get_z()==1
    );

    test.set_material("wooden");
    test.set_position( Geometry(1, 2, 3));
    test.set_size( Geometry(4, 5, 6));

    assert(
            test.get_material()=="wooden" &&
            test.get_position().get_x()==1 &&
            test.get_position().get_y()==2 &&
            test.get_position().get_z()==3 &&

            test.get_size().get_x()==4 &&
            test.get_size().get_y()==5 &&
            test.get_size().get_z()==6
    );

    Kitchen_cabinet test2 = Kitchen_cabinet(
            "wood",
            Geometry(1, 2, 3),
            Geometry(4, 5, 6)
            );

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
            "wood",
            Geometry(),
            Geometry(1, 1, 1)
            );

    Kitchen_cabinet two = Kitchen_cabinet(
            "metal",
            Geometry(),
            Geometry(2, 2, 2)
            );

    Kitchen_cabinet three = Kitchen_cabinet(
            "plastic",
            Geometry(10, 10, 0),
            Geometry(1, 1, 1)
            );

    Kitchen_cabinet four = Kitchen_cabinet(
            "plastic",
            Geometry(1.5, 0, 0),
            Geometry(0.1, 0.1, 0.1)
            );

    assert(one.isCollision(two)==1);
    assert(one.isCollision(three)==0);
    assert(one.isCollision(four)==1);

    Kitchen_cabinet five = Kitchen_cabinet(
            "wood",
            Geometry(5, 5, 5),
            Geometry(2, 2, 2)
            );

    assert(five.is_in_air()==1);

    std::cout<<"All testes has completed successfully"<<std::endl;

    return 0;
}