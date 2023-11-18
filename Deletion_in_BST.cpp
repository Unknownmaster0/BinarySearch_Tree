#include <iostream>
using namespace std;

// Deletion in BST has 3 cases ->
/*  1. if the deleting node has 0 child.
    2. if the deleting node has 1 child.
    3. if the deleting node has 2 child.*/
/*if the node has 0 children then it is easy simply delete that node and return NULL.*/
/*if the node has 1 children then store the children part and delete that node and return the children part.*/
/*if the node has 2 children then You have two choices ->
1. either you take out the maximum element from the left subtree and copy the data to the current root.
2. or you can take out the minimum element from the right subtree and copy the data to the current root.*/
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

// function to find the maximum element in the BST.
Node* findMax(Node* root)
{
    if(root == NULL)
        return NULL;

    // go to the right continuously till you not find the right part is null pointer.
    while(root -> right != NULL)
        root = root -> right;

    return root;
}

// function to delete the node in BST.
Node *deleteNode(Node *root, int val)
{
    if (root == NULL)
        return NULL;

    if (root->data == val)
    {
        // then you need to delete the Node.

        // if the deleting node has 0 children
        if(root -> left == NULL && root -> right == NULL)
        {
            cout<<"when the node has 0 children"<<endl;
            cout<<"deleting node -> "<<root -> data<<endl;
            delete root;
            return NULL;
        }

        // if the deleting node has 1 children
        // if the children in the left part
        if(root -> left != NULL && root-> right == NULL)
        {
            cout<<"when the children in left part "<<endl;
            // store the node
            Node* store = root -> left;
            cout<<"store -> "<<store->data<<endl;
            cout<<"deleting node -> "<<root -> data<<endl;
            delete root;
            return store;
        }
        // if the children in the right part
        if(root -> left == NULL && root -> right != NULL)
        {
            cout<<"when the children in the right part "<<endl;
            // store the Node
            Node* store = root -> right;
            cout<<"store -> "<<store->data<<endl;
            cout<<"deleting node -> "<<root -> data<<endl;
            delete root;
            return store;
        }
    
        // if the node has 2 children.
        if(root -> left != NULL && root -> right != NULL)
        {
            // use your choice -> find the max from the left subtree or min from the right subtree.
            int maxi = findMax(root->left)->data;
            cout<<"maxi -> "<<maxi<<endl;
            // copy that element to the root->data
            cout<<"root data before copying -> "<<root -> data<<endl;
            root->data = maxi;
            cout<<"root data after copying -> "<<root->data<<endl;
            // now go and delete the maxi element form the left part of the subtree.
            root -> left = deleteNode(root->left, maxi);
        }

    }
    else if (root->data > val){
        cout<<"i am going in the left part of "<<root->data<<endl;
        root->left = deleteNode(root->left, val);
    }
    else{
        cout<<"i am going in the right part of "<<root->data<<endl;
        root->right = deleteNode(root->right, val);
    }
}

// function to create the BST.
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
    Node* root = NULL;
    int val;
    cin>>val;
    while(val != -1)
    {
        root = createNode(root,val);
        cin>>val;
    }
    printNode(root);
    cout<<endl;

    root = deleteNode(root,5);

    printNode(root);
    cout<<endl;

    return 0;
}