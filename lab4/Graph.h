#ifndef LAB4_GRAPH_H
#define LAB4_GRAPH_H

#include <algorithm>
#include <fstream>
#include <limits>
#include <map>
#include <queue>
#include <string>

#include "GraphNode.h"

template <typename Key, typename Value> class Graph {
private:
  std::vector<GraphNode<Key, Value>> nodes;

public:
  Graph() { nodes = std::vector<GraphNode<Key, Value>>(); }

  Graph(const Graph<Key, Value> &graph) {
    for (auto item : graph.nodes) {
      nodes.push_back(item);
    }
  }

  ~Graph() = default;

  void clear() { this->nodes.clear(); }

  int length() const { return nodes.size(); }

  void saveFile(const std::string &filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
      for (const auto &node : nodes) {
        file << node;
      }
      file.close();
    } else {
      std::cerr << "Unable to open file: " << filename << std::endl;
    }
  }

  void readFile(const std::string &filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
      nodes.clear();
      GraphNode<Key, Value> node;
      while (file >> node) {
        nodes.push_back(node);
      }
      file.close();
    } else {
      std::cerr << "Unable to open file: " << filename << std::endl;
    }
  }

  void add(GraphNode<Key, Value> node) {
    if (std::find(nodes.begin(), nodes.end(), node) == nodes.end()) {
      nodes.push_back(node);
    }
  }

  bool isContains(const Key &key) {
    for (int i = 0; i < nodes.size(); ++i) {
      if (nodes[i].getKey() == key) {
        return true;
      }
    }
    return false;
  }

  int remove(const Value &value) {
    for (int i = 0; i < nodes.size(); ++i) {
      if (nodes[i].getValue() == value) {
        nodes.erase(nodes.begin() + i, nodes.end() + i);
        return 1;
      }
    }
    return 0;
  }

  bool operator==(const Graph<Key, Value> &graph) {
    if (length() != graph.length()) {
      return false;
    }
    Graph<Key, Value> temp = *this && graph;
    return length() == temp.length();
  }

  bool operator!=(const Graph<Key, Value> &graph) { return !(*this == graph); }

  Value operator[](Key key) {
    for (int i = 0; i < nodes.size(); ++i) {
      if (nodes[i].getKey() == key) {
        return nodes[i].getValue();
      }
    }

    add(GraphNode<Key, Value>(key, Value()));
    return nodes.back().getValue();
  }

  Graph<Key, Value> operator&&(const Graph<Key, Value> &graph) {
    Graph<Key, Value> result = Graph<Key, Value>();
    for (int i = 0; i < length(); ++i) {
      for (int j = 0; j < graph.length(); ++j) {
        if (nodes[i] == graph.nodes[j]) {
          result.add(nodes[i]);
        }
      }
    }
    return result;
  }

  std::vector<GraphNode<Key, Value>>
  path(const GraphNode<Key, Value> &startNode,
       const GraphNode<Key, Value> &endNode) {
    std::vector<int> distances(nodes.size(), std::numeric_limits<int>::max());
    std::vector<GraphNode<Key, Value>> prev(nodes.size());

    auto itStart = std::find_if(nodes.begin(), nodes.end(),
                                [&startNode](const auto &node) {
                                  return node.getKey() == startNode.getKey();
                                });

    auto itEnd =
        std::find_if(nodes.begin(), nodes.end(), [&endNode](const auto &node) {
          return node.getKey() == endNode.getKey();
        });

    if (itStart != nodes.end() && itEnd != nodes.end()) {
      int startIdx = std::distance(nodes.begin(), itStart);
      distances[startIdx] = 0;

      std::priority_queue<std::pair<int, Key>, std::vector<std::pair<int, int>>,
                          std::greater<std::pair<int, int>>>
          pq;
      pq.push({0, startIdx});

      while (!pq.empty()) {
        int current = pq.top().second;
        int currentDistance = pq.top().first;
        pq.pop();

        if (current == std::distance(nodes.begin(), itEnd)) {
          break;
        }

        if (currentDistance > distances[current]) {
          continue;
        }

        for (size_t i = 0; i < nodes[current].getNodes().size(); ++i) {
          int neighborIdx = std::distance(
              nodes.begin(), std::find(nodes.begin(), nodes.end(),
                                       nodes[current].getNodes()[i]));
          int newDistance = distances[current] + nodes[current].getCosts()[i];

          if (newDistance < distances[neighborIdx]) {
            distances[neighborIdx] = newDistance;
            pq.push({newDistance, neighborIdx});
            prev[neighborIdx] = nodes[current];
          }
        }
      }
    }

    std::vector<GraphNode<Key, Value>> path =
        std::vector<GraphNode<Key, Value>>();
    int endIdx = std::distance(nodes.begin(), itEnd);
    while (endIdx > 0) {
      path.push_back(nodes[endIdx]);
      endIdx = std::distance(
          nodes.begin(), std::find(nodes.begin(), nodes.end(), prev[endIdx]));
    }
    path.push_back(startNode);
    std::reverse(path.begin(), path.end());

    return path;
  }
};

#endif