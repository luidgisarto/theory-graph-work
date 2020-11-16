#include <stdio.h>
#include <iostream>
#include <algorithm>
#include "Graph.h"

//construtor do grafo
Graph::Graph() {
    this->first = nullptr;
    this->totalEdges = 0;
    this->order = 0;
}

//destrutor do grafo
Graph::~Graph() {
}

/*
 * @function Verifica a existência de um nó no grafo
 * @param info -  valor que identifica um nó]
 * */
bool Graph::hasNode(int info) {
    Node *aux = first;

    while (aux) {
        if (aux->getInfo() == info) {
            return true;
        }
        aux = aux->getProx();
    }
    return false;
}

/*
 * @function Retorna um nó especifíco do grafo, caso não encontre retorna null
 * @param info - valor que identifica um nó]
 * */
Node *Graph::getNode(int info) {
    Node *aux = first;

    while (aux) {
        if (aux->getInfo() == info) {
            return aux;
        }
        aux = aux->getProx();
    }
    return nullptr;
}

/*
 * @function Retorna a ordem do grafo
 * */
int Graph::getOrder() {
    return this->order;
}

/*
 * @function Retorna o total de arestas inseridas no grafo
 * */
int Graph::getTotalEdges() {
    return this->totalEdges;
}

/*
 * @function Altera o total de nós do grafo
 * @param total  - total de nós */
void Graph::setTotalNodes(int total) {
    this->totalNodes = total;
}

/*
 * @function Insere um nó específico no grafo e retorna ele
 * @param info - identificador do nó a ser inserido
 * */
Node *Graph::insertNode(int info) {
    Node *p = nullptr;
    if(this->order < this->totalNodes) {
        p = new Node(info);
        if(first) {
            p->setProx(first);
        }
        first = p;
        this->order++;
    }

    return p;
}

/*
 * @function Insere uma aresta no grafo
 * @param n1 - identificador do nó a ser ligado
 * @param n2 - identificador do nó a ser ligado
 * @param weight - identificador do peso da aresta
 *
 * */
void Graph::insertEdge(int n1, int n2, int weight) {

    Node *p = getNode(n1);
    Node *q = getNode(n2);

    if (!p) {
        p = this->insertNode(n1);
    }

    if (!q) {
        q = this->insertNode(n2);
    }

    //Verifica se os nós de inserção da aresta existem e se não existe uma aresta entre eles no grafo
    if (p && q && !p->hasEdge(n2)) {
        p->insertEdge(q, weight);
        q->insertEdge(p, weight);
        this->totalEdges++;
    }
}

/*
 * @function Retorna o grau médio do grafo
 * */
float Graph::getMediumDegree() {
    Node *aux = first;
    int degree = 0;

    while (aux) {
        degree += aux->getDegree();
        aux = aux->getProx();
    }
    return (float) (degree) / (this->order);
}

/*
 * @function Retorna o grau do grafo
 * */
int Graph::getDegree() {
    Node *aux = first;
    int degree = 0;

    while (aux) {
        if(aux->getDegree() > degree) {
            degree = aux->getDegree();
        }
        aux = aux->getProx();
    }

    return degree;
}

/*
 * @function Calcula a frequência relativa de um grau especifíco no grafo
 * @param degree - grau a ser calculado a frequência relativa no grafo*/
float Graph::getRelativeFrequency(int degree) {
    Node *aux = first;
    int total = 0;

    while (aux) {
        if (aux->getDegree() == degree) {
            total++;
        }
        aux = aux->getProx();
    }
    float frequency = (float) (total) / (this->order);
    return frequency;
}



