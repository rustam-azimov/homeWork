#ifndef TICTACTOERULES_H
#define TICTACTOERULES_H

#include <QString>

/**
 * @file ticTacToeRules.h
 *
 * Class to play tic-tac-toe game.
 */

int const numOfButtons = 9;

/// @class TicTacToePlay implementation of game.
class TicTacToeRules
{
public:
    TicTacToeRules()
    {
        isX = true;
        arrayOfButtons = new int[numOfButtons];
        counter = 0;
        for (int i = 0; i < numOfButtons; i++)
        {
            arrayOfButtons[i] = 0;
        }
    }

    ~TicTacToeRules()
    {
        delete[] arrayOfButtons;
    }
    int isWin()
    {
        if (counter == 9)
            return 2;
        if ((arrayOfButtons[0] == arrayOfButtons[1]) && (arrayOfButtons[0] == arrayOfButtons[2]) && (arrayOfButtons[0] != 0))
            return arrayOfButtons[0];
        if ((arrayOfButtons[3] == arrayOfButtons[4]) && (arrayOfButtons[3] == arrayOfButtons[5]) && (arrayOfButtons[3] != 0))
            return arrayOfButtons[3];
        if ((arrayOfButtons[6] == arrayOfButtons[7]) && (arrayOfButtons[6] == arrayOfButtons[8]) && (arrayOfButtons[6] != 0))
            return arrayOfButtons[6];
        if ((arrayOfButtons[0] == arrayOfButtons[3]) && (arrayOfButtons[0] == arrayOfButtons[6]) && (arrayOfButtons[0] != 0))
            return arrayOfButtons[0];
        if ((arrayOfButtons[1] == arrayOfButtons[4]) && (arrayOfButtons[1] == arrayOfButtons[7]) && (arrayOfButtons[1] != 0))
            return arrayOfButtons[1];
        if ((arrayOfButtons[2] == arrayOfButtons[5]) && (arrayOfButtons[2] == arrayOfButtons[8]) && (arrayOfButtons[2] != 0))
            return arrayOfButtons[2];
        if ((arrayOfButtons[0] == arrayOfButtons[1]) && (arrayOfButtons[0] == arrayOfButtons[2]) && (arrayOfButtons[0] != 0))
            return arrayOfButtons[0];
        if ((arrayOfButtons[0] == arrayOfButtons[4]) && (arrayOfButtons[0] == arrayOfButtons[8]) && (arrayOfButtons[0] != 0))
            return arrayOfButtons[0];
        if ((arrayOfButtons[2] == arrayOfButtons[4]) && (arrayOfButtons[2] == arrayOfButtons[6]) && (arrayOfButtons[2] != 0))
            return arrayOfButtons[2];
        return 0;
    }

    QString setSign(int num)
    {
        if (arrayOfButtons[num] != 0)
            return " ";
        counter++;
        if (isX)
        {
            arrayOfButtons[num] = 1;
            isX = false;
            return "X";
        }
        else
        {
            arrayOfButtons[num] = -1;
            isX = true;
            return "O";
        }
    }
    bool isCross()
    {
        return isX;
    }

    void reset()
    {
        for (int i = 0; i < numOfButtons; i++)
            arrayOfButtons[i] = 0;
        isX = true;
        counter = 0;
    }

private:
    bool isX;
    int *arrayOfButtons;
    int counter;
};

#endif // TICTACTOERULES_H
