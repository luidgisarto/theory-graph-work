//
// Created by Luidgi Sarto on 24/10/2020.
//

#include <stdio.h>
#include <algorithm>
#include "Node.h"
#include "Edge.h"

using namespace  std;

Node::Node(int id) {
    this->value = id;
    this->degree = 0;
}

Node::~Node() {}

int Node::getValue() {
    return this->value;
}

bool Node::hasEdge(int nodeId) {
    auto iterator = find_if(edges.begin(), edges.end(), [&](Edge *edge){
        return edge->hasEdge(value, nodeId);
    });

    if(iterator != edges.end()){
        return true;
    }
    return false;
}

void Node::insertEdge(Edge *edge) {
    this->edges.push_back(edge);
    this->degree++;
}

list<Edge *> Node::getEdges() {
    return this->edges;
}

list<int> Node::getAdj() {
    list<int> adj;

    for (const auto &edge: this->edges) {
        adj.push_back(edge->getFirstAdj());
        adj.push_back(edge->getSecondAdj());
    }

    return adj;
}

int Node::getIndex() {
    return this->index;
}

int Node::setIndex(int index) {
    this->index = index;
}

int Node::getDegree() {
    return this->degree;
}
