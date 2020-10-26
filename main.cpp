#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include "src/Graph.h"

using namespace std;

void readFile() {
    fstream file;

    file.open("..\\inputs\\sample.txt");

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

    graph->printSequenceDegrees();

    graph->printGraph();
}

int main() {

    readFile();

    return 0;
}


