#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <chrono>
#include <random>
#include <math.h>
#include <fstream>
#include "Graph.h"
#include "managers/FileManager.h"

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
    Node *aux = first;
    Node *current;
    if (this->order < this->totalNodes) {
        p = new Node(info);
        p->setIndex(this->order);

        if (!first) {
            first = p;
        } else {
            while (aux) {
                current = aux;
                aux = aux->getProx();
            }
            current->setProx(p);
        }
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
        if (aux->getDegree() > degree) {
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

void Graph::breadthFirstSearch(int nodeInfo, char *outputPath) {

    ofstream file;
    file.open(outputPath, ofstream::ios_base::app);
    file << endl << "-----Execução da busca em Largura-----" << endl << endl;

    Node *p = getNode(nodeInfo);
    queue<int> queue;

    if (!p) {
        file << "Não foi encontrado nenhum nó: " << nodeInfo;
        return;
    }

    bool visited[this->order];

    for (int i = 0; i < this->order; ++i) {
        visited[i] = false;
    }

    queue.push(p->getInfo());
    visited[p->getIndex()] = true;
    //cout << p->getInfo() << endl;
    file << p->getInfo() << endl;
    Node *adj;
    Edge *aux;
    while (!queue.empty()) {
        aux = p->getFirstEdge();
        while (aux) {
            adj = aux->getAdjacent();
            auto index = adj->getIndex();

            if (!visited[index]) {
                visited[index] = true;
                queue.push(adj->getInfo());
                //cout << adj->getInfo() << endl;
                file << adj->getInfo() << endl;
            } else {
                aux = aux->getProx();
            }
        }

        queue.pop();
        if (!queue.empty()) {
            p = getNode(queue.front());
        }
    }

    file.close();

}

void Graph::depthFirstSearch(int nodeInfo, char *outputPath) {
    ofstream file;
    Node *p = getNode(nodeInfo);
    stack<int> stack;

    file.open(outputPath, ofstream::ios_base::app);
    file << endl << "-------Execução da Busca em profundidade--------" <<endl << endl;

    if (!p) {
        file << "Não foi encontrado nenhum nó: " << nodeInfo;
        return;
    }

    bool visited[this->order];

    for (int i = 0; i < this->order; ++i) {
        visited[i] = false;
    }

    stack.push(p->getInfo());
    visited[p->getIndex()] = true;
    //cout << p->getInfo() << endl;
    file << p->getInfo() << endl;

    Edge *edge;

    while (!stack.empty()) {
        edge = p->getFirstEdge();
        while (edge) {
            auto adj = edge->getAdjacent();
            auto index = adj->getIndex();

            if (!visited[index]) {
                visited[index] = true;
                stack.push(adj->getInfo());
                file << adj->getInfo() << endl;
                //cout << adj->getInfo() << endl;
                p = getNode(stack.top());
                edge = p->getFirstEdge();
            } else {
                edge = edge->getProx();
            }
        }
        stack.pop();

        if (!stack.empty()) {
            p = getNode(stack.top());
        }
    }

    file.close();
}

int Graph::djisktraAlgorithm(int srcInfo, int destInfo, char *outputPath) {
    ofstream file;

    file.open(outputPath, ofstream::ios_base::app);

    file << endl << "-------Execução do algoritmo de Djikstra-----" << endl << endl;

    int dist[this->order];
    bool visited[this->order];

    if (hasNode(srcInfo) && hasNode(destInfo)) {
        Node *start = getNode(srcInfo);
        Node *dest = getNode(destInfo);

        for (int i = 0; i < this->order; ++i) {
            visited[i] = false;
            dist[i] = INT_MAX / 2;
        }

        dist[start->getIndex()] = 0;

        priority_queue<pair<int, int>,
                vector<pair<int, int> >, greater<pair<int, int> > > pq;

        // a distância de orig para orig é 0
        dist[start->getIndex()] = 0;

        // insere na fila
        pq.push(make_pair(dist[start->getIndex()], start->getInfo()));

        // loop do algoritmo
        while (!pq.empty()) {
            pair<int, int> p = pq.top(); // extrai o pair do topo
            int u = p.second; // obtém o vértice do pair
            pq.pop(); // remove da fila

            Node *n = getNode(u);

            // verifica se o vértice não foi expandido
            if (visited[n->getIndex()] == false) {
                // marca como visitado
                visited[n->getIndex()] = true;

                Edge *e = n->getFirstEdge();

                while (e) {
                    // obtém o vértice adjacente e o custo da aresta
                    Node *v = e->getAdjacent();
                    int costEdge = e->getWeight();

                    // relaxamento (u, v)
                    if (dist[v->getIndex()] > (dist[n->getIndex()] + costEdge)) {
                        // atualiza a distância de "v" e insere na fila
                        dist[v->getIndex()] = dist[n->getIndex()] + costEdge;
                        pq.push(make_pair(dist[v->getIndex()], v->getInfo()));
                    }
                    e = e->getProx();
                }
            }
        }

        for (int i = 0; i < this->order; ++i) {
            file << "D(" << i << ")= " << dist[i] << endl;
        }

        // retorna a distância mínima até o destino
        file << "D(" << srcInfo << "," << destInfo << ") = " << dist[dest->getIndex()] << endl;
        return dist[dest->getIndex()];
    }

    file << "Não foi encontrado o nó de partida ou nó de saíde" << endl;

    file.close();

    return 0;
}

void Graph::greedyAlgorithm(char *outputPath) {
    ofstream file;

    file.open(outputPath, ofstream::ios_base::app);

    file << endl << "------Execução do algoritmo guloso-------" << endl;

    auto start = chrono::steady_clock::now();

    vector<int> sol;
    list<Node> candidates = getAllNodes();
    candidates = sortCandidates(candidates);

    while (!candidates.empty()) {
        auto item = candidates.front();
        sol.push_back(item.getInfo());
        candidates = updateCandidates(item, candidates);
    }
    auto end = chrono::steady_clock::now();
    file << "S = "<< sol.size() << endl;
    file << "Tempo em milisegundos: " <<chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;
    file << "Tempo em segundos: " <<chrono::duration_cast<chrono::milliseconds>(end - start).count() / 1000.00 << "s" << endl;

    file.close();
}

void Graph::executeMinimalDominantSubset(int iterationsAlpha, char *outputPath) {
    ofstream  file;

    file.open(outputPath, ofstream::ios_base::app);

    file << endl << "-----Execução do Algoritmo Randomizado--" << endl << endl;

    vector<double> alphas = {0.1, 0.2, 0.3, 0.5, 0.7 };
    vector<int> s;
    for (int i = 0; i < alphas.size(); ++i) {
        auto alfa = alphas[i];

        file << "----Alfa: " << alfa << "------" << endl;

        for (int j = 0; j < iterationsAlpha; ++j) {
            auto start = chrono::high_resolution_clock::now();
            auto solution = randomizedGluttonousAlgorithm(alfa, 500);
            auto end = chrono::high_resolution_clock::now();
            auto duration = end - start;
            auto time = chrono::duration_cast<chrono::milliseconds>(duration).count();
            file << "iteração: " << j << endl;
            file <<  "$ = "<< solution.size() << endl;
            file << "Tempo: "<< time << "ms " << time/1000.00 << "s" << endl;
            file << endl;
            s.push_back(solution.size());
        }
        file << "Média = " << calculateMedia(s) << endl << endl;
    }

    file.close();
}

double Graph::calculateMedia(vector<int> values) {
    int total = 0;
    for (int i = 0; i < values.size(); ++i) {
        total += values[i];
    }
    return total / values.size();
}

vector<int> Graph::randomizedGluttonousAlgorithm(float alfa, int maxIterations) {
    vector<int> solution;
    list<Node> candidates = getAllNodes();
    candidates = sortCandidates(candidates);
    int iterations = 0;

    while (iterations < maxIterations) {
        while (!candidates.empty()) {
            auto current = getRandomElement(candidates, alfa);
            solution.push_back(current.getInfo());
            candidates = updateCandidates(current, candidates);
        }
        iterations++;
    }
    return solution;
}

list<Node> Graph::getAllNodes() {
    list<Node> all;
    Node *p = first;
    while (p) {
        all.push_back(*p);
        p = p->getProx();
    }

    return all;
}

list<Node> Graph::sortCandidates(list<Node> candidates) {
    candidates.sort();
    return candidates;
}

list<Node> Graph::updateCandidates(Node current, list<Node> candidates) {
    auto adjacents = current.getAllAdjacents();

    for (int i = 0; i < adjacents.size(); ++i) {
        candidates.remove_if([&](Node node){
            if(current.getInfo() == node.getInfo()
            || node.getInfo() == adjacents[i]){
                return true;
            }
            return false;
        });
    }
    return sortCandidates(candidates);
}

Node Graph::getRandomElement(list<Node> candidates, float alfa) {
    int maxPosition = alfa * (candidates.size() - 1);
    int position = (rand() % (maxPosition + 1 - 0)) + 0;
    auto it = candidates.begin();
    advance(it, position);
    return it.operator*();
}
