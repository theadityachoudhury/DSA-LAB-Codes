#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

typedef struct{
    struct node* front;
    struct node* rear;
}queues;

int insert(queues* q1,int v){
    struct node* p = malloc(sizeof(struct node));
    if(p==NULL){
        printf("Overflow!!\n");
        return 1;
    }
    p->data = v;
    p->next = NULL;
    if(q1->front == NULL){
        q1->front = q1->rear = p;
    }
    else{
        q1->rear->next = p;
        q1->rear = p;
    }
    return 0;
}

int delete(queues* q,int* k){
    if(q->front == NULL){
        printf("Not Possible\n");
        return 1;
    }
    else if(q->front->next == NULL){
        *k = q->front->data;
        q->front = q->rear = NULL;
    }
    else{
        struct node* p = q->front;
        *k = q->front->data;
        q->front = q->front->next;
        free(p);
    }
}


void display(struct node* q){
    struct node* p = q;
    if(p == NULL){
        printf("Empty!!\n");
        return;
    }
    while(p!=NULL){
        printf("%d\t",p->data);
        p = p->next;
    }
    printf("\n");
}

void peek(struct node* q){
    if(q == NULL){
        printf("Empty\n");
        return;
    }
    printf("%d\n",q->data);
}

int isempty(queues q){
    if(q.front==NULL) return 1;
    return 0;
}
int isfull(queues q){
    struct node* p = malloc(sizeof(struct node));
    if(p==NULL) return 1;
    return 0;
}


void main(){
    queues q1;
    q1.front = q1.rear = NULL;
    int k,condition = 1,choice,v,zz;
    printf("Enter\n 1. for insertion \n 2. for deletion \n 3. for displaying \n 4. for peeking \n 5. for isempty \n 6. for isfull \n 7 for quit!! \n");
    while (condition){
        printf("Enter your choice:- ");
        scanf("%d",&choice);
        if(choice==1){
            printf("Enter the value to insert:- ");
            scanf("%d",&v);
            insert(&q1,v);
            printf("Data inserted sucessfully!!\n\n");
        }
        else if(choice == 2){
            delete(&q1,&k);
            printf("Data deleted -> %d\n\n",k);
        }
        else if(choice == 3){
            display(q1.front);
        }
        else if(choice == 4){
            peek(q1.front);
            printf("\n\n");
        }
        else if(choice == 5){
            zz = isempty(q1);
            if(zz) printf("Queue is empty");
            else printf("Queue has items!!");
        }

        else if(choice == 6){
            zz = isfull(q1);
            if(zz) printf("Queue is full");
            else printf("Queue is not full!!");
        }
        else if(choice == 7) condition = 0;
        else printf("Please choose correct option!!\n");

    }
}