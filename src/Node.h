//
// Created by Luidgi Sarto on 24/10/2020.
//

#ifndef GRAPHTHEORYWORK_NODE_H
#define GRAPHTHEORYWORK_NODE_H
#include <stdio.h>
#include <list>

using namespace std;

class Edge;

class Node {
private:
    int value;
    int index;
    int degree;
    list<Edge> *edges;
public:
    Node(int id);
    ~Node();
    int getValue();
    void setIndex(int index);
    int getIndex();
    void insertEdge(Edge *edge);
    bool hasEdge(int n1, int n2);
    list<Edge*> getEdges();
    list<int> getAdj();

    int getDegree();

    Edge *getEdge(int n1, int n2);
};


#endif //GRAPHTHEORYWORK_NODE_H
