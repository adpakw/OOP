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

bool PuzzleNode::checkToConnect(PuzzleNode *puzzleNode,
                                std::string position) const {
  bool result = false;
  if (position == "top") {
    if (get_topNode() == nullptr && puzzleNode->get_bottomNode() == nullptr &&
        get_top() == puzzleNode->get_bottom() &&
        get_convex() != puzzleNode->get_convex()) {
      result = true;
    }
  } else if (position == "right") {
    if (get_rightNode() == nullptr && puzzleNode->get_leftNode() == nullptr &&
        get_right() == puzzleNode->get_left() &&
        get_convex() != puzzleNode->get_convex()) {
      result = true;
    }
  } else if (position == "bottom") {
    if (get_bottomNode() == nullptr && puzzleNode->get_topNode() == nullptr &&
        get_bottom() == puzzleNode->get_top() &&
        get_convex() != puzzleNode->get_convex()) {
      result = true;
    }
  } else if (position == "left") {
    if (get_leftNode() == nullptr && puzzleNode->get_rightNode() == nullptr &&
        get_left() == puzzleNode->get_right() &&
        get_convex() != puzzleNode->get_convex()) {
      result = true;
    }
  } else {
    std::cout << "Inappropriate value" << std::endl;
  }
  return result;
}

bool PuzzleNode::checkConnection(PuzzleNode *puzzleNode,
                                 std::string position) const {
  bool result = false;
  if (position == "top") {
    if (get_top() == puzzleNode->get_bottom() &&
        get_convex() != puzzleNode->get_convex()) {
      result = true;
    }
  } else if (position == "right") {
    if (get_right() == puzzleNode->get_left() &&
        get_convex() != puzzleNode->get_convex()) {
      result = true;
    }
  } else if (position == "bottom") {
    if (get_bottom() == puzzleNode->get_top() &&
        get_convex() != puzzleNode->get_convex()) {
      result = true;
    }
  } else if (position == "left") {
    if (get_left() == puzzleNode->get_right() &&
        get_convex() != puzzleNode->get_convex()) {
      result = true;
    }
  } else {
    std::cout << "Inappropriate value" << std::endl;
  }
  return result;
}

void PuzzleNode::makeConnection(PuzzleNode *puzzleNode, std::string position,
                                int value) {

  if (position == "top") {
    set_top(value);
    set_topNode(puzzleNode);
    puzzleNode->set_bottom(value);
    puzzleNode->set_bottomNode(this);
  } else if (position == "right") {
    set_right(value);
    set_rightNode(puzzleNode);
    puzzleNode->set_left(value);
    puzzleNode->set_leftNode(this);
  } else if (position == "bottom") {
    set_bottom(value);
    set_bottomNode(puzzleNode);
    puzzleNode->set_top(value);
    puzzleNode->set_topNode(this);
  } else if (position == "left") {
    set_left(value);
    set_leftNode(puzzleNode);
    puzzleNode->set_right(value);
    puzzleNode->set_rightNode(this);
  }
}

void PuzzleNode::connectNode(PuzzleNode *puzzleNode, std::string position) {
  if (position == "top") {
    set_topNode(puzzleNode);
    puzzleNode->set_bottomNode(this);
  } else if (position == "right") {
    set_rightNode(puzzleNode);
    puzzleNode->set_leftNode(this);
  } else if (position == "bottom") {
    set_bottomNode(puzzleNode);
    puzzleNode->set_topNode(this);
  } else if (position == "left") {
    set_leftNode(puzzleNode);
    puzzleNode->set_rightNode(this);
  }
}

void PuzzleNode::disconnectNode(PuzzleNode *puzzleNode, std::string position) {
  if (position == "top") {
    set_topNode(nullptr);
    puzzleNode->set_bottomNode(nullptr);
  } else if (position == "right") {
    set_rightNode(nullptr);
    puzzleNode->set_leftNode(nullptr);
  } else if (position == "bottom") {
    set_bottomNode(nullptr);
    puzzleNode->set_topNode(nullptr);
  } else if (position == "left") {
    set_leftNode(nullptr);
    puzzleNode->set_rightNode(nullptr);
  }
}
