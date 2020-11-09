//
// Created by Luidgi Sarto on 24/10/2020.
//

#include "Edge.h"
#include <stdio.h>
#include <iostream>

Edge::Edge(int n1, int n2, int weight) {
    this->n1 = n1;
    this->n2 = n2;
    this->weight = weight;
}

bool Edge::hasEdge(int n1, int n2) {
    if((this->n1 == n1 && this->n2 == n2)
    || this->n2 == n1 && this->n2 == n1) {
        return true;
    }
    return false;
}

int Edge::getFirstAdj() {
    return this->n1;
}

int Edge::getSecondAdj() {
    return this->n2;
}