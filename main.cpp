#include <iostream>
#include <string>
#include "src/Graph.h"
#include "src/FileManager.h"
#include "src/MenuManager.h"

using namespace std;

void executeOperation(int option, Graph *graph) {
    switch (option) {
        case 1: {
            int node = -1;
            cout << "Informe o nó de início:" << endl;
            cin >> node;

            auto outputPath = "..\\outputs\\largura.txt";
            char *path = const_cast<char *>(outputPath);
            graph->breadthFirstSearch(node, path);
            break;
        }
        case 2: {
            int node = -1;
            cout << "Informe o nó de início:" << endl;
            cin >> node;

            auto outputPath = "..\\outputs\\profundidade.txt";
            char *path = const_cast<char *>(outputPath);
            graph->depthFirstSearch(node, path);
            break;
        }
        case 3: {
            int start = -1;
            int end = -1;
            cout << "Informe o nó de início:" << endl;
            cin >> start;

            cout << "Informe o nó de fim:" << endl;
            cin >> end;

            auto outputPath = "..\\outputs\\djisktra.txt";
            char *path = const_cast<char *>(outputPath);
            graph->djisktraAlgorithm(start, end, path);
            break;
        }
        case 4: {
//            auto outputPath = "..\\outputs\\prim.txt";
//            char *path = const_cast<char *>(outputPath);
//            graph->primAlgorithm(path);
            cout << "Não foi possível obter resultado devido a problemas de implementação" << endl;
            break;
        }
        case 5: {
            auto outputPath = "..\\outputs\\kruskal.txt";
            char *path = const_cast<char *>(outputPath);
            graph->kruskalAlgorithm(path);
            break;
        }
        case 6: {
            auto outputPath = "..\\outputs\\guloso.txt";
            char *path = const_cast<char *>(outputPath);
            graph->greedyAlgorithm(path);
            break;
        }
        case 7: {
            int iterations = 10;
            auto outputPath = "..\\outputs\\randomizado.txt";
            char *path = const_cast<char *>(outputPath);
            graph->executeMinimalDominantSubset(iterations, path);
            break;
        }
        case 8:{
            exit(EXIT_SUCCESS);
        }
        default:{
            exit(EXIT_SUCCESS);
        }
    }
}

void prepareMenu(int option, Graph *graph) {
    auto menuManager = new MenuManager();
    while (option == -1) {
        option = menuManager->createMenu();
    }

    executeOperation(option, graph);
    prepareMenu(-1, graph);
}

int main(int argc, char **argv) {
    char *inputFileName;
    char *outputFileName;

    if (argc != 3) {
        throw invalid_argument("Parâmetros inválidos");
    }

    vector<string> instances = {"Problem.dat_50_50_0", "Problem.dat_50_100_0", "Problem.dat_50_500_0",
                                "Problem.dat_100_2000_0"};

    auto graph = new Graph();

    inputFileName = argv[1];
    outputFileName = argv[2];
    int readType = -1;

    while (readType == -1) {
        cout << "Selecione o tipo de leitura de arquivo: " << endl;
        cout << "1 - Padrão" << endl;
        cout << "2 - Matriz de Adjacência" << endl;

        cin >> readType;
    }

    auto fileManager = new FileManager(inputFileName, outputFileName, graph);

    if (readType == 1) {
        fileManager->readFile();
        fileManager->writeFile();
    } else if (readType == 2) {
        fileManager->readFileMatrix();
        fileManager->writeFile();
    }

    if (readType > 2) {
        exit(EXIT_SUCCESS);
    } else {
        int option = -1;
        prepareMenu(option, graph);
    }


    return 0;
}


