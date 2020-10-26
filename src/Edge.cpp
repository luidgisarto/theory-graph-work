//
// Created by Luidgi Sarto on 24/10/2020.
//

#include "Edge.h"

Edge::Edge() {}

Edge::Edge(Node *src, Node *dest, int weight) {
    this->src = src;
    this->dest = dest;
    this->weight = weight;
}

Edge::Edge(Node *src, Node *dest) {
    this->src = src;
    this->dest = dest;
    this->weight = 0;
}

Edge::~Edge() {}

int Edge::getWeight() {
    return this->weight;
}

Node * Edge::getSource() {
    return this->src;
}

Node * Edge::getDestination() {
    return this->dest;
}

Edge * Edge::getNextEdge() {
    return this->next;
}

void Edge::setNextEdge(Edge *next) {
    this->next = next;
}