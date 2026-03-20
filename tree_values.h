#ifndef TREE_VALUES
#define TREE_VALUES

struct treeValues
{
    int value = 0;
    bool valid = 0;

    treeValues(int _value, int _valid)
    {
        value = _value;
        valid = _valid;
    }
};

#endif