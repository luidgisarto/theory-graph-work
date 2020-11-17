#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <iomanip>
#include "src/Graph.h"
#include "src/managers/FileManager.h"
#include "src/managers/MenuManager.h"

using namespace std;

int main(int argc, char **argv) {
    auto start = chrono::steady_clock::now();

    char *inputFileName;
    char *outputFileName;

    if(argc != 3) {
        throw invalid_argument("Parâmetros inválidos");
    }

    auto graph = new Graph();

    inputFileName = argv[1];
    outputFileName = argv[2];

    auto fileManager = new FileManager(inputFileName, outputFileName, graph);

    fileManager->readFile();

    auto end = chrono::steady_clock::now();
//    cout << "Tempo de leitura do arquivo em milisegundos: " <<chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;
  //  cout << "Tempo de leitura do arquivo em segundos: " <<chrono::duration_cast<chrono::seconds>(end - start).count() << "s" << endl;

    fileManager->writeFile();


    graph->djisktraAlgorithm(1, 6, outputFileName);

    return 0;
}


