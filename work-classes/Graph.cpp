#include "Graph.h"

Graph::Graph(bool **graphMatrix, int verticesNum) {
    for (int i = 0; i < verticesNum; ++i) {
        vertices.push_back(new Vertex);
        for (int j = 0; j < verticesNum; ++j) {
            if (graphMatrix[i][j]) {
                vertices[i]->neighbors.push_back(j);
            }
        }
    }
    verticesColors = vector<int>(vertices.size(), -1);
}

Vertex *Graph::getVertex(int num) {
    return vertices[num];
}

int Graph::getVerticesNum() {
    return vertices.size();
}

bool Graph::setColor(int num, int colorToSet) {
    for(auto neighbor : vertices[num]->neighbors){
        if(verticesColors[neighbor] == colorToSet){
            return false;
        }
    }
    verticesColors[num] = colorToSet;
    return true;
}

bool Graph::isFullyColored() {
    for(auto color : verticesColors){
        if(color == -1){
            return false;
        }
    }
    return true;
}

vector<int> Graph::getColors() {
    return verticesColors;
}

void Graph::setColors(vector<int> backup) {
    verticesColors = std::move(backup);
}

bool Graph::isZeroNectar(int num) {
    bool result = true;
    for (int i = 0; i < vertices[num]->neighbors.size() && result; ++i) {
        result &= (verticesColors[vertices[num]->neighbors[i]] != -1);
    }
    return result;
}

void Graph::dropColors() {
    verticesColors = vector<int>(vertices.size(), -1);
}

void Graph::outputColors() {
    cout << "Current color scheme:";
    for (int i = 0; i < verticesColors.size(); ++i) {
        if(i % 60 == 0){
            cout << '\n';
        }
        cout << verticesColors[i] << ' ';
    }
}
