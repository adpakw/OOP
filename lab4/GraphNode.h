#ifndef LAB4_GRAPHNODE_H
#define LAB4_GRAPHNODE_H

#include <iostream>
#include <vector>

template <typename Key, typename Value> class GraphNode {
private:
  Key key;
  Value value;

  std::vector<GraphNode<Key, Value>> nodes;
  std::vector<int> costs;

public:
  Key getKey() const { return key; }

  void setKey(const Key &value) { this->key = value; }

  Value getValue() const { return value; }

  void setValue(const Value &value) { this->value = value; }

  std::vector<GraphNode<Key, Value>> getNodes() const { return nodes; }

  std::vector<int> getCosts() const { return costs; }

  GraphNode() {
    key = Key();
    value = Value();

    nodes = std::vector<GraphNode<Key, Value>>();
    costs = std::vector<int>();
  }

  GraphNode(const Key &key, const Value &value) {
    this->key = key;
    this->value = value;

    nodes = std::vector<GraphNode<Key, Value>>();
    costs = std::vector<int>();
  }

  void addConnection(const GraphNode<Key, Value> &graphNode, int cost) {
    nodes.push_back(graphNode);
    costs.push_back(cost);
  }

  bool operator==(const GraphNode<Key, Value> &graphNode) {
    return key == graphNode.key && value == graphNode.value;
  }

  friend std::ostream &operator<<(std::ostream &os,
                                  const GraphNode<Key, Value> &graphNode) {
    os << graphNode.key << ' ' << graphNode.value << ' '
       << graphNode.nodes.size() << ' ';
    for (size_t i = 0; i < graphNode.nodes.size(); ++i) {
      os << graphNode.nodes[i] << ' ' << graphNode.costs[i] << ' ';
    }
    os << '\n';
    return os;
  }

  friend std::istream &operator>>(std::istream &is,
                                  GraphNode<Key, Value> &graphNode) {
    is >> graphNode.key >> graphNode.value;
    int nodeCount;
    is >> nodeCount;
    graphNode.nodes.resize(nodeCount);
    graphNode.costs.resize(nodeCount);
    for (int i = 0; i < nodeCount; ++i) {
      is >> graphNode.nodes[i] >> graphNode.costs[i];
    }
    return is;
  }
};

#endif