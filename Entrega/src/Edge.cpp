#include "Edge.h"

/*
 * @function construtor com peso
 * @param src - ponteiro pro primeiro nó da aresta*
 * @param dest - ponteiro pro segundo nó da aresta
 * @param weight - peso da aresta*/
Edge::Edge(Node *src, Node *dest, int weight) {
    this->src = src;
    this->dest = dest;
    this->weight = weight;
    this->next = nullptr;
}

/*
 * @function construtor sem peso
 * @param src - ponteiro pro primeiro nó da aresta*
 * @param dest - ponteiro pro segundo nó da aresta*/
Edge::Edge(Node *src, Node *dest) {
    this->src = src;
    this->dest = dest;
    this->weight = 0;
}

Edge::~Edge() {}

/*
* @fuction retorna o peso da aresta*/
int Edge::getWeight() {
    return this->weight;
}

/*
* @fuction retorna o ponteiro pro primeiro nó*/
Node * Edge::getSource() {
    return this->src;
}

/*
* @fuction retorna o ponteiro pro segundo nó*/
Node * Edge::getDestination() {
    return this->dest;
}

/*
* @fuction retorna o ponteiro pra próxima aresta*/
Edge * Edge::getProx() {
    return this->next;
}

/*
* @fuction atribui o ponteiro pra próxima aresta*/
void Edge::setProx(Edge *next) {
    this->next = next;
}
