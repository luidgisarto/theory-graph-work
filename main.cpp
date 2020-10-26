#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include "src/Graph.h"

using namespace std;

Graph *readFile(string inputFileName) {
    fstream file;

    file.open(inputFileName);

    cout << "Lendo arquivo" << endl;

    if(!file.is_open()) {
        cout << "Erro ao abrir o arquivo " << endl;
        throw invalid_argument("Erro ao abrir arquivo para leitura.");
    }

    int total;
    int n1;
    int n2;
    int edgeWeight;

    file >> total;

    cout << total <<endl;

    Graph* graph = new Graph(total);

    while (file >> n1 >> n2 >> edgeWeight) {
        cout << to_string(n1) + " " + to_string(n2) + " " + to_string(edgeWeight) <<endl;
        graph->insertEdge(n1, n2, edgeWeight);
    }

    file.close();

    cout << "leitura de arquivo finalizada" << endl;

    return graph;
}

int main(int argc, char **argv) {
    string inputFileName;

    if(argc != 3) {
        throw invalid_argument("Parâmetros inválidos");
    }

    inputFileName = argv[1];

    Graph *graph = readFile(inputFileName);

    graph->printSequenceDegrees();

    graph->printGraph();
    return 0;
}


