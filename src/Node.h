#ifndef GRAPHTHEORYWORK_NODE_H
#define GRAPHTHEORYWORK_NODE_H

#include <list>
#include <vector>

using  namespace std;

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

    Edge *insertEdge(Node *node, int weight);

    bool hasEdge(int nodeInfo);

    void setIndex(int index);

    int getIndex();

    int getWeight(int nodeInfo);

    vector<int> getAllAdjacents();

    inline bool operator<(Node b) {
        if (degree > b.getDegree() && edges)
            return true;
        else
            return false;
    }

    Node *getMinAdj();

    Edge * getLowerEdge();

private:
    int info; // identificador do nó
    int index; //indice de inserção do nó
    int degree; // grau do nó
    Node *next; //ponteiro pro próximo nó do grafo
    Edge *edges; //ponteiro pra primeira aresta do nó
    Node * getAdj(int nodeInfo);

};


#endif //GRAPHTHEORYWORK_NODE_H
