//
// Created by Luidgi Sarto on 24/10/2020.
//

#ifndef GRAPHTHEORYWORK_GRAPH_H
#define GRAPHTHEORYWORK_GRAPH_H

#include "Node.h"
#include "Edge.h"
#include <stdio.h>
#include <list>


using namespace std;

class Graph {
private:
    int order;
    int totalEdges;
    list<Node> *nodes;

public:
    Graph();
    ~Graph();
    Node* getNode(int id);
    list<Node> *getNodes();
    int getTotalEdges();
    bool hasNode(int id);
    Node * insertNode(int id);
    void insertEdge(int n1, int n2, int weight);
    bool hasEdge(int n1, int n2);
    void setOrder(int order);
    int getLastIndex();
    int getOrder();
    void breadthFirstSearch(int nodeValue, char *outputPath);
    void depthFirstSearch(int nodeValue, char *outputPath);
    void djikstraAlgorithm(Graph *graph, char *outputPath);
    void floydAlgorithm(Graph *graph, char *outputPath);
    void primAlgorithm(Graph *graph, char *outputPath);
    void kruskalAlgorithm(Graph *graph, char *outputPath);
    void printGraph(Graph *graph, char *outputPath);
    void printSequenceDegrees(Graph *graph, char *outputPath);
};


#endif //GRAPHTHEORYWORK_GRAPH_H
