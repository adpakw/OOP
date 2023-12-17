#ifndef PUZZLENODE_H
#define PUZZLENODE_H

#include "MathTile.h"

class PuzzleNode final : public MathTile {
private:
  PuzzleNode *topNode;
  PuzzleNode *rightNode;
  PuzzleNode *bottomNode;
  PuzzleNode *leftNode;

public:
  PuzzleNode *get_topNode() const;
  PuzzleNode *get_rightNode() const;
  PuzzleNode *get_bottomNode() const;
  PuzzleNode *get_leftNode() const;

  void set_topNode(PuzzleNode *puzzleNode);
  void set_rightNode(PuzzleNode *puzzleNode);
  void set_bottomNode(PuzzleNode *puzzleNode);
  void set_leftNode(PuzzleNode *puzzleNode);

  PuzzleNode();
  PuzzleNode(int top, int right, int bottom, int left, bool convex,
             PuzzleNode *topNode, PuzzleNode *rightNode, PuzzleNode *bottomNode,
             PuzzleNode *leftNode);
  PuzzleNode(const PuzzleNode &puzzleNode);

  void show() const override;
  void rotate(int angle);

  bool check(PuzzleNode *puzzleNode) const;
};

#endif