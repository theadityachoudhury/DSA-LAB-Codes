#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
}*head=NULL,*tail=NULL;

int crnode(int n){
    struct node* c;
    for (int i = 0; i < n; i++)
    {
        c = (struct node*)malloc(sizeof(struct node));
        printf("Enter the value of element %d:- ",i);
        scanf("%d",&c->data);
        c->next = NULL;
        if (head == NULL){
            head = tail = c;
        }
        else{
            tail->next = c;
            tail = c;
        }
    }
    
}

void display(){
    struct node* c;
    c = head;
    while(c!=NULL){
        printf("%d\t",c->data);
        c = c->next;
    }
}


void insert(int v,int p){
    struct node *c,*ptr;
    c = (struct node*)malloc(sizeof(struct node));
    c->data = v;
    c->next = NULL;
    if(head==NULL){
        head = tail = c;
    }
    else if(p==0){
        c->next = head;
        head = c;
    }
    else{
        ptr = head;
        for (int i = 0; i < p-1 && ptr->next!= NULL; i++)
        {
            ptr = ptr->next;
        }
        if (ptr->next==NULL){
            tail->next = c;
            tail = c;
        }
        else{
            c->next = ptr->next;
            ptr->next = c;
        }
        
    }
}


void main(){
    int choice,condition=1,n=0,v,p=0,count=0;
    while (condition)
    {
        printf("\n\n\nEnter\n 1 to create a list \n 2 to display the content of the list \n 3 to Insert a node at the beginning of the list \n 4 to Insert a node at the end of the list \n 5 to Insert a node after kth node into the list \n 6 to quit the program \n Enter your choice:- ");
        scanf("%d",&choice);
        if (choice==1){
            printf("\n\nEnter the number of nodes:- ");
            scanf("%d",&n);
            count+=n;
            crnode(n);
        }
        else if(choice == 2){
            printf("\n");
            display();
        }
        else if(choice == 3){
            printf("\n\nEnter the value to be inserted:- ");
            scanf("%d",&v);
            insert(v,0);
            printf("The list after adding %d in position 0 is:-",v);
            display();
            count++;
        }
        else if(choice == 4){
            printf("\n\nEnter the value to be inserted:- ");
            scanf("%d",&v);
            insert(v,count++);
            printf("The list after adding %d in the end is:-",v);
            display();
        }
        else if(choice == 5){
            printf("\n\nEnter the value to be inserted:- ");
            scanf("%d",&v);
            printf("Enter the position:- ");
            scanf("%d",&p);
            insert(v,p);
            count++;
            printf("The list after adding %d in the end is:-",v);
            display();
        }
        else if(choice == 6) condition = 0;
        else printf("Please enter correct choice!!");
    }
}