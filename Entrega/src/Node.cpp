#include <stdio.h>
#include "Node.h"
#include "Edge.h"

/*
 * @function construtor
 * @param id - representa o identificador do nó*/
Node::Node(int id) {
    this->info = id;
    this->next = nullptr;
    this->edges = nullptr;
    this->degree = 0;
}

/*
 * Destrutor */
Node::~Node() {}

/*
 * @fuction retorna o identificador do nó*/
int Node::getInfo() {
    return this->info;
}

/*
 * @fuction retorna o grau do nó*/
int Node::getDegree() {
    return this->degree;
}

/*
 * @fuction atribui o próximo nó do grafo
 * @param pNode - objeto Nó a ser inserido na lista encadeada*/
void Node::setProx(Node *pNode) {
    this->next = pNode;
}

/*
 * @fuction retorna o próximo nó*/
Node *Node::getProx() {
    return this->next;
}

/*
 * @fuction insere aresta do nó atual pra outro nó com peso
 * @param node - nó que será ligado a aresta
 * @param weight - peso da aresta */
Edge *Node::insertEdge(Node *node, int weight) {
    Edge *p = new Edge(this, node, weight);
    Edge *aux = this->edges;
    Edge *current = nullptr;

    //função que insere a aresta no fim da lista de arestas desse nó
    if (!aux) {
        this->edges = p;
    }
    else {
        while (aux) {
            current = aux;
            aux = aux->getProx();
        }
        current->setProx(p);
    }
    this->degree++;
    return p;
}
/*
* @fuction verifica a existência de uma aresta
* @param nodeInfo - identificador do nó a ser ligado*/
bool Node::hasEdge(int nodeInfo) {
    Edge *aux = edges;

    //função que pecorre a lista de arestas e verifica se  a não existência de um self-loop, ou uma aresta igual
    while (aux) {
        auto edgeSrc = aux->getSource();
        auto edgeDest = aux->getDestination();

        if (edgeSrc->getInfo() == this->info
        && edgeDest->getInfo() == nodeInfo
        || this->info == nodeInfo) {
            return true;
        }
        aux = aux->getProx();
    }

    return false;
}
/*
* @fuction retorna o ponteiro pra primeira aresta do nó*/
Edge *Node::getFirstEdge() {
    return this->edges;
}


