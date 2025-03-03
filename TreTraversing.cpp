#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node*left,*right;
    node(int val){
        data=val;
        left=right=NULL;
    }
};

void Postorder(node*root){
    if(root==NULL)return;
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";
}

void Inorder(node*root){
    if(root==NULL){
        return;
    }
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

void Preorder(node *root){
    if(root==NULL)return;
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}

int main(){
    node * root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->left->right->left=new node(7);

    cout<<"Preorder traversing : ";
    Preorder(root);
    cout<<"Inorder traversing : ";
    Inorder(root);
    cout<<"Postorder traversing : ";
    Postorder(root);
    return 0;
}


