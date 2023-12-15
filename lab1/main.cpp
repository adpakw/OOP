#include <cassert>
#include <iostream>

#include "KitchenCabinet.h"
#include "Vector.h"

int main() {

  KitchenCabinet test = KitchenCabinet();
  assert(test.get_material() == "wooden");

  assert(test.get_position().get_x() == 0);
  assert(test.get_position().get_y() == 0);
  assert(test.get_position().get_z() == 0);

  assert(test.get_size().get_x() == 1);
  assert(test.get_size().get_y() == 1);
  assert(test.get_size().get_z() == 1);

  test.set_material("wooden");
  test.set_position(Vector(1, 2, 3));
  test.set_size(Vector(4, 5, 6));

  assert(test.get_material() == "wooden");
  assert(test.get_position().get_x() == 1);
  assert(test.get_position().get_y() == 2);
  assert(test.get_position().get_z() == 3);

  assert(test.get_size().get_x() == 4);
  assert(test.get_size().get_y() == 5);
  assert(test.get_size().get_z() == 6);

  KitchenCabinet test2 =
      KitchenCabinet("wood", Vector(1, 2, 3), Vector(4, 5, 6));

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

  KitchenCabinet one = KitchenCabinet("wood", Vector(), Vector(1, 1, 1));

  KitchenCabinet two = KitchenCabinet("metal", Vector(), Vector(2, 2, 2));

  KitchenCabinet three =
      KitchenCabinet("plastic", Vector(10, 10, 0), Vector(1, 1, 1));

  KitchenCabinet four =
      KitchenCabinet("plastic", Vector(1.5, 0, 0), Vector(0.1, 0.1, 0.1));

  assert(one.hasCollision(two) == 1);
  assert(one.hasCollision(three) == 0);
  assert(one.hasCollision(four) == 1);

  KitchenCabinet five =
      KitchenCabinet("wood", Vector(5, 5, 5), Vector(2, 2, 2));
  assert(five.isInAir() == 1);

  KitchenCabinet six = KitchenCabinet("wood", Vector(5, 5, 0), Vector(2, 2, 2));
  assert(six.isInAir() == 0);

  std::cout << "All testes has completed successfully" << std::endl;

  return 0;
}