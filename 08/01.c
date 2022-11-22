#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int* data;
    int front,rear;
}queues;
int n;

void insert(queues *q,int v){
    if(q->front == (q->rear+1)%n){
        printf("Queue is full\n");
    }
    else if(q->front==-1){
        q->front=q->rear=0;
        q->data[q->front]=v;
    }
    else{
        q->rear = (q->rear+1)%n;
        q->data[q->rear] = v;
    }
}

void delete(queues *q,int *k){
    if(q->front==-1){
        printf("Empty List");
    }
    else if(q->front==q->rear){
        *k = q->data[q->front];
        q->front = q->rear = -1;
    }
    else{
        *k = q->data[q->front];
        q->front = (q->front+1)%n;
    }
}

void display(queues q) {
  int i;
  if (q.front == -1){
    printf(" \n Empty Queue\n");
    return;
  }
    printf("\n Items -> ");
    for (i = q.front; i != q.rear; i = (i + 1) % n) {
      printf("%d ", q.data[i]);
    }
    printf("%d \n", q.data[i]);
}

void peek(queues q){
    printf("First data is -> %d",q.data[q.front]);
}
int isempty(queues q){
    if(q.front==-1) return 1;
    return 0;
}
int isfull(queues q){
    if(q.front==(q.rear+1)%n) return 1;
    return 0;
}

void main(){
    printf("Enter the size of the queue:- ");
    scanf("%d",&n);
    queues q1;
    q1.front=q1.rear=-1;
    q1.data = malloc(n*sizeof(int));
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
            display(q1);
        }
        else if(choice == 4){
            peek(q1);
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