#pragma once

#include <utility>
#include <vector>
#include "iostream"

using namespace std;

struct Vertex {
    vector<int> neighbors;
};

class Graph {
private:
    vector<Vertex *> vertices;
    vector<int> verticesColors;
public:
    //Create graph from bool matrix
    Graph(bool **graphMatrix, int verticesNum);

    //Get vertex by number
    Vertex *getVertex(int num);

    //Returns true if success
    bool setColor(int num, int colorToSet);

    //Get num of vertices
    int getVerticesNum();

    bool isFullyColored();

    void outColors(){
        for(auto color : verticesColors){
            cout << color << ' ';
        }
    }

    vector<int> getColors(){
        return verticesColors;
    }

    void setColors(vector<int> backup){
        verticesColors = std::move(backup);
    }

    void dropColors(){
        verticesColors = vector<int>(vertices.size(), -1);
    }

    bool isColored(int num){
        return verticesColors[num] != -1;
    }

    bool isZeroNectar(int num){
        bool result = true;
        for (int i = 0; i < vertices[num]->neighbors.size() && result; ++i) {
            result &= (verticesColors[vertices[num]->neighbors[i]] != -1);
        }
        return result;
    }
};
