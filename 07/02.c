#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

typedef struct{
    struct node* top;
}stack;

int create(stack* s,int n){
    struct node* curr;
    printf("Enter the value:- ");
    for(int i = 0; i<n;i++){
        curr = malloc(sizeof(struct node));
        scanf("%d",&curr->data);
        if(s->top == NULL){
            s->top = curr;
            curr->next = NULL;
        }
        else{
            curr->next = s->top;
            s->top = curr;
        }
    }
}

int pop(stack* s,int* k){
    if(s->top==NULL){
        printf("Underflow!!\n");
        return 1;
    }
    else if(s->top->next == NULL){
        *k = s->top->data;
        free(s->top);
        s->top = NULL;
    }
    else{
        struct node* p = s->top;
        *k = s->top->data;
        s->top = s->top->next;
        free(p);
    }
}

void display_top(stack s){
    if(s.top==NULL){
        printf("Empty!!\n");
        return;
    }
    printf("%d\n",s.top->data);
    printf("\n");
}

void display(stack s){
    struct node* p = s.top;
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

void main(){
    stack s;
    s.top = NULL;
    int k,n,condition=1,z;
    printf("1. For creating the stack \n2. For Displaying the stack \n3. For Inserting a value \n4. Display Top Element of the stack \n5. Pop the value from the stack \n6. To Quit \n");
    while(condition){
        printf("Enter your choice:- ");
        scanf("%d",&n);
        if(n==1){
            printf("Enter the number of elements in the stack:- ");
            scanf("%d",&z);
            create(&s,z);
        }
        else if(n==2){
            display(s);
        }
        else if(n==3){
            create(&s,1);//for insertion
        }
        else if(n==4){
            display_top(s);
        }
        else if(n==5){
        pop(&s,&k);
        printf("%d\n",k);
        }
        else if(n==6) condition=0;
        else{
            printf("Please enter correct choice!!\n");
        }
    }
}