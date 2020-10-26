//
// Created by Luidgi Sarto on 24/10/2020.
//

#ifndef GRAPHTHEORYWORK_NODE_H
#define GRAPHTHEORYWORK_NODE_H

class Edge;

class Node {
public:
    Node(int id);
    ~Node();
    int getId();
    int getDegree();
    Node *getNextNode();
    Edge *getEdges();
    void insertEdge(Node *dest, int weight);
    void insertEdge(Node *dest);
    void removeEdge(Node *dest);
    void setNextNode(Node *next);
private:
    int id;
    int degree;
    Node *next;
    Edge *edges;
};


#endif //GRAPHTHEORYWORK_NODE_H
