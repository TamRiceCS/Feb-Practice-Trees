#include <iostream>
#include <string>
#include "tree_values.h"

void loadFile();
void loadNbN(); // load node by node

void buildMenu(int &step)
{

    char userInput = '0';
    std::cout << "How would you like to build your tree:" << std::endl;
    std::cout << "   1. Give a file that contains the graph in vector form..." << std::endl;
    std::cout << "   2. Generate a graph giving nodes one at a time..." << std::endl;
    std::cout << "   Press \'x\' to exit the program..." << std::endl;

    std::cout << "\nYour input: ";
    std::cin.clear();
    std::cin >> userInput;

    while (true)
    {
        switch (userInput)
        {
        case 'x':
        {
            step = 0;
            return;
        }
        case '1':
        {
            std::cout << "Please enter the file name..." << std::endl;
            break;
        }
        case '2':
        {
            std::cout << "Here are some base rules: " << std::endl;
            std::cout << "   1. Values are only allowed to vary [-1000, 1000] and null..." << std::endl;
            std::cout << "   2. You can only have 25 nodes max..." << std::endl;

            break;
        }
        default:
        {
            std::cout << "Sorry, that is not a valid input. Try again..." << std::endl;
            break;
        }
        }
    }
}

int main()
{
    int step = 1;
    std::cout << "\nWelcome to my graph practice code." << std::endl;

    if (step == 1)
    {
        buildMenu(step);
    }
    std::cout << "\nThank you, bye!" << std::endl;

    return 0;
}