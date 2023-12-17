#include <cassert>
#include <iostream>

#include "MathTile.h"
#include "PuzzleMap.h"
#include "PuzzleNode.h"

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

  threeTile.rotate(180);
  assert(threeTile.get_top() == 3);
  assert(threeTile.get_right() == 4);
  assert(threeTile.get_bottom() == 1);
  assert(threeTile.get_left() == 2);

  PuzzleNode oneNode = PuzzleNode();
  assert(oneNode.get_top() == 0);
  assert(oneNode.get_right() == 0);
  assert(oneNode.get_bottom() == 0);
  assert(oneNode.get_left() == 0);
  assert(oneNode.get_convex() == false);
  assert(oneNode.get_topNode() == nullptr);
  assert(oneNode.get_rightNode() == nullptr);
  assert(oneNode.get_bottomNode() == nullptr);
  assert(oneNode.get_leftNode() == nullptr);

  PuzzleNode twoNode =
      PuzzleNode(1, 0, 3, 4, true, nullptr, &oneNode, nullptr, nullptr);
  assert(twoNode.get_top() == 1);
  assert(twoNode.get_right() == 0);
  assert(twoNode.get_bottom() == 3);
  assert(twoNode.get_left() == 4);
  assert(twoNode.get_convex() == true);
  assert(twoNode.get_topNode() == nullptr);
  assert(twoNode.get_rightNode() == &oneNode);
  assert(twoNode.get_bottomNode() == nullptr);
  assert(twoNode.get_leftNode() == nullptr);

  PuzzleNode threeNode = PuzzleNode(twoNode);
  assert(threeNode.get_top() == 1);
  assert(threeNode.get_right() == 0);
  assert(threeNode.get_bottom() == 3);
  assert(threeNode.get_left() == 4);
  assert(threeNode.get_convex() == true);
  assert(threeNode.get_topNode() == nullptr);
  assert(threeNode.get_rightNode() == &oneNode);
  assert(threeNode.get_bottomNode() == nullptr);
  assert(threeNode.get_leftNode() == nullptr);

  threeNode.set_left(0);
  threeNode.set_right(2);
  threeNode.set_leftNode(&oneNode);
  threeNode.set_rightNode(nullptr);

  assert(threeNode.get_topNode() == nullptr);
  assert(threeNode.get_rightNode() == nullptr);
  assert(threeNode.get_bottomNode() == nullptr);
  assert(threeNode.get_leftNode() == &oneNode);
  assert(threeNode.get_leftNode() == twoNode.get_rightNode());

  threeNode.rotate(90);

  assert(threeNode.get_top() == 0);
  assert(threeNode.get_right() == 1);
  assert(threeNode.get_bottom() == 2);
  assert(threeNode.get_left() == 3);
  assert(threeNode.get_topNode() == &oneNode);
  assert(threeNode.get_rightNode() == nullptr);
  assert(threeNode.get_bottomNode() == nullptr);
  assert(threeNode.get_leftNode() == nullptr);

  PuzzleNode fourNode =
      PuzzleNode(2, 3, 9, 0, false, nullptr, nullptr, nullptr, nullptr);

  assert(fourNode.checkToConnect(&threeNode, "right") == 1);

  fourNode.connectNode(&threeNode, "right", threeNode.get_left());

  assert(fourNode.get_rightNode() == &threeNode);
  assert(threeNode.get_leftNode() == &fourNode);

  PuzzleMap oneMap = PuzzleMap();

  assert(oneMap.get_size() == 1);
  assert(oneMap.get_puzzles().size() == 0);
  oneMap.set_size(2);

  PuzzleMap twoMap = PuzzleMap();
  twoMap.set_size(3);
  twoMap.generatePuzzleMap();

  assert(twoMap.checkConnectionsInMap() == 1);
  assert(twoMap.get_puzzles().size() == 9);
  // twoMap.show();
  twoMap.removePuzzleByPosition(1, 1);
  // twoMap.show();
  assert(twoMap.get_puzzles().size() == 8);

  std::cout << "All testes has completed successfully" << std::endl;
  return 0;
}