#ifndef PUZZLEMAP_H
#define PUZZLEMAP_H

#include "MathTile.h"
#include "PuzzleNode.h"
#include <random>
#include <vector>

class PuzzleMap {
private:
  std::vector<PuzzleNode *> puzzles;
  int size;

public:
  int get_size() const;
  std::vector<PuzzleNode *> get_puzzles() const;

  void set_size(int value);
  void set_puzzles(const std::vector<PuzzleNode *> &puzzles);

  PuzzleMap();
  PuzzleMap(int size, const std::vector<PuzzleNode *> &puzzles);
  PuzzleMap(const PuzzleMap &puzzleMap);

  void show() const;

  void addPuzzle(PuzzleNode *puzzleNode);
  // void removePuzzleByPosition();

  void generatePuzzleMap();
  bool checkConnectionsInMap();
};

#endif