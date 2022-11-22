#include<stdio.h>
#include<stdlib.h>

struct node{
	int c;
	int p;
	struct node* next;
};

void crnode(struct node** head,int n){
	struct node* l;
	for(int i=0;i<n;i++){
		struct node* ptr = malloc(sizeof(struct node));
		printf("Enter power coefficient:- ");
		scanf("%d %d",&ptr->p,&ptr->c);
		ptr->next=NULL;
		if(*head==NULL){
			*head = ptr;
			l = ptr;
		}
		else{
			l->next = ptr;
			l = ptr;
		}
	}
}

void join(struct node** h1,struct node*h2){
	struct node* p = *h1;
	if (*h1==NULL){
		*h1 = h2;
		return;
	}
	while(p->next!=NULL) p = p->next;
	p->next = h2;
}

void display(struct node *h){
	struct node *p=h;
	while(p->next!=NULL){
		printf("%d^%d+",p->c,p->p);
		p=p->next;
	}
	printf("%dx^%d",p->c,p->p);
}

void multi(struct node** h,struct node* h1, struct node* h2){
	struct node* l;
	struct node* p = h1;
	struct node* q;
	struct node* r;
	while(p!=NULL){
		q = h2;
		while(q!=NULL){
			r= malloc(sizeof(struct node));
			r->c = p->c*q->c;
			r->p = p->p+q->p;
			r->next = NULL;
			if(*h == NULL){
				*h = r;
				l = r;
			}
			else{
				l->next = r;
				l = r;
			}
			q = q->next;
		}
		p = p->next;
	}
	
}

int main(){
	struct node* head1,*head2,*head3;
	head1=head2=head3=NULL;
	int n;
	printf("Enter the number of nodes to create in polynomial 1:- ");
	scanf("%d",&n);
	crnode(&head1,n);
	printf("Enter the number of nodes to create in polynomial 2:- ");
	scanf("%d",&n);
	crnode(&head2,n);
	multi(&head3,head1,head2);
	display(head3);
	return 0;
}