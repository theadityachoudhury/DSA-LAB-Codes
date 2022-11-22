#include<stdio.h>
#define max 5

typedef struct{
    int data[max];
    int front,rear;
}queues;

typedef struct{
    int data[max];
    int top;
}stack;

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

void push(stack *s,int v){
    if(s->top==max){
        printf("Overflow\n");
        return;
    }
    else{
        s->top++;
        s->data[s->top] = v;
    }
}

void pop(stack *s,int* k){
    if(s->top==-1) return;
    else{
        *k = s->data[s->top];
        s->top--;
    }
}


void reverse(queues* q){
    stack s;
    int k;
    while(q->rear!=-1){
        delete(q,&k);
        push(&s,k);
    }

    while(s.top!=-1){
        pop(&s,&k);
        insert(q,k);
    }
}


void qdisplay(queues q){
    for(int i=0;i<=q.rear;i++){
        printf("%d\t",q.data[i]);
    }
    printf("\n");
}

void main(){
    queues q;
    int t;
    q.front = q.rear = -1;
    insert(&q,1);
    insert(&q,2);
    insert(&q,3);
    insert(&q,4);
    insert(&q,5);
    qdisplay(q);
    reverse(&q);
    qdisplay(q);
}