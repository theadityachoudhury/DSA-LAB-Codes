#include<stdio.h>
#include<stdlib.h>

struct node{
    char data[1];
    struct node* left,*right;
};

typedef struct{
    struct node* data[11];
    int top;
}stack;

struct node* createnode(char v[1]){
    struct node* curr = malloc(sizeof(struct node));
    curr->data[0] = v[0];
    curr->left = curr->right = NULL;
    return curr;
}


void inorder(struct node *root){
    if(root==NULL) return;
    inorder(root->left);
    printf("%c\t",root->data[0]);
    inorder(root->right);
}

void preorder(struct node *root){
    if(root==NULL) return;
    printf("%c\t",root->data[0]);
    preorder(root->left);
    preorder(root->right);
}
  
void postorder(struct node *root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%c\t",root->data[0]);
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
    printf("Inorder:- ");
    inorder(root);
    printf("\n");
    printf("Preorder:- ");
    preorder(root);
    printf("\n");
    printf("Postorder:- ");
    postorder(root);
    printf("\n");
}