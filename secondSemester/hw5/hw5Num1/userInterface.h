#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <iostream>

#include "hasher.h"

/**
* @file userInterface.h
*
* @section DESCRIPTION
*
* Implementation of user interface.
*/

enum Command {
    ext = 0,
    add,
    rmv,
    find,
    chFun,
    stats,
    hlp
};

void help()
{
    std::cout << "You can use this commands:\n"
                 " 1 - add value to table\n"
                 " 2 - remove value from table\n"
                 " 3 - find value in table\n"
                 " 4 - change hash function\n"
                 " 5 - print hash-table statistics\n"
                 " 6 - print list of commands\n"
                 " 0 - exit the program\n\n";
}

bool isCommand(int value)
{
    if (!((value >= 0) && (value <= 6)))
        return false;
    return true;
}

bool isChangeFun(int value)
{
    if (!((value >= 0) && (value <= 2)))
        return false;
    return true;
}

void work()
{
    std::cout << "This program to work with hash-tables\n\n";
    help();
    int cmd;
    Hasher *hasher = new Hasher();
    while (true)
    {
        std::cin >> cmd;
        while (!isCommand(cmd))
        {
            std::cout << "Bad command!\n";
            std::cin >> cmd;
        }
        switch (cmd)
        {
        case (ext):
        {
            std::cout << "Goodbye!";
            delete hasher;
            return;
        }
        case (add):
        {
            std::cout << "Enter the value to add ";
            int value = 0;
            std::cin >> value;
            hasher->addToHash(value);
            break;
        }
        case (rmv):
        {
            std::cout << "Enter the value to remove ";
            int value = 0;
            std::cin >> value;
            hasher->removeFromHash(value);
            break;
        }
        case (find):
        {
            std::cout << "Enter the value to search ";
            int value = 0;
            std::cin >> value;
            if (hasher->isContained(value))
                std::cout << "The value is contained in hash-table\n";
            else
                std::cout << "The value is not contained in hash-table\n";
            break;
        }
        case (chFun):
        {
            std::cout << "You can change hash function\n"
                         "Enter the: \n"
                         " 1 - by mod\n"
                         " 2 - by '37 * value + 41' and by mod\n"
                         " 3 - by sum of the digits and by mod\n"
                         " 0 - do not change function\n";
            int type;
            std::cin >> type;
            while (!isChangeFun(type))
            {
                std::cout << "Bad command!";
                std::cin >> type;
            }
            if (type != 0)
            {
                hasher->rehash((HashType)type);
                std::cout << "Hash function is changed\n";
            }
            break;
        }
        case (stats):
        {
            hasher->printStatistic();
            break;
        }
        case (hlp):
        {
            help();
            break;
        }
        }
    }
}

#endif // USERINTERFACE_H
