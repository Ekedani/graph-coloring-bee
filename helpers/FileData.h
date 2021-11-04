#include <string>
#include <fstream>

using namespace std;
class FileData {
public:
    static void saveMatrix(bool **graphMatrix, int verticesNum);
    static pair<bool**, int> readMatrix();
};


