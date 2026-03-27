#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "tree_values.h"

void loadNbN()
{
}
void loadBasicFile(std::vector<treeValues> &vTree)
{

    std::string fileName = "";

    std::cout << "\nPlease enter the file name..." << std::endl;
    std::cout << "\nYour input: ";
    std::cin.clear();
    std::cin >> fileName;

    std::ifstream vTreeFile(fileName);

    if (!vTreeFile.is_open())
    {
        std::cout << "Could not open the file..." << std::endl;
        return;
    }

    std::string fileLine = "";
    int number = 0;
    int sign = 1;
    int valid = 1;

    std::getline(vTreeFile, fileLine);
    for (int i = 0; i < fileLine.size(); i++)
    {
        if (fileLine[i] == '-')
        {
            sign = -1;
        }
        else if (std::isdigit(fileLine[i]))
        {
            number *= 10;
            number += (fileLine[i] - '0') * sign;
        }
    }

    // Do NOT assume the user is telling the truth. Force a cut off.
    if (number > 20)
    {
        std::cout << "There are too many nodes..." << std::endl;
    }

    number = 0;

    std::getline(vTreeFile, fileLine);
    // TODO: a quick check for validity, count how many ',' are present.
    for (int i = 0; i < fileLine.size(); i++)
    {
        if (std::isdigit(fileLine[i]))
        {
            number *= 10;
            number += (fileLine[i] - '0');
        }
        else if (fileLine[i] == 'n')
        {
            number = 0;
            valid = 0;
        }
        else if (fileLine[i] == ',' || fileLine[i] == ']')
        {
            treeValues newVal = treeValues(number, valid);
            vTree.push_back(newVal);
            number = 0;
            sign = 1;
            valid = 1;
        }

        if (number > 1000 || number < -1000)
        {
            vTree.clear();
            std::cout << "Tree contains a node w/ an invalid value..." << std::endl;
            return;
        }
        // TODO: first user out when there are too many nodes.
    }

    std::cout << "\n[";

    for (int i = 0; i < vTree.size() - 1; i++)
    {
        std::cout << vTree[i].value << ", ";
    }

    std::cout << vTree[vTree.size() - 1].value << "]" << std::endl;
}

bool basicTree(std::vector<treeValues> &vTree)
{
    std::cout << "Operations of a basic tree are..." << std::endl;
    std::cout << "   1. Pre-Order Traversal..." << std::endl;
    std::cout << "   2. In-Order Traversal..." << std::endl;
    std::cout << "   3. Post-Order Traversal..." << std::endl;
    std::cout << "   4. Level-Order Traversal..." << std::endl;
    std::cout << "   5. Add a Node..." << std::endl;
    std::cout << "   6. Delete a Node..." << std::endl;

    char userInput = '0';

    return true; // true to continue the program...

    while (true)
    {
        std::cout << "\nYour input: ";
        std::cin.clear();
        std::cin >> userInput;

        switch (userInput)
        {
        case 'x':
        {
            return false;
        }
        }
    }
}

void buildMenu(std::vector<treeValues> &vTree)
{

    char userInput = '0';

    std::cout << "\nHere are some base rules: " << std::endl;
    std::cout << "   -Values are only allowed to vary [-1000, 1000] and null..." << std::endl;
    std::cout << "   -Represent nullptrs as the singular character n..." << std::endl;
    std::cout << "   -Repeated values are allowed...." << std::endl;
    std::cout << "   -You can only have 25 nodes max..." << std::endl;

    std::cout << "\nWhich tree type would you like to build:" << std::endl;
    std::cout << "   1. Generic Tree..." << std::endl;
    std::cout << "   2. Binary Tree..." << std::endl;
    std::cout << "   3. Ternary Tree..." << std::endl;
    std::cout << "   4. AVL Tree..." << std::endl;
    std::cout << "   5. Red-Black Tree..." << std::endl;
    std::cout << "   6. Segment Tree..." << std::endl;
    std::cout << "   7. B-Tree..." << std::endl;
    std::cout << "     ***N-ary trees will be skipped as it builds on patterns between 2-node and 3-node trees..."
              << std::endl;
    std::cout << "x. Enter the letter \'x\' to quit the program..." << std::endl;

    while (true)
    {
        std::cout << "\nYour input: ";
        std::cin.clear();
        std::cin >> userInput;

        switch (userInput)
        {
        case 'x':
        {
            return;
        }
        case '1':
        {
            loadBasicFile(vTree);
            break;
        }
        case '2':
        {

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
    std::cout << "\nWelcome to my graph practice code..." << std::endl;

    std::vector<treeValues> vTree;
    buildMenu(vTree);

    std::cout << "\nThank you, bye!" << std::endl;

    return 0;
}