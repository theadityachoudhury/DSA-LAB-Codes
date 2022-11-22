#include<stdio.h>
#define max 5

typedef struct{
    int data[max];
    int front,rear;
}queue;
// typedef struct{
//     int data[max];
//     int top;
// }stack;
queue q;
int enqueue(queue* q, int v){
    if(q->rear == max-1){
        printf("Not possible overflow!!\n");
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
int dequeue(queue* q,int* k){
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
        enqueue(&q,v);
}
void pop(int *k){
int t;
    dequeue(&q,&t);
	*k=t;
}
void display(queue q){
    for(int i=0;i<=q.rear;i++){
        printf("%d\t",q.data[i]);
    }
    printf("\n");
}

void plusone(){
    int k,z=q.rear;
    for(int i=0;i<z;i++){
            dequeue(&q,&k);
	        enqueue(&q,k);
	}
}

int main(){
    int k;
    q.front=q.rear=-1;
    push(5);
    display(q);
    push(4);
    display(q);
    push(3);
    display(q);
    push(2);
    display(q);
    plusone();
    pop(&k);
    display(q);
    printf("deleted element:%d",k);
    return 0;
}