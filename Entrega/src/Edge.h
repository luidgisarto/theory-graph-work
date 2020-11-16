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
    Edge *getProx();
    void setProx(Edge *next);
private:
    int weight; // peso da aresta
    Node *src; //ponteiro pro primeiro no da aresta
    Node *dest; // ponteiro pro segundo nó da aresta
    Edge *next; //pronteiro pra próxima aresta
};


#endif //GRAPHTHEORYWORK_EDGE_H
