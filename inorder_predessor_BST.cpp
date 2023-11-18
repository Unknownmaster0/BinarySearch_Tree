#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }
};

Node *findPred(Node *root, Node *x)
{
    if (root == NULL)
        return NULL;

    Node *pred = NULL;
    while (root)
    {
        if (root->data >= x->data)
        {
            root = root->left;
        }
        else
        {
            pred = root;
            root = root -> right;
        }
    }

    return pred;
}

int main()
{

    return 0;
}