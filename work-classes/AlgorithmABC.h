#include <vector>
#include <set>
#include <ctime>
#include "Graph.h"
#include "iostream"
#include <random>

using namespace std;

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

    void processVertex(int num, int beeNum);

    vector<int> sendForagers(vector<pair<int, int>> &destinations);

public:

    explicit AlgorithmABC(Graph *graphToProcess) {
        this->graphToProcess = graphToProcess;
        this->randomMachine.seed(time(nullptr));
        for (int i = 0; i < graphToProcess->getVerticesNum(); ++i) {
            allColors.push_back(i);
        }
    }

    void runAlgorithm(int iterations) {
        auto destinations = getDestinations();
        do {
            auto parameters = calculateBeesToSend(destinations);
            destinations = sendForagers(parameters);
        } while (!graphToProcess->isFullyColored());
        cout << "Visited: " << visitedVertices.size() << '\n';
        for (int i = 0; i < iterations && visitedVertices.size() < 300; ++i) {
            auto parameters = calculateBeesToSend(destinations);
            destinations = sendForagers(parameters);
        }
        cout << "Chromatic num: " << usedColors.size() << '\n';
        graphToProcess->outColors();
    }

    void resetAlgo() {
        visitedVertices.clear();
        usedColors.clear();
        graphToProcess->dropColors();
    }
};
