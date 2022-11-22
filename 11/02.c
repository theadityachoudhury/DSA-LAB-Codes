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

struct node* find_max(struct node* root){
    if(root==NULL) return NULL;
    return find_max(root->r);
}

struct node* del(struct node* root,int v){
    if(root==NULL) return NULL;
    if(v>root->data){
        root->r = del(root->r,v);
        return root;
    }
    if(v<root->data){
        root->l = del(root->l,v);
        return root;
    }
    if(v==root->data){
        if(root->l!=NULL && root->r!=NULL){
            struct node* curr = find_max(root->l);
            root->data = curr->data;
            root->l = del(root->l,curr->data);
            return root;
        }
        if(root->r==NULL){
            struct node* tmp = root->l;
            free(root);
            return tmp;
        }
        if(root->l==NULL){
            struct node* tmp = root->r;
            free(root);
            return tmp;
        }

    }
}

void inorder(struct node *root){
    if(root==NULL) return;
    inorder(root->l);
    printf("%d\t",root->data);
    inorder(root->r);
}

void preorder(struct node *root){
    if(root==NULL) return;
    printf("%d\t",root->data);
    preorder(root->l);
    preorder(root->r);
}

void postorder(struct node *root){
    if(root==NULL) return;
    postorder(root->l);
    postorder(root->r);
    printf("%d\t",root->data);
}

void main(){
    struct node* root=NULL;
    int n=1,v,c;
    printf("Enter your choice- ");
    while(n){
        scanf("%d",&c);
        if(c == 1 || c == 2){
            printf("Enter the value:- ");
            scanf("%d",&v);
            root = insert(root,v);
        }
        else if(c == 3){
            printf("Enter the value:- ");
            scanf("%d",&v);
            root = del(root,v);
        }
        else if(c==4){
            printf("The tree is:- ");
            inorder(root);
            printf("\n");
        }
        else if(c==5){
            printf("Inorder:- ");
            inorder(root);
            printf("\n");
            printf("preorder:- ");
            preorder(root);
            printf("\n");
            printf("Postorder:- ");
            postorder(root);
            printf("\n");
        }
        else if(c==6) n = 0;
        else printf("Enter correct values!!!");

    }
}