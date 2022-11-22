#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* l,*r;
};

struct node* insert(struct node* root,int v){
    if(root==NULL){
        struct node* curr = malloc(sizeof(struct node));
        curr->l = curr->r = NULL;
        curr->data = v;
        return curr;
    }
    else if(v>root->data){
        root->r = insert(root->r,v);
        return root;
    }
    else if(v<root->data){
        root->l = insert(root->l,v);
        return root;

    }
}

void inorder(struct node *root){
    if(root==NULL) return;
    inorder(root->l);
    printf("%d\t",root->data);
    inorder(root->r);
}

void main(){
    struct node* root=NULL;
    int n,v;
    printf("Enter the number of nodes:- ");
    scanf("%d",&n);
    printf("Enter the values- ");
    while(n){
        scanf("%d",&v);
        root = insert(root,v);
        n--;
    }
    printf("The tree is:- ");
    inorder(root);
}