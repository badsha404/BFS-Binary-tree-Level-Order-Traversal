#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node* FindMin(Node* root)
{
    while(root->left!=NULL) root->left;
    return root;
}


Node* Delete(Node* root,int data)
{
    if(root==NULL)return root;
    else if(data < root->data) root->left = Delete(root->left,data);
    else if(data > root->data) root->right = Delete(root->right,data);

    else{
        // Case 1: No child
        if(root->left == NULL && root->right == NULL){
            delete root;
            root = NULL;
        }
        //Case 2: 1 child
        else if(root->left==NULL){
            Node* temp = root;
            root = root->right;
            delete  temp;
        }
        else if(root->right==NULL)
        {
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        //Case 3: 2 Child;
        else{
            Node* temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right,temp->data);
        }
    }
    return root;

}

//Function to visit nodes in Inorder
void Inorder(Node* root)
{
    if(root==NULL)return;
    Inorder(root->left);
    printf("%d ",root->data);
    Inorder(root->right);
}

// Function to Insert Node in a Binary Search Tree

Node* Insert(Node* root,int data)
{
    if(root==NULL){
        root = new Node();
        root->data = data;
        root->left = root->right =NULL;
    }
    else if(data<=root->data){
        root->left = Insert(root->left,data);
    }else{
        root->right = Insert(root->right,data);
    }
    return root;

}
int main()
{
    /*Code To Test the logic
	  Creating an example tree
                5
			   / \
			  3   10
			 / \   \
			1   4   11
    */

    Node* root = NULL;
    root = Insert(root,5);root = Insert(root,10);
    root = Insert(root,3);root = Insert(root,4);
    root = Insert(root,1);root = Insert(root,11);

    //Delete a Node from tree;
    root = Delete(root,5);

    //Print Node in inorder;
    printf("Inorder: ");
    Inorder(root);
    cout<<"\n";


    return 0;
}
