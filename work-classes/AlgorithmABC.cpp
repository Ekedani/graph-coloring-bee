#include "AlgorithmABC.h"

int AlgorithmABC::moveScoutToRandom() {
    int vertexNum = -1;
    while (vertexNum == -1 && visitedVertices.size() != graphToProcess->getVerticesNum()) {
        int randomAttempt = randomMachine() % graphToProcess->getVerticesNum();
        if (!visitedVertices.contains(randomAttempt)) {
            vertexNum = randomAttempt;
            visitedVertices.insert(vertexNum);
        }
    }
    return vertexNum;
}

void AlgorithmABC::colorVertex(int num) {
    //For the first color
    if (usedColors.empty()) {
        usedColors.push_back(allColors[0]);
        //Always successful
        graphToProcess->setColor(num, usedColors[0]);
    } else {
        //Check colors in usedColors
        for (int color = 0; color < usedColors.size(); ++color) {
            if (graphToProcess->setColor(num, color)) {
                return;
            }
        }
        //New color in palette
        usedColors.push_back(allColors[usedColors.size()]);
        graphToProcess->setColor(num, usedColors[usedColors.size() - 1]);
    }
}

vector<int> AlgorithmABC::getDestinations() {
    vector<int> destinations;
    for (int i = 0; i < SCOUTS_NUM; ++i) {
        auto dest = moveScoutToRandom();
        if (dest == -1) {
            return destinations;
        }
        destinations.push_back(dest);
    }
    return destinations;
}

vector<pair<int, int>> AlgorithmABC::calculateBeesToSend(vector<int> &destinations) {
    vector<pair<int, int>> result;
    int degreeSum = 0;
    for (auto destination : destinations) {
        degreeSum += graphToProcess->getVertex(destination)->neighbors.size();
    }
    float onePart = float(FORAGER_NUM) / float(degreeSum);
    int usedTotal = 0;
    for (int i = 0; i < destinations.size() - 1; ++i) {
        int beeNum = int(graphToProcess->getVertex(destinations[i])->neighbors.size() * onePart);
        result.emplace_back(destinations[i], beeNum);
        usedTotal += beeNum;
    }
    int lastBeeNum = FORAGER_NUM - usedTotal;
    result.emplace_back(destinations[destinations.size() - 1], lastBeeNum);
    return result;
}

void AlgorithmABC::processVertex(int num, int beeNum) {
    auto neighborsAmount = graphToProcess->getVertex(num)->neighbors.size();
    for (int i = 0; i < beeNum && i < neighborsAmount; ++i) {
        auto neighborNum = graphToProcess->getVertex(num)->neighbors[i];
        colorVertex(neighborNum);
    }
    colorVertex(num);
}

vector<int> AlgorithmABC::sendForagers(vector<pair<int, int>> &destinations) {
    vector<int> newScouts;
    for (auto destination : destinations) {
        processVertex(destination.first, destination.second);
        newScouts.push_back(moveScoutToRandom());
    }
    return newScouts;
}
