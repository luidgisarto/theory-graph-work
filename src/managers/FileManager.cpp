#include <fstream>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <queue>
#include "FileManager.h"


FileManager::FileManager(char *inputFileName, char *outputFileName, Graph *graph) {
    this->inputFileName = inputFileName;
    this->outputFileName = outputFileName;
    this->graph = graph;
}

FileManager::FileManager(char *outputFileName) {
    this->outputFileName = outputFileName;
}

/*
 * @function realiza a leitura do arquivo e cria a estrutura do grafo*/
void FileManager::readFile() {
    fstream file;

    file.open(this->inputFileName);

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

    //atribui no grafo o total de nós lido do arquivo
    graph->setTotalNodes(total);
    //cout << total <<endl;

    while (file >> n1 >> n2 >> edgeWeight) {
        //cout << to_string(n1) + " " + to_string(n2) + " " + to_string(edgeWeight) <<endl;
        //cria a aresta da linha do arquivo
        graph->insertEdge(n1, n2, edgeWeight);
    }

    file.close();

    //cout << "leitura de arquivo finalizada" << endl;
}

void FileManager::readFileMatrix() {
    fstream file;
    file.open(this->inputFileName);
    //cout << "Lendo arquivo" << endl;
    if(!file.is_open()) {
        //cout << "Erro ao abrir o arquivo " << endl;
        throw invalid_argument("Erro ao abrir arquivo para leitura.");
    }

    int total = 0;
    string ignoreLine = "";
    string line = "";
    int value = -1;

    file >> ignoreLine;
    file >> total;

    //atribui no grafo o total de nós lido do arquivo
    graph->setTotalNodes(total);
    //cout << total <<endl;

//    queue<int> edges;
//    int edge = -1;
//    while (ignoreLine != "******************WEIGHTS*****************************") {
//        file >> ignoreLine;
//    }

    while (ignoreLine != "*****************CONNECTIONS****************") {
//        file >> line;
//        try {
//            auto edge = stoi(line);
//            edges.push(edge);
//        }
//        catch (...) {
//            break;
//        }
        file >> ignoreLine;
    }

    for (int i = 0; i < total; ++i) {
        for (int j = 0; j < total; ++j, file >> value) {
            if(value == 1 && i != j) {
                int weight = 0;
//                if(edges.size() > 0) {
//                    weight = edges.front();
//                    edges.pop();
//                }
                graph->insertEdge(i, j, 0);
            }
        }
    }

    file.close();
}

/*
 * @function realiza a escrita do arquivo  no formato esperado*/
void FileManager::writeFile() {
    ofstream file;

    file.open(this->outputFileName, ofstream::ios_base::app);

    if(!file.is_open()) {
        throw invalid_argument("Erro ao abrir arquivo para escrita.");
    }


    file << "" << endl;
    file << "-------------- Trabalho de Grafos -------------------" << endl;
    file << "-------------- Luidgi Sarto Lacerda -----------------" << endl;
    file << "-------------- Sistemas de Informação ---------------" << endl;
    file << "-------------- 201176023 ----------------------------" << endl;
    file << "" << endl;

    file << "Vértices: " << graph->getOrder() << endl;
    file << "Arestas: " << graph->getTotalEdges() << endl;
    file << "Grau Médio: " << graph->getMediumDegree() << endl;

    //salva no arquivo a frequência relativa de graus
    for (int i = 0; i <= graph->getDegree(); ++i) {
        if(graph->getRelativeFrequency(i) > 0){
            file << "f(" << i << "): " << graph->getRelativeFrequency(i) << endl;
        }
    }

    file.close();
}

void FileManager::writeFile(string line) {
    ofstream file;

    file.open(this->outputFileName);

    if(!file.is_open()) {
        throw invalid_argument("Erro ao abrir arquivo para escrita.");
    }

    file << line << endl;
}

