#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next,*prev;
};
struct node* head=NULL,*tail = NULL;

int find_length(){
	int count = 0;
	struct node* ptr = head;
	while(ptr!=NULL){
		count++;
		ptr = ptr->next;
	}
	return count;
}

void reverse(int n){
	struct node* ptr=head;
	struct node* l = tail;
	int temp;
	for(int i=0;i<n/2;i++){
		temp = ptr->data;
		ptr->data = l->data;
		l->data = temp;
		ptr = ptr->next;
		l = l->prev;
	}
}

void display(){
	struct node* ptr = head;
	while(ptr!=NULL){
		printf("%d\t",ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}

void insert(int n){
	struct node* cur = malloc(sizeof(struct node));
	cur->data = n;
	cur->next = NULL;
	cur->prev = NULL;
	if(head==NULL) head = tail = cur;
	else{
		tail->next = cur;
		cur->prev = tail;
		tail = cur;
	}
}

int main(){
	insert(1);
	insert(2);
	insert(3);
	insert(4);
	insert(5);
	insert(6);
	display();
	int n = find_length();
	reverse(n);
	display();
}
