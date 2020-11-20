#include <iostream>
#include <stdio.h>
#include "MenuManager.h"

using namespace std;

MenuManager::MenuManager() {}

MenuManager::~MenuManager() {}

int MenuManager::createMenu() {
    int option = -1;

    this->createHeader();

    cout << "Selecione o número correspondente a operação desejada: " << endl;

    this->createOptions();

    cin >> option;

    return option;
}

void MenuManager::createHeader() {
    cout << "" << endl;
    cout << "-------------- Trabalho de Grafos -------------------" << endl;
    cout << "-------------- Luidgi Sarto Lacerda -----------------" << endl;
    cout << "-------------- Sistemas de Informação ---------------" << endl;
    cout << "-------------- 201176023 ----------------------------" << endl;
    cout << "" << endl;
}

void MenuManager::createOptions() {
    cout << "" << endl;
    cout << "1 - Caminhamento em largura" << endl;
    cout << "2 - Caminhamento em profundidade" << endl;
    cout << "3 - Algoritmo de Djikstra (caminho mínimo)" << endl;
    cout << "4 - Algoritmo de Prim" << endl;
    cout << "5 - Algoritmo de Kruskal" << endl;
    cout << "6 - Algoritmo Guloso" << endl;
    cout << "7 - Algoritmo Guloso Randomizado" << endl;
    cout << "8 - Sair" << endl;
    cout << "" << endl;
}