//
// Created by Luidgi Sarto on 24/10/2020.
//

#include <stdio.h>
#include <iostream>
#include "Graph.h"
#include "Edge.h"
#include "Node.h"
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

Graph::~Graph() {
    this->order = 0;
    this->totalEdges = 0;
}

void Graph::insertNode(int id) {
    auto lastIndex = getLastIndex();
    auto newNode = new Node(id);
    newNode->setIndex(lastIndex);
    this->nodes.push_back(newNode);
}

bool Graph::hasNode(int id) {
    auto iterator = find_if(this->nodes.begin(), this->nodes.end(), [&](Node *node) {
        return node->getValue() == id;
    });

    if (iterator != this->nodes.end()) {
        return true;
    }
    return false;
}

Node *Graph::getNode(int id) {
    auto iterator = find_if(this->nodes.begin(), this->nodes.end(), [&](Node *node) {
        return node->getValue() == id;
    });

    if (iterator != nodes.end()) {
        return *iterator;
    }

    return nullptr;
}

void Graph::insertEdge(int n1, int n2, int weight) {
    if (!hasEdge(n1, n2)) {
        if (!this->hasNode(n1)) {
            this->insertNode(n1);
        }

        if (!this->hasNode(n2)) {
            this->insertNode(n2);
        }

        auto *node1 = getNode(n1);
        auto *node2 = getNode(n2);

        node1->insertEdge(new Edge(n1, n2, weight));
        node2->insertEdge(new Edge(n2, n1, weight));

        this->totalEdges++;
    }
}

bool Graph::hasEdge(int n1, int n2) {
    auto iterator = find_if(nodes.begin(), nodes.end(), [&](Node *node) {
        return node->hasEdge(n1) && node->hasEdge(n2);
    });

    if (iterator != nodes.end()) {
        return true;
    }
    return false;
}

void Graph::setOrder(int order) {
    this->order = order;
}

Graph::Graph() {
    this->order = 0;
    this->totalEdges = 0;
}

int Graph::getLastIndex() {
    return this->nodes.size();
}

void Graph::breadthFirstSearch(int nodeValue, char *outputPath) {
    try {
        Node *current;
        queue<Node *> queue;
        vector<bool> visited(this->order, false);

        current = getNode(nodeValue);

        cout << "Início da Busca em largura" << endl;

        cout << current->getValue() << "\t";

        visited[current->getIndex()] = true;

        while (true) {
            for (const auto &nodeId: current->getAdj()) {
                auto node = getNode(nodeId);

                if (!visited[node->getIndex()]) {
                    cout << node->getValue() << "\t";
                    visited[node->getIndex()] = true;
                    queue.push(node);
                }
            }

            if (queue.empty()) {
                break;
            }

            current = queue.front();
            queue.pop();
        }

        cout << "\nFim da Busca em largura" << endl;
    }
    catch (...) {
        cout << "throw some exception" << endl;
        throw;
    }
}

void Graph::depthFirstSearch(int nodeValue, char *outputPath) {
    stack<Node *> stack;
    vector<bool> visited(this->order, false);
    Node *current;
    Node *node;

    current = this->nodes.front();
    while (true) {
        if (!visited[current->getIndex()]) {
            cout << "Visitando vértice: " << current->getValue() << endl;

            visited[current->getIndex()] = true;
            stack.push(getNode(current->getValue()));
        }

        bool find = false;
        for (const auto &nodeId: current->getAdj()) {
            node = getNode(nodeId);

            if (!visited[node->getIndex()]) {
                find = true;
                break;
            }
        }

        if (find) {
            current = node;
        } else {
            stack.pop();

            if (stack.empty()) {
                break;
            }

            current = stack.top();
        }
    }
}

void Graph::printGraph(Graph *graph, char *outputPath) {}

void Graph::kruskalAlgorithm(Graph *graph, char *outputPath) {}

void Graph::printSequenceDegrees(Graph *graph, char *outputPath) {}

void Graph::primAlgorithm(Graph *graph, char *outputPath) {}

void Graph::djikstraAlgorithm(Graph *graph, char *outputPath) {}

void Graph::floydAlgorithm(Graph *graph, char *outputPath) {}

int Graph::getTotalEdges() {
   return totalEdges;
}





