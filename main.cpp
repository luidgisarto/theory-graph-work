#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include "src/Graph.h"

using namespace std;

Graph *readFile(string inputFileName) {
    fstream file;

    file.open(inputFileName);

    //cout << "Lendo arquivo" << endl;

    if(!file.is_open()) {
        cout << "Erro ao abrir o arquivo " << endl;
        throw invalid_argument("Erro ao abrir arquivo para leitura.");
    }

    int total;
    int n1;
    int n2;
    int edgeWeight;

    file >> total;

    //cout << total <<endl;

    Graph* graph = new Graph(total);

    while (file >> n1 >> n2 >> edgeWeight) {
        //cout << to_string(n1) + " " + to_string(n2) + " " + to_string(edgeWeight) <<endl;
        graph->insertEdge(n1, n2, edgeWeight);
    }

    file.close();

    //cout << "leitura de arquivo finalizada" << endl;

    return graph;
}

void createMenu() {
    int option = -1;

    cout << "" << endl;

    cout << "-------------- Trabalho de Grafos -------------------" << endl;
    cout << "-------------- Luidgi Sarto Lacerda -----------------" << endl;
    cout << "-------------- Sistemas de Informação ---------------" << endl;
    cout << "-------------- 201176023 ----------------------------" << endl;

    cout << "" << endl;

    cout << "Selecione o número correspondente a operação desejada" << endl;

    cout << "" << endl;

    cout << "1 - Caminhamento em largura" << endl;
    cout << "2 - Caminhamento em profundidade"<< endl;
    cout << "3 - Algoritmo de Djikstra (caminho mínimo)" << endl;
    cout << "4 - Algoritmo de Floyd (caminho mínimo)" << endl;
    cout << "5 - Algoritmo de Prim (árvore geradora)" << endl;
    cout << "6 - Algoritmo de Kruskal (árvore geradora mínima)" << endl;
    cout << "7 - Imprimir Grafo" << endl;
    cout << "8 - Imprimir Sequência de Graus" << endl;
    cout << "9 - Sair" << endl;

    cin >> option;
}

int main(int argc, char **argv) {
    string inputFileName;

    if(argc != 3) {
        throw invalid_argument("Parâmetros inválidos");
    }

    inputFileName = argv[1];
    readFile(inputFileName);
    createMenu();

    return 0;
}


