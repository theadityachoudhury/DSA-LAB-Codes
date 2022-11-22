#include<stdio.h>
#include<stdlib.h>
struct node{
	int cof;
	int exp;
	struct node *next;
};
void create(struct node **h){
int n;
printf("\nEnter no. of terms:");
scanf("%d",&n);
struct node *cur,*l;
	for(int i=0;i<n;i++){
	cur=malloc(sizeof(struct node));
	cur->next=NULL;
	scanf("%d %d",&cur->cof,&cur->exp);
	if(*h==NULL)
	l=*h=cur;
	else{
	l->next=cur;
	l=cur;
	}
    }
}
void display(struct node *h){
struct node *p=h;
	while(p->next!=NULL){
	printf("%d^%d+",p->cof,p->exp);
	p=p->next;
	}
printf("%dx^%d",p->cof,p->exp);
}
int main(){
struct node *head=NULL;
create(&head);
display(head);
return 0;
}