#include "PuzzleNode.h"
#include <iostream>

PuzzleNode *PuzzleNode::get_topNode() const { return topNode; }

PuzzleNode *PuzzleNode::get_rightNode() const { return rightNode; }

PuzzleNode *PuzzleNode::get_bottomNode() const { return bottomNode; }

PuzzleNode *PuzzleNode::get_leftNode() const { return leftNode; }

void PuzzleNode::set_topNode(PuzzleNode *puzzleNode) { topNode = puzzleNode; }

void PuzzleNode::set_rightNode(PuzzleNode *puzzleNode) {
  rightNode = puzzleNode;
}

void PuzzleNode::set_bottomNode(PuzzleNode *puzzleNode) {
  bottomNode = puzzleNode;
}

void PuzzleNode::set_leftNode(PuzzleNode *puzzleNode) { leftNode = puzzleNode; }

PuzzleNode::PuzzleNode() : MathTile() {
  topNode = nullptr;
  rightNode = nullptr;
  bottomNode = nullptr;
  leftNode = nullptr;
}

PuzzleNode::PuzzleNode(int top, int right, int bottom, int left, bool convex,
                       PuzzleNode *topNode, PuzzleNode *rightNode,
                       PuzzleNode *bottomNode, PuzzleNode *leftNode)
    : MathTile(top, right, bottom, left, convex) {
  this->topNode = topNode;
  this->rightNode = rightNode;
  this->bottomNode = bottomNode;
  this->leftNode = leftNode;
}

PuzzleNode::PuzzleNode(const PuzzleNode &puzzleNode)
    : MathTile((MathTile &)puzzleNode) {
  this->topNode = puzzleNode.topNode;
  this->rightNode = puzzleNode.rightNode;
  this->bottomNode = puzzleNode.bottomNode;
  this->leftNode = puzzleNode.leftNode;
}

void PuzzleNode::show() const {
  MathTile::show();
  std::cout << "topNode = " << get_topNode()
            << "\nrightNode = " << get_rightNode()
            << "\nbottomNode = " << get_bottomNode()
            << "\nleftNode = " << get_leftNode() << std::endl;
}

void PuzzleNode::rotate(int angle) {
  MathTile::rotate(angle);
  PuzzleNode *buf;
  switch (angle) {
  case (0):
    break;
  case (90):
    buf = get_topNode();
    set_topNode(get_leftNode());
    set_leftNode(get_bottomNode());
    set_bottomNode(get_rightNode());
    set_rightNode(buf);
    break;
  case (180):
    buf = get_topNode();
    set_topNode(get_bottomNode());
    set_bottomNode(buf);
    buf = get_leftNode();
    set_leftNode(get_rightNode());
    set_rightNode(buf);
    break;
  case (270):
    buf = get_topNode();
    set_topNode(get_rightNode());
    set_rightNode(get_bottomNode());
    set_bottomNode(get_leftNode());
    set_leftNode(buf);
    break;
  default:
    std::cout << "Inappropriate value" << std::endl;
    break;
  }
}

bool PuzzleNode::check(PuzzleNode *puzzleNode) const {
  return this == puzzleNode;
}
