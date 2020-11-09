//
// Created by Luidgi Sarto on 08/11/2020.
//

#ifndef GRAPHTHEORYWORK_FILEMANAGER_H
#define GRAPHTHEORYWORK_FILEMANAGER_H


#include "../Graph.h"

class FileManager {

public:
    void writeFile(char *outputFileName);
    void readFile(char *inputFileName, Graph *graph);
};


#endif //GRAPHTHEORYWORK_FILEMANAGER_H
