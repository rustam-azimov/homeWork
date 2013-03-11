#include "fileOutput.h"

#include <fstream>

using namespace std;

void FileOutput::print() const {
    ofstream output("output.txt");
    for (int i = 0; i < spiralSize; i++)
        output << spiralArray[i] << " ";
    output.close();
}
