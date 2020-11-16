#ifndef GRAPHTHEORYWORK_NODE_H
#define GRAPHTHEORYWORK_NODE_H

class Edge;

class Node {
public:
    Node(int id);
    ~Node();
    int getInfo();
    int getDegree();
    Node *getProx();
    Edge *getFirstEdge();
    void setProx(Node *pNode);
    Edge * insertEdge(Node *node, int weight);
    bool hasEdge(int nodeInfo);

private:
    int info; // identificador do nó
    int degree; // grau do nó
    Node *next; //ponteiro pro próximo nó do grafo
    Edge *edges; //ponteiro pra primeira aresta do nó
};


#endif //GRAPHTHEORYWORK_NODE_H
