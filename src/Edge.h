//
// Created by Luidgi Sarto on 24/10/2020.
//

#ifndef GRAPHTHEORYWORK_EDGE_H
#define GRAPHTHEORYWORK_EDGE_H

class Node;

class Edge{
public:
    Edge(Node *src, Node *dest, int weight);
    Edge(Node *src, Node *dest);
    Edge();
    ~Edge();
    int getWeight();
    Node *getSource();
    Node *getDestination();
    Edge *getNextEdge();
    void setNextEdge(Edge *next);
private:
    int weight;
    Node *src;
    Node *dest;
    Edge *next;
};


#endif //GRAPHTHEORYWORK_EDGE_H
