#pragma once
class Generator {
public:
    static bool** generateGraphMatrix(int verticesNum, int minDegree, int maxDegree){
        auto result = new bool*[verticesNum];
        for (int i = 0; i < verticesNum; ++i) {
            result[i] = new bool[verticesNum];
        }

        return result;
    }
};