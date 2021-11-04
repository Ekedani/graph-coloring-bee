#include <vector>
#include <set>
#include <ctime>
#include <iostream>
#include <random>
#include "Graph.h"

using namespace std;

//Combination of the algorithm from the article and the lecture
class AlgorithmABC {
private:
    static const int SCOUTS_NUM = 5;
    static const int FORAGER_NUM = 55;
    vector<int> allColors;
    vector<int> usedColors;

    Graph *graphToProcess;
    set<int> visitedVertices;

    mt19937 randomMachine;

    //Returns current scout location
    //Select random unvisited vertex
    int moveScoutToRandom();

    //Set color considering information about usedColors
    //Use the smallest available color
    void colorVertex(int num);

    //Get SCOUTS_NUM destinations
    vector<int> getDestinations();

    //Original algorithm use probability, but this modification splits bees proportionally
    //Calculate number of foragers to each destination
    vector<pair<int, int>> calculateBeesToSend(vector<int> &destinations);

    //Forager stage for 1 vertex
    void processVertex(int num, int beeNum);

    //Start global forager stage
    vector<int> sendForagers(vector<pair<int, int>> &destinations);

public:
    //Initialize graph, generator and color palette
    explicit AlgorithmABC(Graph *graphToProcess) {
        this->graphToProcess = graphToProcess;
        this->randomMachine.seed(time(nullptr));
        for (int i = 0; i < graphToProcess->getVerticesNum(); ++i) {
            allColors.push_back(i);
        }
    }

    //
    void runAlgorithm(int iterations) {
        //Used to keep the result from degenerating
        int bestChromaticNumber = 300;
        vector<int> colorsBackup;
        for (int i = 0; i < iterations; ++i) {
            this->resetAlgorithmParameters();
            auto destinations = getDestinations();
            do {
                auto parameters = calculateBeesToSend(destinations);
                destinations = sendForagers(parameters);
            } while (!graphToProcess->isFullyColored());
            //TODO: Add used color validation
            //Compare this iteration with best previous
            if(bestChromaticNumber < this->usedColors.size()){
                graphToProcess->setColors(colorsBackup);
            }else{
                bestChromaticNumber = this->usedColors.size();
                colorsBackup = graphToProcess->getColors();
            }

            //Statistics
            if((i + 1) % 20 == 0 || i == 0){
                cout << "Iteration #" << i + 1 <<" chromatic num: " << bestChromaticNumber << '\n';
            }
        }
    }

    //Global algorithm reset. We use it because of random factor
    //A different choice of vertices could improve our results for a bit
    //If it becomes worse than existing - we will use backup
    void resetAlgorithmParameters() {
        visitedVertices.clear();
        usedColors.clear();
        graphToProcess->dropColors();
    }
};
