#include<stdio.h>
#define max 6

typedef struct{
    int data[max];
    int top;
}stack;

void push(stack *s,int v){
    if(s->top==max-1){
        printf("Overflow\n");
        return;
    }
    else{
        s->top++;
        s->data[s->top] = v;
    }
}
void display(stack s){
    for(int i=0;i<=s.top;i++){
        printf("%d\t",s.data[i]);
    }
    printf("\n");
}



int main(){
    stack s1,s2;
    s1.top = s2.top = -1;
    push(&s1,1);
    push(&s1,2);
    push(&s1,3);
    push(&s1,4);
    push(&s1,5);
    display(s1);
    s2 = s1;
    display(s2);
}
