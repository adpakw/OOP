#include <cassert>
#include <iostream>

#include "HomeAppliances.h"
#include "KitchenCabinet.h"
#include "Plan.h"
#include "Vector.h"

int main() {

  KitchenCabinet test = KitchenCabinet();
  assert(test.get_material() == "wood");

  assert(test.get_position().get_x() == 0);
  assert(test.get_position().get_y() == 0);
  assert(test.get_position().get_z() == 0);

  assert(test.get_size().get_x() == 1);
  assert(test.get_size().get_y() == 1);
  assert(test.get_size().get_z() == 1);

  test.set_material("wood");
  test.set_position(Vector(1, 2, 3));
  test.set_size(Vector(4, 5, 6));

  assert(test.get_material() == "wood");
  assert(test.get_position().get_x() == 1);
  assert(test.get_position().get_y() == 2);
  assert(test.get_position().get_z() == 3);

  assert(test.get_size().get_x() == 4);
  assert(test.get_size().get_y() == 5);
  assert(test.get_size().get_z() == 6);

  KitchenCabinet test2 =
      KitchenCabinet(Vector(1, 2, 3), Vector(4, 5, 6), "wood");

  assert(test2.get_material() == "wood");
  assert(test2.get_position().get_x() == 1);
  assert(test2.get_position().get_y() == 2);
  assert(test2.get_position().get_z() == 3);

  assert(test2.get_size().get_x() == 4);
  assert(test2.get_size().get_y() == 5);
  assert(test2.get_size().get_z() == 6);

  KitchenCabinet test3 = KitchenCabinet(test2);
  assert(test3.get_material() == test2.get_material());
  assert(test3.get_position().get_x() == test2.get_position().get_x());
  assert(test3.get_position().get_y() == test2.get_position().get_y());
  assert(test3.get_position().get_z() == test2.get_position().get_z());

  assert(test3.get_size().get_x() == test2.get_size().get_x());
  assert(test3.get_size().get_y() == test2.get_size().get_y());
  assert(test3.get_size().get_z() == test2.get_size().get_z());

  KitchenCabinet one = KitchenCabinet(Vector(), Vector(1, 1, 1), "wood");

  KitchenCabinet two = KitchenCabinet(Vector(), Vector(2, 2, 2), "metal");

  KitchenCabinet three =
      KitchenCabinet(Vector(10, 10, 0), Vector(1, 1, 1), "plastic");

  KitchenCabinet four =
      KitchenCabinet(Vector(1.5, 0, 0), Vector(0.1, 0.1, 0.1), "plastic");

  assert(one.hasCollision(two) == 1);
  assert(one.hasCollision(three) == 0);
  assert(one.hasCollision(four) == 1);

  KitchenCabinet five =
      KitchenCabinet(Vector(5, 5, 5), Vector(2, 2, 2), "wood");
  assert(five.isInAir() == 1);

  KitchenCabinet six = KitchenCabinet(Vector(5, 5, 0), Vector(2, 2, 2), "wood");
  assert(six.isInAir() == 0);

  HomeAppliances appliance = HomeAppliances();
  assert(appliance.get_name() == "default" && appliance.get_state() == false);

  assert(appliance.get_position().get_x() == 0);
  assert(appliance.get_position().get_y() == 0);
  assert(appliance.get_position().get_z() == 0);

  assert(appliance.get_size().get_x() == 1);
  assert(appliance.get_size().get_y() == 1);
  assert(appliance.get_size().get_z() == 1);

  appliance.set_name("Fridge");
  appliance.changeState();
  appliance.set_position(Vector(1, 2, 3));
  appliance.set_size(Vector(4, 5, 6));

  assert(appliance.get_name() == "Fridge" && appliance.get_state() == true);

  assert(appliance.get_position().get_x() == 1);
  assert(appliance.get_position().get_y() == 2);
  assert(appliance.get_position().get_z() == 3);

  assert(appliance.get_size().get_x() == 4);
  assert(appliance.get_size().get_y() == 5);
  assert(appliance.get_size().get_z() == 6);

  HomeAppliances appliance2 =
      HomeAppliances(Vector(1, 2, 3), Vector(4, 5, 6), "Fridge", true);

  assert(appliance2.get_name() == "Fridge" && appliance2.get_state() == true);

  assert(appliance2.get_position().get_x() == 1);
  assert(appliance2.get_position().get_y() == 2);
  assert(appliance2.get_position().get_z() == 3);

  assert(appliance2.get_size().get_x() == 4);
  assert(appliance2.get_size().get_y() == 5);
  assert(appliance2.get_size().get_z() == 6);

  HomeAppliances appliance3 = HomeAppliances(appliance2);
  assert(appliance3.get_name() == appliance2.get_name());
  assert(appliance3.get_state() == appliance2.get_state());
  assert(appliance3.get_position().get_x() ==
         appliance2.get_position().get_x());
  assert(appliance3.get_position().get_y() ==
         appliance2.get_position().get_y());
  assert(appliance3.get_position().get_z() ==
         appliance2.get_position().get_z());

  assert(appliance3.get_size().get_x() == appliance2.get_size().get_x());
  assert(appliance3.get_size().get_y() == appliance2.get_size().get_y());
  assert(appliance3.get_size().get_z() == appliance2.get_size().get_z());

  HomeAppliances applianceThree =
      HomeAppliances(Vector(10, 10, 10), Vector(1, 1, 1), "Fridge", false);

  HomeAppliances applianceTwo =
      HomeAppliances(Vector(), Vector(2, 2, 2), "Fridge", false);

  HomeAppliances applianceFour =
      HomeAppliances(Vector(1.5, 0, 0), Vector(0.1, 0.1, 0.1), "Fridge", false);

  assert(one.hasCollision(applianceTwo) == true);
  assert(one.hasCollision(applianceThree) == false);
  assert(one.hasCollision(applianceFour) == true);

  Plan plan = Plan();

  plan.addItem(&one);
  plan.addItem(&two);
  plan.addItem(&applianceThree);
  plan.addItem(&five);

  assert(plan.get_size().get_x() == 1);
  assert(plan.get_size().get_y() == 1);
  assert(plan.get_size().get_z() == 1);
  assert(plan.get_items().size() == 4);

  plan.set_size(Vector(0.5, 0.5, 0.5));

  assert(plan.get_size().get_x() == 0.5);
  assert(plan.get_size().get_y() == 0.5);
  assert(plan.get_size().get_z() == 0.5);

  Plan plan2 = Plan(Vector(5, 5, 5));

  plan2.set_items(plan.get_items());

  plan2.removeItemByNumber(0);

  assert(plan2.get_items().size() == 3);

  assert(plan.check() == false);
  assert(plan2.check() == true);

  std::cout << "All testes has completed successfully" << std::endl;
  return 0;
}
