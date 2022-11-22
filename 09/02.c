#include<stdio.h>
#define max 6

typedef struct{
    int data[max];
    int front,rear;
}queues;

typedef struct{
    int data[max];
    int top;
}stack;

int curr = 0;
queues q[2];

int insert(queues* q, int v){
    if(q->rear == max-1){
        printf("Not possible!!\n");
        return 1;
    }
    else if(q->front == -1){
        q->front = q->rear = 0;
        q->data[q->rear] = v;
    }
    else{
        q->rear++;
        q->data[q->rear] = v;
    }
    return 0;
}

int delete(queues* q,int* k){
    if(q->rear == -1){
        printf("Not possible!!");
        return 1;
    }
    else if(q->front  == q->rear){
        *k = q->data[q->front];
        q->rear = q->front = -1;
    }
    else{
        *k = q->data[q->front];
        for(int i = 0;i<q->rear;i++){
            q->data[i] = q->data[i+1];
        }
        q->rear--;
    }
    return 0;
}

void push(int v){
    insert(&q[curr],v);
}

void pop(int *k){
    int t;
    while(1){
        delete(&q[curr],&t);
        if(q[curr].front==-1){
            curr=(curr+1)%2;
            return;
        }
        insert(&q[(curr+1)%2],t);
    }
}

void display(){
    for(int i=0;i<=q[curr].rear;i++){
        printf("%d\t",q[curr].data[i]);
    }
    printf("\n");
}

void main(){
    int k;
    q[0].front = q[0].rear = q[1].front = q[1].rear = -1;
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    display();
    pop(&k);
    printf("k = %d\n",k);
    display();
}