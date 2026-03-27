class BasicTree
{
private:
    struct node
    {
        node *left;
        node *right;
        int value;
        bool valid;
        std::string type;

        node(node *_left, node *_right, int _value, bool _valid)
        {
            left = _left;
            right = _right;
            value = _value;
            valid = _valid;
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
    BasicTree(std::vector<legalValues> tree)
    {
        root = new node(tree[0], nullptr, nullptr, true);

        int index = 1;
        std::queue<node *> traverse;
        traverse.push(root);

        while (index < tree.size() && !traverse.empty())
        {
            node *parent = traverse.front();
            traverse.pop();

            if (parent == nullptr)
            {
                index += 2;
                continue;
            }

            int value = 0;
            if (tree[index].legal)
            {
            }
            parent->left = new node(tree[index++].value, nullptr, nullptr);
            parent->right = new node(tree[index++].value, nullptr, nullptr);

            traverse.push(parent->left);
            traverse.push(parent->right);
        }
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

    /*
    1. Find parent by value, report back all nodes that match and their children, let user confirm
    2. If ambiguous where to add (can be left or right child), ask!
    3. Create and append to nodes.
    4. REJECT additions that are out of bounds of tree size.
    */
    void addNode();
    /*
    3 add cases need to consider
        - no children = just remove
        - one child = replace parent w/ child
        - two children = no set rule but pick left as parent then right as it's left child
    */
    void removeNode();
};