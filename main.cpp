#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include "src/Graph.h"
#include "src/files/FileManager.h"
#include <chrono>

using namespace std;

void executeOperation(int option, int nodeValue, Graph *graph, char *outputPath) {
    switch (option) {
        case 1:
            graph->breadthFirstSearch(nodeValue, outputPath);
            break;
        case 2:
            graph->depthFirstSearch(nodeValue, outputPath);
            break;
        case 3:
            graph->djikstraAlgorithm(graph, outputPath);
            break;
        case 4:
            graph->floydAlgorithm(graph, outputPath);
            break;
        case 5:
            graph->primAlgorithm(graph, outputPath);
            break;
        case 6:
            graph->kruskalAlgorithm(graph, outputPath);
            break;
        case 7:
            graph->printGraph(graph, outputPath);
            break;
        case 8:
            graph->printSequenceDegrees(graph, outputPath);
            break;
        case 9:
            break;
    }
}

int createMenu() {
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

    cout << "" <<endl;

    cin >> option;

    return option;
}

int main(int argc, char **argv) {
    auto start = chrono::steady_clock::now();

    string inputFileName;
    FileManager fileManager;
    int selectedNode = -1;
    Graph *graph = new Graph();

    if(argc != 3) {
        throw invalid_argument("Parâmetros inválidos");
    }

    fileManager.readFile(argv[1], graph);

    auto end = chrono::steady_clock::now();
    cout << "Tempo de leitura do arquivo em milisegundos: " <<chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;
    cout << "Tempo de leitura do arquivo em segundos: " <<chrono::duration_cast<chrono::seconds>(end - start).count() << "s" << endl;

    cout << "Arestas: " << graph->getTotalEdges() << endl;

    cout << "Informe o nó de início: " << endl;
    cin >> selectedNode;

    auto selectedOption = createMenu();

    executeOperation(selectedOption, selectedNode, graph, argv[2]);

    return 0;
}


