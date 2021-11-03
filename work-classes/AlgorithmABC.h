#include <vector>
#include <set>
#include <ctime>
#include "Graph.h"

using namespace std;

class AlgorithmABC {
private:
    static const int SCOUTS_NUM = 5;
    static const int FORAGER_NUM = 55;
    vector<int> allColors;
    vector<int> usedColors;

    Graph *graphToProcess;
    set<int> visitedVertices;

    //Returns current scout location
    int moveScoutToRandom();

    //Set color considering information about usedColors
    void colorVertex(int num);

    //Get SCOUTS_NUM destinations
    vector<int> getDestinations();

    //Original algorithm use probability, but this modification splits bees proportionally
    vector<pair<int, int>> calculateBeesToSend(vector<int> &destinations);

    void processVertex(int num, int beeNum);

    vector<int> sendForagers(vector<pair<int, int>> &destinations);

public:

    explicit AlgorithmABC(Graph* graphToProcess){
        this->graphToProcess = graphToProcess;
        for (int i = 0; i < graphToProcess->getVerticesNum(); ++i) {
            allColors.push_back(i);
        }
    }

    void runAlgorithm(){
        auto destinations = getDestinations();
        do{
            auto parameters = calculateBeesToSend(destinations);
            destinations = sendForagers(parameters);
        }while(!graphToProcess->isFullyColored());
    }

};
