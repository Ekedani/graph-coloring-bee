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

    void outputColors();

    int getColor(int num){
        return verticesColors[num];
    }

    //Function used to backup
    vector<int> getColors();
    void setColors(vector<int> backup);

    void dropColors();

    bool isZeroNectar(int num);

};
