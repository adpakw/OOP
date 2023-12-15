#ifndef LAB4_GRAPHNODE_H
#define LAB4_GRAPHNODE_H

#include <iostream>
#include <vector>

template <typename K, typename V>
class GraphNode {
private:
    K key;
    V value;

    std::vector<GraphNode<K, V>> nodes;
    std::vector<int> costs;
public:

    K getKey() const{
        return key;
    }

    void setKey(const K &value){
        this->key = value;
    }

    V getValue() const{
        return value;
    }

    void setValue(const V &value){
        this->value = value;
    }

    std::vector<GraphNode<K, V>> getNodes() const{
        return nodes;
    }

    std::vector<int> getCosts() const{
        return costs;
    }

    GraphNode(){
        key = K();
        value = V();

        nodes = std::vector<GraphNode<K, V>>();
        costs = std::vector<int>();
    }

    GraphNode(const K &key, const V &value){
        this->key = key;
        this->value = value;

        nodes = std::vector<GraphNode<K, V>>();
        costs = std::vector<int>();
    }

    void addConnection(const GraphNode<K, V> &graphNode, int cost){
        nodes.push_back(graphNode);
        costs.push_back(cost);
    }

    bool operator == (const GraphNode<K, V> &graphNode){
        return key==graphNode.key && value==graphNode.value;
    }

    friend std::ostream& operator<<(std::ostream &os, const GraphNode<K,V> &graphNode){
        os << graphNode.key << ' ' << graphNode.value << ' ' << graphNode.nodes.size() << ' ';
        for (size_t i = 0; i < graphNode.nodes.size(); ++i) {
            os << graphNode.nodes[i] << ' ' << graphNode.costs[i] << ' ';
        }
        os << '\n';
        return os;
    }

    friend  std::istream& operator>>(std::istream &is, GraphNode<K, V> &graphNode){
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