class BasicTree
{
private:
    struct node
    {
        node *left;
        node *right;
        int value;

        node(node *_left, node *_right, int _value)
        {
            left = _left;
            right = _right;
            value = _value;
        }
    };

    node *root = nullptr;

    /*
    In a vector you can extract the following values:
        1. left 2*n + 1
        2. right 2*n + 2
        3. parent (n-1) / 2
    */

public:
    BasicTree(std::vector<int> tree)
    {
    }

    void preorder(node *n)
    {
        if (n == nullptr)
        {
            return;
        }
        cout << "We are currently at... " << n->value << std::endl;
        preorder(n->left);
        preorder(n->right);
    }
    void inorder(node *n)
    {
        if (n == nullptr)
        {
            return;
        }
        preorder(n->left);
        cout << "We are currently at... " << n->value << std::endl;
        preorder(n->right);
    }
    void postorder(node *n)
    {
        if (n == nullptr)
        {
            return;
        }
        preorder(n->left);
        preorder(n->right);
        cout << "We are currently at... " << n->value << std::endl;
    }
    void levelorder(node *n)
    {
        if (n == nullptr)
        {
            return;
        }
        std::queue<node *> level;
        int size = 0;
        int level = 1;

        if (root == nullptr)
        {
            std::cout << "We can not traverse a nullptr" << std::endl;
        }

        level.push(n);
        size = 1;

        while (size != 0)
        {
            node *front = level.front();
            level.pop();
            size--;
            std::cout << "We are currently at... " << n->value << " at level " << level << std::endl;
            if (n->left != nullptr)
            {
                level.push(n->left);
            }
            if (n->right != nullptr)
            {
                level.push(n->right);
            }

            if (size == 0 && !level.empty())
            {
                size = level.size();
                level++;
            }
        }
    }

    void addNode();
    void removeNode();
};