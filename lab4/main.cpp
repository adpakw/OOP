#include <iostream>
#include <cassert>

#include "Graph.h"
#include "PostOffice.h"



int main() {
    Graph<int, PostOffice> emptyGraph = Graph<int, PostOffice>();
    Graph<int, PostOffice> graph = Graph<int, PostOffice>();
    assert(graph.length()==0); //размер коллекции, созданной конструктором по умолчанию, равен нулю

    PostOffice postOffice1 = PostOffice(1, 0);
    PostOffice postOffice2 = PostOffice(2, 1);
    PostOffice postOffice3 = PostOffice(3, 3);

    GraphNode<int, PostOffice> node1 = GraphNode<int, PostOffice>(postOffice1.getIndex(), postOffice1);
    GraphNode<int, PostOffice> node2 = GraphNode<int, PostOffice>(postOffice2.getIndex(), postOffice2);
    GraphNode<int, PostOffice> node3 = GraphNode<int, PostOffice>(postOffice3.getIndex(), postOffice3);


    assert(node1.getKey()==1);
    assert(node1.getValue().getMails()==0);
    graph.add(node1);
    assert(graph.length()==1);//при добавлении нового значения размер коллекции, реализованной на множествах, увеличивается на единицу, а при добавлении имеющегося значения размер остаётся прежним;
    graph.add(node1);
    graph.add(node2);
    assert(graph.length()==2);

    graph.clear();

    assert(graph==emptyGraph);//непустая коллекция после удаления всех объектов равна коллекции, созданной при помощи конструктора по умолчанию;

    Graph<int, PostOffice> graph2 = Graph<int, PostOffice>();
    graph2.add(node2);
    graph2.add(node3);

    Graph<int, PostOffice> graph3 = graph&&graph2;
    assert(graph3==emptyGraph);//при пересечении любой коллекции с пустой, оператор && возвращает пустую коллекцию (any && empty == empty);
    assert(graph2==graph2);//при пересечении одинаковых коллекций, оператор && возвращает новую коллекцию, равную любой из них (any && any == any);

    graph.add(node1);
    graph.add(node2);
    Graph<int, PostOffice> graph4 = graph&&graph2;
    assert(graph4.isContains(node1.getKey())== false);
    assert(graph4.isContains(node2.getKey())== true);

    assert(graph4.remove(postOffice1)==0);
    assert(graph4.remove(postOffice2)==1);
    assert(graph4==emptyGraph);

    Graph<int, PostOffice> graphCopy = Graph<int, PostOffice>(graph);
    assert(graph==graphCopy);

    graph.add(node3);
    assert(graph!=graphCopy);//копия непустой коллекции равна оригиналу, после вставки, удаления или изменения элемента равенство нарушается;

    Graph<int, PostOffice> graph5 = Graph<int, PostOffice>();
    node1.addConnection(node2, 1);
    node2.addConnection(node1, 1);
    graph5.add(node1);
    graph5.add(node2);
    Graph<int, PostOffice> graph5Copy = Graph<int, PostOffice>(graph5);
    graph5.saveFile("file.txt");
    graph5.clear();
    graph5.readFile("file.txt");
    assert(graph5==graph5Copy);//непустая коллекция, сохранённая в файл, равна новой коллекции, загруженной из того же файла.


    PostOffice pathPO1 = PostOffice(1, 1);
    PostOffice pathPO2 = PostOffice(2, 0);
    PostOffice pathPO3 = PostOffice(3, 0);
    PostOffice pathPO4 = PostOffice(4, 0);
    PostOffice pathPO5 = PostOffice(5, 0);
    PostOffice pathPO6 = PostOffice(6, 0);

    GraphNode<int, PostOffice> pathGN1 = GraphNode<int, PostOffice>(pathPO1.getIndex(), pathPO1);
    GraphNode<int, PostOffice> pathGN2 = GraphNode<int, PostOffice>(pathPO2.getIndex(), pathPO2);
    GraphNode<int, PostOffice> pathGN3 = GraphNode<int, PostOffice>(pathPO3.getIndex(), pathPO3);
    GraphNode<int, PostOffice> pathGN4 = GraphNode<int, PostOffice>(pathPO4.getIndex(), pathPO4);
    GraphNode<int, PostOffice> pathGN5 = GraphNode<int, PostOffice>(pathPO5.getIndex(), pathPO5);
    GraphNode<int, PostOffice> pathGN6 = GraphNode<int, PostOffice>(pathPO6.getIndex(), pathPO6);

    pathGN1.addConnection(pathGN6, 14);
    pathGN6.addConnection(pathGN1, 14);

    pathGN1.addConnection(pathGN3, 9);
    pathGN3.addConnection(pathGN1, 9);

    pathGN1.addConnection(pathGN2, 7);
    pathGN2.addConnection(pathGN1, 7);

    pathGN6.addConnection(pathGN3, 2);
    pathGN3.addConnection(pathGN6, 2);

    pathGN2.addConnection(pathGN3, 10);
    pathGN3.addConnection(pathGN2, 10);

    pathGN2.addConnection(pathGN4, 15);
    pathGN4.addConnection(pathGN2, 15);

    pathGN3.addConnection(pathGN4, 11);
    pathGN4.addConnection(pathGN3, 11);

    pathGN6.addConnection(pathGN5, 9);
    pathGN5.addConnection(pathGN6, 9);

    pathGN4.addConnection(pathGN5, 6);
    pathGN5.addConnection(pathGN4, 6);

    Graph<int, PostOffice> graphPath = Graph<int, PostOffice>();
    graphPath.add(pathGN1);
    graphPath.add(pathGN2);
    graphPath.add(pathGN3);
    graphPath.add(pathGN4);
    graphPath.add(pathGN5);
    graphPath.add(pathGN6);

    Graph<int, PostOffice> graphPathCopy = Graph<int, PostOffice>(graphPath);

    assert(graphPath==graphPathCopy);

    std::vector<GraphNode<int, PostOffice>> path = graphPath.path(pathGN1, pathGN5);
    assert(path[0]==pathGN1);
    assert(path[1]==pathGN3);
    assert(path[2]==pathGN6);
    assert(path[3]==pathGN5);


    std::cout<<"All tests has completed successfully"<<std::endl;

    return 0;
}