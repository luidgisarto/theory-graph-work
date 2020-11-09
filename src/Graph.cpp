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

Graph::Graph() {
    this->order = 0;
    this->totalEdges = 0;
    this->nodes = new list<Node>;
}

Graph::~Graph() {
    this->order = 0;
    this->totalEdges = 0;
    this->nodes = nullptr;
}

int Graph::getOrder() {
    return this->order;
}

Node * Graph::insertNode(int id) {
    auto lastIndex = getLastIndex();
    auto *newNode = new Node(id);
    newNode->setIndex(lastIndex);
    this->nodes->push_back(*newNode);
    this->order++;
    return newNode;
}

list<Node> * Graph::getNodes() {
    return this->nodes;
}

bool Graph::hasNode(int id) {
    auto iterator = find_if(this->nodes->begin(), this->nodes->end(), [&](Node node) {
        return node.getValue() == id;
    });

    if (iterator != this->nodes->end()) {
        return true;
    }
    return false;
}

Node *Graph::getNode(int id) {
    auto iterator = find_if(this->nodes->begin(), this->nodes->end(), [&](Node node) {
        return node.getValue() == id;
    });

    if (iterator != this->nodes->end()) {
        return iterator.operator->();
    }

    return nullptr;
}

void Graph::insertEdge(int n1, int n2, int weight) {
    if (!hasEdge(n1, n2)) {
        auto *node1 = getNode(n1);
        auto *node2 = getNode(n2);

        if (node1 == NULL) {
            node1 = this->insertNode(n1);
        }

        if (node2 == NULL) {
            node2 = this->insertNode(n2);
        }

        node1->insertEdge(new Edge(n1, n2, weight));
        node2->insertEdge(new Edge(n2, n1, weight));

        cout << this->order << endl;

        this->totalEdges++;
    }
}

bool Graph::hasEdge(int n1, int n2) {
//    for (auto it = this->nodes->begin(); it != this->nodes->end(); it++) {
//        if(it->hasEdge(n1,n2)){
//            return true;
//        }
//    }
//    return false;
auto iterator = find_if(this->nodes->begin(), this->nodes->end(), [&](Node node) {
    return node.hasEdge(n1, n2);
});

if (iterator != this->nodes->end()) {
    return true;
}
return false;
}

void Graph::setOrder(int order) {
    this->order = order;
}

int Graph::getLastIndex() {
    return this->nodes->size();
}

void Graph::breadthFirstSearch(int nodeValue, char *outputPath) {
    try {
        Node *current;
        queue<Node *> queue;
        vector<bool> visited(this->order, false);

        if(!hasNode(nodeValue)) {
            throw invalid_argument("Nó não encontrado no grafo");
        }

        current = getNode(nodeValue);

        cout << "Início da Busca em largura" << endl;

        if(!current) {
            *current = this->nodes->front();
        }

        cout << current->getValue() << "\n";

        visited[current->getIndex()] = true;

        while (true) {
            for (const auto &nodeId: current->getAdj()) {
                auto node = getNode(nodeId);

                    if (!visited[node->getIndex()]) {
                        cout << node->getValue() << "\n";
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

    if(!hasNode(nodeValue)) {
        throw invalid_argument("Nó não encontrado no grafo");
    }

    current = getNode(nodeValue);
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






