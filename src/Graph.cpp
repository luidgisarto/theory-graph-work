//
// Created by Luidgi Sarto on 24/10/2020.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include "Graph.h"

Graph::Graph() {}

Graph::Graph(int totalNodes) {
    this->vertex = 0;
    initialize(totalNodes);
}

Graph::Graph(int totalNodes, bool digraf) {
    this->digraf = digraf;
    initialize(totalNodes);
}

Graph::~Graph() {}

int Graph::getOrder() {
    return vertex;
}

int Graph::getDegree() {
    int degree = 0;
    int actualDegree;
    Node *node = first;
    while (node) {
        if(node->getDegree() > degree){
            degree = node->getDegree();
        }
        node = node->getNextNode();
    }

    return degree;
}

int Graph::getDegreeNode(int id) {
    Node *node = getNode(id);
    if(node) {
        return node->getDegree();
    }

    return 0;
}

Node *Graph::getNode(int id) {
    Node *node = first;

    while (node) {
        if(node->getId() == id) {
            return node;
        }
        node = node->getNextNode();
    }
    return nullptr;
}

Node * Graph::getFirstNode() {
    return first;
}

int * Graph::getSequenceDegrees() {
    int *degrees = new int[vertex];
    int i = 0;
    Node *node = first;
    while (node) {
        degrees[i] = node->getDegree();
        i++;
        node = node->getNextNode();
    }
    sort(degrees, degrees + vertex, greater<int>());

    return degrees;
}

void Graph::initialize(int totalNodes) {
    for (int i = 0; i < totalNodes; ++i) {
        insertNode(i);
    }
}

void Graph::removeEdge(Node *node) {}

void Graph::insertNode(int id) {
    Node *node = new Node(id);
    if(!isNull()){
        node->setNextNode(first);
    }
    first = node;
    vertex++;
}

void Graph::removeNode(int id) {}

void Graph::insertEdge(int start, int end, int weight) {
    Node *firstNode = NULL;
    Node *lastNode = NULL;
    Node *actual = first;
    while ((firstNode == NULL || lastNode == NULL) && actual != NULL) {
        if (actual->getId() == start) {
            firstNode = actual;
        }
        if (actual->getId() == end) {
            lastNode = actual;
        }
        actual = actual->getNextNode();
    }

    if (firstNode && lastNode) {
        firstNode->insertEdge(lastNode, weight);
        if (!digraf) {
            lastNode->insertEdge(firstNode, weight);
        }
    }
}

void Graph::removeEdge(int start, int end) {}

bool Graph::isNull() {
    return first == NULL;
}

bool Graph::isTrivial() {
    return first && first->getEdges() == NULL;
}

void Graph::printSequenceDegrees() {
    int *degrees = getSequenceDegrees();

    cout << "[";
    for (int i = 0; i < vertex; i++) {
        cout << degrees[i] << (i + 1 == vertex ? "" : ",");
    }
    cout << "]" << endl;
}

void Graph::printGraph() {
    Node *node = first;
    Edge *edge;

    cout << "Ordem do grafo: " << getOrder() << endl;
    cout << "Grau do grafo: " << getDegree() << endl;
    cout << "Vertices: " << endl << endl << "------" << endl << endl;

    while (node) {
        edge = node->getEdges();
        cout << "ID: \t" << node->getId() << endl;
        cout << "Grau: \t" << node->getDegree()<< endl;
        cout << "Arestas: " << endl;

        while (edge) {
            cout << "\t=>" << edge->getDestination()->getId() << ": " << edge->getWeight()
                 << endl;
            edge = edge->getNextEdge();
        }
        node = node->getNextNode();
        cout << "------" << endl << endl;
    }
}


