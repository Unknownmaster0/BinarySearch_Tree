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

/* working good but not optimised.
void createNode(Node *&root, Node* newNode)
{
    // for the first time when no node is created yet.
    if (root == NULL)
    {
        root = newNode;
    }
    else if (root->left == NULL && root->data > newNode->data)
    {
        root->left = newNode;
    }
    else if (root->right == NULL && root->data < newNode->data)
    {
        root->right = newNode;
    }
    else
    {
        if (root->data > newNode->data)
            createNode(root->left,newNode);
        else if (root->data < newNode->data)
            createNode(root->right,newNode);
    }
}
*/

Node* createNode(Node* root, int data){
    // base case -> you have come to insert the root node only.
    if(root == NULL){
        root = new Node(data);
        return root;
    }

    if(root-> data > data){
        root -> left = createNode(root->left, data);
    }
    else{
        root->right = createNode(root->right, data);
    }
}

// use the inorder traversal for the tree.
void printNode(Node *root)
{
    cout<<endl;
    if (root == NULL)
        return;

    // go to left
    printNode(root->left);
    // print the node
    cout << root->data << " ";
    // go to right
    printNode(root->right);
}

int main()
{
    Node *root = NULL;
    int val, choice = 1;
    cin>>val;

// if the val is -1 then simply end the tree.
    while(val != -1){
        root = createNode(root, val);
        cin>>val;
    }
    printNode(root);
    return 0;
}