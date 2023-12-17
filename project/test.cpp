#include <cassert>
#include <iostream>

#include "MathTile.h"

int main() {

  MathTile oneTile = MathTile();
  assert(oneTile.get_top() == 0);
  assert(oneTile.get_right() == 0);
  assert(oneTile.get_bottom() == 0);
  assert(oneTile.get_left() == 0);
  assert(oneTile.get_convex() == false);

  MathTile twoTile = MathTile(1, 2, 3, 4, true);
  assert(twoTile.get_top() == 1);
  assert(twoTile.get_right() == 2);
  assert(twoTile.get_bottom() == 3);
  assert(twoTile.get_left() == 4);
  assert(twoTile.get_convex() == true);

  MathTile threeTile = MathTile(twoTile);
  assert(threeTile.get_top() == 1);
  assert(threeTile.get_right() == 2);
  assert(threeTile.get_bottom() == 3);
  assert(threeTile.get_left() == 4);
  assert(threeTile.get_convex() == true);

  oneTile.set_top(9);
  oneTile.set_right(8);
  oneTile.set_bottom(7);
  oneTile.set_left(6);
  oneTile.set_convex(true);

  assert(oneTile.get_top() == 9);
  assert(oneTile.get_right() == 8);
  assert(oneTile.get_bottom() == 7);
  assert(oneTile.get_left() == 6);
  assert(oneTile.get_convex() == true);

  std::cout << "All testes has completed successfully" << std::endl;
  return 0;
}