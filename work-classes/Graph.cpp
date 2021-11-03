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
