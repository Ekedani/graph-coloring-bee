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

    void outputColors(){
        cout << "Current color scheme:";
        for (int i = 0; i < verticesColors.size(); ++i) {
            if(i % 60 == 0){
                cout << '\n';
            }
            cout << verticesColors[i] << ' ';
        }
    }

    //Function used to backup
    vector<int> getColors();
    void setColors(vector<int> backup);

    void dropColors(){
        verticesColors = vector<int>(vertices.size(), -1);
    }

    bool isZeroNectar(int num){
        bool result = true;
        for (int i = 0; i < vertices[num]->neighbors.size() && result; ++i) {
            result &= (verticesColors[vertices[num]->neighbors[i]] != -1);
        }
        return result;
    }

};
