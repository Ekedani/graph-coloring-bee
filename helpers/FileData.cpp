#include "FileData.h"

pair<bool **, int> FileData::readMatrix() {
    ifstream file;
    file.open(R"(D:\Programming\graph-coloring-bee\helpers\GraphMatrix.txt)");
    int verticesNum;
    file >> verticesNum;

    auto result = new bool*[verticesNum];
    for (int i = 0; i < verticesNum; ++i) {
        result[i] = new bool[verticesNum];
    }

    for (int i = 0; i < verticesNum; ++i) {
        for (int j = 0; j < verticesNum; ++j) {
            file >> result[i][j];
        }
    }

    file.close();
    return pair(result, verticesNum);
}

void FileData::saveMatrix(bool **graphMatrix, int verticesNum) {
    ofstream file;
    file.open(R"(D:\Programming\graph-coloring-bee\helpers\GraphMatrix.txt)");
    file << verticesNum << '\n';
    for (int i = 0; i < verticesNum; ++i) {
        for (int j = 0; j < verticesNum; ++j) {
            file << graphMatrix[i][j] << ' ';
        }
        file << '\n';
    }
    file.close();
}
