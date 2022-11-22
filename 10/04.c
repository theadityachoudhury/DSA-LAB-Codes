#include<stdio.h>
#include<stdlib.h>

struct node{
    char data[1];
    struct node* left,*right;
};

struct node* createnode(char v[1]){
    struct node* curr = malloc(sizeof(struct node));
    curr->data[0] = v[0];
    curr->left = curr->right = NULL;
    return curr;
}

void inorder(struct node *root){
    if(root==NULL) return;
    inorder(root->left);
    if((root->left == NULL && root->right!=NULL) || (root->left != NULL && root->right==NULL)) printf("%c\t",root->data[0]);
    inorder(root->right);
}

void main(){
    struct node* root;
    root = createnode("A");
    root->left = createnode("B");
    root->left->left = createnode("D");
    root->left->right = createnode("E");
    root->left->right->left = createnode("F");
    root->right = createnode("C");
    root->right->left = createnode("G");
    root->right->right = createnode("H");
    root->right->right->left = createnode("J");
    root->right->right->right = createnode("K");
    root->right->right->left->left = createnode("L");
    inorder(root);
}