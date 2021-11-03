#include <iostream>
#include "helpers/Generator.h"
#include "work-classes/AlgorithmABC.h"

int main() {
    //Graph parameters
    const int VERTICES_NUM = 15;
    const int MIN_DEGREE = 1;
    const int MAX_DEGREE = 5;

    auto graphMatrix = Generator::generateGraphMatrix(VERTICES_NUM, MIN_DEGREE,MAX_DEGREE);
    for (int i = 0; i < VERTICES_NUM; ++i) {
        for (int j = 0; j < VERTICES_NUM; ++j) {
            cout << graphMatrix[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}
