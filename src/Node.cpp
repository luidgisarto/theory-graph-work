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
    this->edges = new list<Edge>;
}

Node::~Node() {
    this->value = -1;
    this->degree = 0;
    this->edges = nullptr;
}

int Node::getValue() {
    return this->value;
}

bool Node::hasEdge(int n1, int n2) {
//    for (auto it= this->edges->begin(); it != this->edges->end(); it++) {
//        if(it->hasEdge(n1, n2)) {
//            return true;
//        }
//    }
//
//    return  false;
    auto iterator = find_if(this->edges->begin(), this->edges->end(), [&](Edge edge){
        return edge.hasEdge(n1, n2);
    });

    if(iterator != this->edges->end()){
        return true;
    }
    return false;
}

void Node::insertEdge(Edge *edge) {
    this->edges->push_back(*edge);
    this->degree++;
}

list<int> Node::getAdj() {
    list<int> adj;

    for (auto it = this->edges->begin(); it != this->edges->end(); it++){
        adj.push_back(it->getFirstAdj());
        adj.push_back(it->getSecondAdj());
    }

    return adj;
}

int Node::getIndex() {
    return this->index;
}

void Node::setIndex(int index) {
    this->index = index;
}

int Node::getDegree() {
    return this->degree;
}
