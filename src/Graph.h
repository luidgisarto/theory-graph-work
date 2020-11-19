#ifndef GRAPHTHEORYWORK_GRAPH_H
#define GRAPHTHEORYWORK_GRAPH_H

#include "Node.h"
#include "Edge.h"
#include <stdio.h>
#include <list>

using namespace std;

class Graph {
private:
    int totalEdges; //total de arestas do grafo
    int totalNodes; //total de nós lido pelo arquivo
    int order; // ordem do grafo
    Node *first; // ponteiro pro primeiro nó da lista
public:
    Graph();
    ~Graph();
    int getTotalEdges();
    int getOrder();
    int getDegree();
    float getMediumDegree();
    float getRelativeFrequency(int degree);
    Node * getNode(int info);
    Node* insertNode(int info);
    void insertEdge(int n1, int n2, int weight);
    void setTotalNodes(int total);
    bool hasNode(int info);
    void breadthFirstSearch(int nodeInfo, char *outputPath);
    void depthFirstSearch(int nodeInfo, char *outputPath);
    int djisktraAlgorithm(int srcInfo, int destInfo, char *outputPath);
    void greedyAlgorithm(char *outputFile);
    list<Node> getAllNodes();
    list <Node> sortCandidates(list<Node> candidates);
    list<Node> updateCandidates(Node current, list<Node> candidates);
    vector<int> randomizedGluttonousAlgorithm(float alfa, int maxIterations);
    Node getRandomElement(list<Node> candidates, float alfa);
    void executeMinimalDominantSubset(int iterationsAlpha, char *outputPath);

    double calculateMedia(vector<int> solutions);
};


#endif //GRAPHTHEORYWORK_GRAPH_H
