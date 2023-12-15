#ifndef LAB4_GRAPH_H
#define LAB4_GRAPH_H

#include <string>
#include <map>
#include <queue>
#include <fstream>
#include <vector>
#include "GraphNode.h"

template <typename K, typename V>
class Graph {
private:
    std::vector<GraphNode<K, V>> nodes;
public:
    Graph() {
        nodes = std::vector<GraphNode<K, V>>();
    }

    Graph(const Graph<K, V> &graph) {
        for (auto item: graph.nodes) {
            nodes.push_back(item);
        }
    }

    ~Graph() {
        // вектор умеет сам распоряжаться данными
    }

    void clear() {
        this->nodes.clear();
    }

    int length() const{
        return nodes.size();
    }

    void saveFile(const std::string &filename){
        std::ofstream file(filename);
        if (file.is_open()) {
            for (const auto& node : nodes) {
                file << node;
            }
            file.close();
        } else {
            std::cerr << "Unable to open file: " << filename << std::endl;
        }
    }

    void readFile(const std::string &filename){
        std::ifstream file(filename);
        if (file.is_open()) {
            nodes.clear();
            GraphNode<K, V> node;
            while (file >> node) {
                nodes.push_back(node);
            }
            file.close();
        } else {
            std::cerr << "Unable to open file: " << filename << std::endl;
        }
    }

    void add(GraphNode<K, V> node) {
        if(std::find(nodes.begin(), nodes.end(), node)==nodes.end()){
            nodes.push_back(node);
        }
    }

    bool isContains(const K &key){
        for (int i = 0; i < nodes.size(); ++i) {
            if(nodes[i].getKey()==key){
                return true;
            }
        }
        return false;
    }

    int remove(const V &value){
        for (int i = 0; i < nodes.size(); ++i) {
            if(nodes[i].getValue()==value){
                nodes.erase(nodes.begin()+i, nodes.end()+i);
                return 1;
            }
        }
        return 0;
    }

    bool operator == (const Graph<K, V> &graph){
        if(length()!=graph.length()){
            return false;
        }
        Graph<K, V> temp = *this&&graph;
        return length()==temp.length();
    }

    bool operator != (const Graph<K, V> &graph){
        return ! (*this==graph);
    }

    V operator[](K key) {
        for (int i = 0; i < nodes.size(); ++i) {
            if (nodes[i].getKey() == key) {
                return nodes[i].getValue();
            }
        }

        nodes.push_back(GraphNode<K, V>(key, V()));
        return nodes.back().getValue();
    }

    Graph<K, V> operator&&(const Graph<K, V> &graph){
        Graph<K, V> result = Graph<K, V>();
        for (int i = 0; i < length(); ++i) {
            for (int j = 0; j < graph.length(); ++j) {
                if(nodes[i] == graph.nodes[j]){
                    result.add(nodes[i]);
                }
            }
        }
        return result;
    }

    std::vector<GraphNode<K, V>> path(const GraphNode<K, V> &startNode, const GraphNode<K, V> &endNode){
        std::vector<int> distances(nodes.size(), std::numeric_limits<int>::max());
        std::vector<GraphNode<K, V>> prev(nodes.size());

        auto itStart = std::find_if(nodes.begin(), nodes.end(), [&startNode](const auto& node) {
            return node.getKey() == startNode.getKey();
        });

        auto itEnd = std::find_if(nodes.begin(), nodes.end(), [&endNode](const auto& node) {
            return node.getKey() == endNode.getKey();
        });

        if (itStart != nodes.end() && itEnd != nodes.end()) {
            int startIdx = std::distance(nodes.begin(), itStart);
            distances[startIdx] = 0;

            std::priority_queue<std::pair<int, K>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
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
                    int neighborIdx = std::distance(nodes.begin(), std::find(nodes.begin(), nodes.end(), nodes[current].getNodes()[i]));
                    int newDistance = distances[current] + nodes[current].getCosts()[i];

                    if (newDistance < distances[neighborIdx]) {
                        distances[neighborIdx] = newDistance;
                        pq.push({newDistance, neighborIdx});
                        prev[neighborIdx] = nodes[current];
                    }
                }
            }
        }

        std::vector<GraphNode<K, V>> path = std::vector<GraphNode<K, V>>();
        int endIdx = std::distance(nodes.begin(), itEnd);
        while (endIdx > 0) {
            path.push_back(nodes[endIdx]);
            endIdx = std::distance(nodes.begin(), std::find(nodes.begin(), nodes.end(), prev[endIdx]));
        }
        path.push_back(startNode);
        std::reverse(path.begin(), path.end());

        return path;
    }
};


#endif