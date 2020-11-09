//
// Created by Luidgi Sarto on 24/10/2020.
//

#ifndef GRAPHTHEORYWORK_EDGE_H
#define GRAPHTHEORYWORK_EDGE_H

class Node;

class Edge{
private:
    int weight;
    int n1;
    int n2;
public:
    Edge(int n1, int n2, int weight);
    bool hasEdge(int n1, int n2);
    int getFirstAdj();
    int getSecondAdj();
};


#endif //GRAPHTHEORYWORK_EDGE_H
