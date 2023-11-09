#include <iostream>

const size_t MAX_LEN = 1e6;
using namespace std;

struct Node
{
    size_t value = 0;

    Node *left = nullptr;
    Node *right = nullptr;

    long long ind = 0;
    size_t height = 0;

    Node(size_t val, long long ind, size_t height)
    {
        this->value = val;
        this->ind = ind;
        this->height = height;
    }
};

struct Tree
{
    Node *root = nullptr;

    Node* positive[MAX_LEN]{};
    Node* negative[MAX_LEN]{};

    void add(size_t val)
    {
        root = add(root, val);
    }
    
    Node* add(Node *node, size_t val, long long ind = 0, size_t height = 0) { 
       if (node == nullptr) {
           //cout << "add " << val << ' ' << ind << ' ' << height << endl;
            return new Node(val, ind, height);
        }

        ++height;
        //cout << val << ' ' << ind << ' ' << height << endl;
        if (val > node->value) {
            ++ind;
            node->right = add(node->right, val, ind, height);
        }
        
        if (val < node->value) {
            --ind;
            node->left = add(node->left, val, ind, height);
        }
        
        return node;
    }

    void traverse(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }

        if (node->ind > 0 && (positive[node->ind] == nullptr || positive[node->ind]->height > node->height))
        {
            positive[node->ind] = node;
        }

        if (node->ind < 0 && (negative[-node->ind] == nullptr || negative[-node->ind]->height > node->height))
        {
            negative[-node->ind] = node;
        }

        traverse(node->left);
        traverse(node->right);
    }

    void printTop()
    {
        traverse(root);

        long long j = 1;
        while (negative[j] != nullptr)
        {
            ++j;
        }

        --j;
        while (j > 0)
        {
            std::cout << negative[j]->value << " ";
            --j;
        }

        std::cout << root->value << " ";

        j = 1;
        while (positive[j] != nullptr)
        {
            std::cout << positive[j]->value << " ";
            ++j;
        }
        std::cout << std::endl;
    }
};

int main()
{

    size_t t;
    std::cin >> t;

    for (size_t i = 0; i < t; ++i)
    {
        Tree tree;
        size_t n;
        std::cin >> n;

        size_t x;

        for (size_t j = 0; j < n; ++j)
        {
            std::cin >> x;
            tree.add(x);
        }

        tree.printTop();
    }

    return 0;
}