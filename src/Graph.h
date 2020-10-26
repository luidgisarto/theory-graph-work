//
// Created by Luidgi Sarto on 24/10/2020.
//

#ifndef GRAPHTHEORYWORK_GRAPH_H
#define GRAPHTHEORYWORK_GRAPH_H

#include "Node.h"
#include "Edge.h"
#include <stdio.h>

using namespace std;

class Graph {
private:
    int vertex;
    Node *first = NULL;
    bool digraf = false;
    void initialize(int totalNodes);
    void removeEdge(Node *node);
public:
    Graph(int totalNodes);
    Graph(int totalNodes, bool digraf);
    Graph();
    ~Graph();
    int getOrder();
    int getDegree();
    int getDegreeNode(int id);
    Node *getNode(int id);
    Node *getFirstNode();
    int *getSequenceDegrees();
    void insertNode(int id);
    void removeNode(int id);
    void insertEdge(int start, int end, int weight);
    void removeEdge(int start, int end);
    bool isNull();
    bool isTrivial();
    void printSequenceDegrees();
    void printGraph();
};


#endif //GRAPHTHEORYWORK_GRAPH_H
