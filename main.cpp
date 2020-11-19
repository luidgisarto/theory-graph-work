#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <iomanip>
#include "src/Graph.h"
#include "src/managers/FileManager.h"
#include "src/managers/MenuManager.h"

using namespace std;

float calculateMedia(vector<int> solutions) {
    int total = 0;
    for (int i = 0; i < solutions.size(); ++i) {
        total += solutions[i];
    }
    return total/solutions.size();
}

int main(int argc, char **argv) {
    auto start = chrono::high_resolution_clock::now();

    char *inputFileName;
    char *outputFileName;

    if(argc != 3) {
        throw invalid_argument("Parâmetros inválidos");
    }

    auto graph = new Graph();

    inputFileName = argv[1];
    outputFileName = argv[2];

    auto fileManager = new FileManager(inputFileName, outputFileName, graph);

    fileManager->readFileMatrix();

    auto end = chrono::high_resolution_clock::now();
    fileManager->writeFile();

    graph->greedyAlgorithm();

    float alfas[5] = {0.1, 0.2, 0.3, 0.5, 0.7 };
    vector<int> s;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 10; ++j) {
            auto alfa = alfas[i];
            auto start = chrono::high_resolution_clock::now();
            auto solution = graph->randomizedGluttonousAlgorithm(alfa, 500);
            auto end = chrono::high_resolution_clock::now();
            auto duration = end - start;
            auto time = chrono::duration_cast<chrono::milliseconds>(duration).count();
            cout << "iteração: " << j << " alfa: " << alfa <<  " = "<< solution.size() << " " << time << "ms " << time/1000.00 << "s" << endl;
            s.push_back(solution.size());
        }
        cout << "Média = " << calculateMedia(s) << endl;
    }

    return 0;
}


