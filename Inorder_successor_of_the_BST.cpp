#include<iostream>
using namespace std;

// question link -> https://practice.geeksforgeeks.org/problems/inorder-successor-in-bst/1

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

// function to return the inorder successor.
Node * inOrderSuccessor(Node *root, Node *x)
{
    if(root == NULL)    
        return NULL;
        
    Node* succ = NULL;
    while(root)
    {
/* You can avoid these lines just by adding the equality sign to the if statement.
        if(root -> data == x->data)
        {
            if(root -> right != NULL)
            {
                Node* temp = root->right;
                while(temp -> left)
                    temp = temp -> left;
                    
                succ = temp;
                return succ;
            }
            else 
                break;
        }
*/
        if(root -> data <= x->data)
        {
            root = root -> right;
        }
        else{
            succ = root;
            root = root -> left;
        }
    }
    
    return succ;
}

int main()
{
    
    return 0;
}