#include <iostream>
#include "helpers/Generator.h"
#include "work-classes/AlgorithmABC.h"

int main() {
    //Graph parameters
    const int VERTICES_NUM = 300;
    const int MIN_DEGREE = 1;
    const int MAX_DEGREE = 30;

    auto graphMatrix = Generator::generateGraphMatrix(VERTICES_NUM, MIN_DEGREE,MAX_DEGREE);


    return 0;
}
