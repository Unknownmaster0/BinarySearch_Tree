#include<iostream>
using namespace std;

/*Note -> The inorder traversal of the BST is always Sorted.
    The minimum value in the BST is the leftmost part node.
    The maximum value in the BSt is the rightmost part node.*/

class Node{
    public:
        int data;
        Node* left;
        Node* right;

    Node(int val){
        this -> data = val;
        left = NULL;
        right = NULL;
    }
};

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

Node* findMax(Node* root)
{
    if(root == NULL)
        return NULL;

    // go to the right continuously till you not find the right part is null pointer.
    while(root -> right != NULL)
        root = root -> right;

    return root;
}

Node* findMin(Node* root)
{
    if(root == NULL)
        return NULL;

    // go to the left continuously till you not find the left part is null pointer.
    while(root -> left != NULL)
        root = root -> left;

    return root;
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

    Node* maxi = findMax(root);
    cout<<"the maximum node is -> "<<maxi->data<<endl;

    Node* mini = findMin(root);
    cout<<"the minimum node is -> "<<mini->data<<endl;

    return 0;
}