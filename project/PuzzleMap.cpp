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

void PuzzleMap::show() const {
  for (int i = 0; i < puzzles.size(); i++) {
    if (i == 0) {
      std::cout << i << " PuzzleNode" << std::endl;
    } else {
      std::cout << std::endl << i << " PuzzleNode" << std::endl;
    }
    puzzles[i]->show();
  }
}

void PuzzleMap::removePuzzleByPosition(int x, int y) {
  puzzles[x * size + y]->disconnectNode(puzzles[x * size + y]->get_topNode(),
                                        "top");
  puzzles[x * size + y]->disconnectNode(puzzles[x * size + y]->get_rightNode(),
                                        "right");
  puzzles[x * size + y]->disconnectNode(puzzles[x * size + y]->get_bottomNode(),
                                        "bottom");
  puzzles[x * size + y]->disconnectNode(puzzles[x * size + y]->get_leftNode(),
                                        "left");
  puzzles.erase(puzzles.begin() + (x * size + y));
}

void PuzzleMap::generatePuzzleMap() {
  if (!get_puzzles().empty()) {
    puzzles.clear();
  }
  std::random_device rd;
  std::mt19937 mt(rd());
  if (size == 1) {
    std::uniform_int_distribution<int> dist(1, 100);
    PuzzleNode buf = PuzzleNode(dist(mt), dist(mt), dist(mt), dist(mt), false,
                                nullptr, nullptr, nullptr, nullptr);
    addPuzzle(&buf);
  } else {
    std::uniform_int_distribution<int> dist(1, (size - 1) * size * 2);

    std::vector<int> randomNumbers((size - 1) * size * 2);

    for (int &number : randomNumbers) {
      number = dist(mt);
    }
    std::uniform_int_distribution<int> dist1(1, (size - 1) * size * 2 * 10);
    PuzzleNode nodeStorage[size * size + 1];
    for (int i = 0; i < size * size; i++) {
      nodeStorage[i] = PuzzleNode(dist1(mt), dist1(mt), dist1(mt), dist1(mt),
                                  i % 2, nullptr, nullptr, nullptr, nullptr);
      puzzles.push_back(&nodeStorage[i]);
    }
    int g = 0;
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        if (i != size - 1 && j != size - 1) {
          puzzles[i * size + j]->connectNode(puzzles[i * size + j + 1], "right",
                                             randomNumbers[g]);
          g++;
          puzzles[i * size + j]->connectNode(puzzles[(i + 1) * size + j],
                                             "bottom", randomNumbers[g]);
          g++;
        }
        if (i != size - 1 && j == size - 1) {
          puzzles[i * size + j]->connectNode(puzzles[(i + 1) * size + j],
                                             "bottom", randomNumbers[g]);
          g++;
        }
        if (i == size - 1 && j != size - 1) {
          puzzles[i * size + j]->connectNode(puzzles[i * size + j + 1], "right",
                                             randomNumbers[g]);
          g++;
        }
      }
    }
  }
}

bool PuzzleMap::checkConnectionsInMap() const {
  int result = 0;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (i != size - 1 && j != size - 1) {
        result += (int)puzzles[i * size + j]->checkConnection(
            puzzles[i * size + j + 1], "right");
        result += (int)puzzles[i * size + j]->checkConnection(
            puzzles[(i + 1) * size + j], "bottom");
      }
      if (i != size - 1 && j == size - 1) {
        result += (int)puzzles[i * size + j]->checkConnection(
            puzzles[(i + 1) * size + j], "bottom");
      }
      if (i == size - 1 && j != size - 1) {
        result += (int)puzzles[i * size + j]->checkConnection(
            puzzles[i * size + j + 1], "right");
      }
    }
  }
  return result == (size - 1) * 2 * size;
}

