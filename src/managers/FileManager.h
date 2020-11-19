#ifndef GRAPHTHEORYWORK_FILEMANAGER_H
#define GRAPHTHEORYWORK_FILEMANAGER_H


#include "../Graph.h"

class FileManager {
private:
    char *inputFileName;
    char *outputFileName;
    Graph *graph;
public:
    FileManager(char *inputFileName, char *outputFileName, Graph *graph);
    void readFile();
    void writeFile();

    void createHeader(ofstream file);

    void readFileMatrix();
};


#endif //GRAPHTHEORYWORK_FILEMANAGER_H
