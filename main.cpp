#include "helpers/Generator.h"
#include "helpers/FileData.h"
#include "work-classes/AlgorithmABC.h"

int main() {
    //Graph parameters
    const int VERTICES_NUM = 300;
    const int MIN_DEGREE = 1;
    const int MAX_DEGREE = 30;

    //Let the user choice
    char choice;
    cout << "Would you like to generate random graph or input it from the file? (R/F)\n"; cin >> choice;
    bool **graphMatrix;
    if(choice == 'R' || choice == 'r'){
        graphMatrix = Generator::generateGraphMatrix(VERTICES_NUM, MIN_DEGREE,MAX_DEGREE);
        FileData::saveMatrix(graphMatrix, VERTICES_NUM);
    }else{
        graphMatrix = FileData::readMatrix().first;
    }
    cout << "You can see your matrix in the GraphMatrix.txt file\n";

    //Main part of the algorithm
    auto graph = new Graph(graphMatrix, VERTICES_NUM);
    auto algorithm = AlgorithmABC(graph);
    algorithm.runAlgorithm(1000);
    graph->outputColors();
    return 0;
}
