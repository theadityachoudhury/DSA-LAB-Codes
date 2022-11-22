#include<stdio.h>
#include<stdlib.h>

struct node{
    int r,c,v;
    struct node* next;
};

void create(struct node** h){
    struct node *l;
    l = malloc(sizeof(struct node));
    (*h) = l;
    scanf("%d %d %d",&(*h)->r,&(*h)->c,&(*h)->v);
    (*h)->next = NULL;
    for (int i = 0; i < (*h)->v; i++)
    {
        struct node *curr;
        curr = malloc(sizeof(struct node));
        scanf("%d %d %d",&curr->r,&curr->c,&curr->v);
        curr->next = NULL;
        l->next = curr;
        l = curr;
    }
    
}

void transpose(struct node *h){
    struct node *p = h;
    while(p!=NULL){
        int c = p->r;
        p->r = p->c;
        p->c = c;
        p = p->next;
    }
}

void display(struct node *h){
    struct node *p = h;
    while(p!=NULL){
        printf("%d %d %d\n",p->r,p->c,p->v);
        p = p->next;
    }
}

void main(){
    struct node *head = NULL;
    create(&head);
    transpose(head);
    display(head);
}