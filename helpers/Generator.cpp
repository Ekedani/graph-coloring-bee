#include "Generator.h"

bool **Generator::generateGraphMatrix(int verticesNum, int minDegree, int maxDegree) {
    auto result = new bool *[verticesNum];
    for (int i = 0; i < verticesNum; ++i) {
        result[i] = new bool[verticesNum]{};
    }
    //Counting connections every time we need it is extremely ineffective
    auto connections = new int[verticesNum]{};
    //Generate random
    srand(time(nullptr));
    for (int i = 0; i < verticesNum; ++i) {
        int generatedConnections = connections[i];
        for (int j = i + 1; j < verticesNum; ++j) {
            auto probability = rand() % verticesNum;
            //Of course, you can change probability, but I wouldn't recommend you
            if (probability < 20 && connections[j] < maxDegree) {
                result[i][j] = true;
                result[j][i] = true;
                connections[i]++;
                connections[j]++;
                generatedConnections++;
            }
            if(generatedConnections > maxDegree){
                break;
            }
        }
        if (generatedConnections < minDegree) {
            while (!generatedConnections) {
                auto vertToConnect = i + (rand() % (verticesNum - i + 1));
                if (connections[vertToConnect] < maxDegree) {
                    result[i][vertToConnect] = true;
                    result[vertToConnect][i] = true;
                    connections[i]++;
                    connections[vertToConnect]++;
                    generatedConnections++;
                }
            }
        }
    }
    delete[] connections;
    return result;
}
