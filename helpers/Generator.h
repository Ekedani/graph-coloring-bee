#pragma once

#include <ctime>
#include <cstdlib>

using namespace std;

class Generator {
public:
    //Terrible graph generator, thanks to legacy from C
    static bool **generateGraphMatrix(int verticesNum, int minDegree, int maxDegree);
};