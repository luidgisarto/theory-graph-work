//
// Created by Luidgi Sarto on 08/11/2020.
//

#include <fstream>
#include <iostream>
#include "FileManager.h"

void FileManager::readFile(char *inputFileName, Graph *graph) {
    fstream file;

    file.open(inputFileName);

    //cout << "Lendo arquivo" << endl;

    if(!file.is_open()) {
        //cout << "Erro ao abrir o arquivo " << endl;
        throw invalid_argument("Erro ao abrir arquivo para leitura.");
    }

    int total;
    int n1;
    int n2;
    int edgeWeight;

    file >> total;

    //cout << total <<endl;

    graph->setOrder(total);

    while (file >> n1 >> n2 >> edgeWeight) {
        //cout << to_string(n1) + " " + to_string(n2) + " " + to_string(edgeWeight) <<endl;
        graph->insertEdge(n1, n2, edgeWeight);
    }

    file.close();

    //cout << "leitura de arquivo finalizada" << endl;
}

void FileManager::writeFile(char *outputFileName) {

}