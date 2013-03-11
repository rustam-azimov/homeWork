#include "consoleOutput.h"
#include <iostream>

using namespace std;

void ConsoleOutput::print() const {
    for (int i = 0; i < spiralSize; i++) {
        cout << spiralArray[i] << " ";
    }
    cout << endl;
}
