//
// Created by Luidgi Sarto on 24/10/2020.
//

#include <stdio.h>
#include "Node.h"
#include "Edge.h"

Node::Node(int id) {
    this->id = id;
    this->next = NULL;
    this->edges = NULL;
    this->degree = 0;
}

Node::~Node() {}

int Node::getId() {
    return this->id;
}

int Node::getDegree() {
    return this->degree;
}

Edge * Node::getEdges() {
    return this->edges;
}

Node * Node::getNextNode() {
    return  this->next;
}

void Node::insertEdge(Node *dest, int weight) {
    Edge *edge = new Edge(this, dest, weight);
    edge->setNextEdge(edges);
    edges = edge;
    degree++;
}

void Node::insertEdge(Node *dest) {
    insertEdge(dest, 0);
}

void Node::removeEdge(Node *dest) {
    Edge *edge = this->edges;
    Edge *previous = NULL;
    while (edge) {
        if (edge->getDestination() == dest) {
            if (previous == NULL) {
                edges = edge->getNextEdge();
            } else {
                previous->setNextEdge(edge->getNextEdge());
            }
            delete edge;
            break;
        }
        previous = edge;
        edge = edge->getNextEdge();
    }
    degree--;
}

void Node::setNextNode(Node *next) {
    this->next = next;
}

