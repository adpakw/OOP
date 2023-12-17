#include "PuzzleMap.h"
#include <iostream>

int PuzzleMap::get_size() const { return size; }

std::vector<PuzzleNode *> PuzzleMap::get_puzzles() const { return puzzles; }

void PuzzleMap::set_size(int value) {
  if (value > 0) {
    size = value;
  } else {
    std::cout << "Inappropriate value" << std::endl;
  }
}
void PuzzleMap::set_puzzles(const std::vector<PuzzleNode *> &puzzles) {
  this->puzzles = puzzles;
}

PuzzleMap::PuzzleMap() {
  this->size = 1;
  puzzles = std::vector<PuzzleNode *>();
}

PuzzleMap::PuzzleMap(int size, const std::vector<PuzzleNode *> &puzzles) {
  this->size = size;
  this->puzzles = puzzles;
}

PuzzleMap::PuzzleMap(const PuzzleMap &puzzleMap) {
  this->size = puzzleMap.size;
  std::copy(puzzleMap.puzzles.begin(), puzzleMap.puzzles.end(),
            this->puzzles.begin());
}

void PuzzleMap::addPuzzle(PuzzleNode *puzzleNode) {
  puzzles.push_back(puzzleNode);
}

// void PuzzleMap::removePuzzleByPosition();

void PuzzleMap::generatePuzzleMap() {
  if (!get_puzzles().empty()) {
    std::cout << "sosi" << std::endl;
  } else {
    std::cout << "idi v zhopu" << std::endl;
  }
}