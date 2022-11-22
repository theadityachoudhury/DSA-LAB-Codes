#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
}*head=NULL,*tail=NULL;

int crnode(int n){
    struct node* c;
    for (int i = 0; i < n; i++)
    {
        c = (struct node*)malloc(sizeof(struct node));
        printf("Enter the value of element %d:- ",i);
        scanf("%d",&c->data);
        c->next = NULL;
        if (head == NULL){
            head = tail = c;
        }
        else{
            tail->next = c;
            tail = c;
        }
    }
    
}

void display(){
    struct node* c;
    c = head;
    if(head==NULL) {
        printf("List is empty!!\n");
        return;
    }
    while(c!=NULL){
        printf("%d\t",c->data);
        c = c->next;
    }
}


void insert(int v,int p){
    struct node *c,*ptr;
    c = (struct node*)malloc(sizeof(struct node));
    c->data = v;
    c->next = NULL;
    if(head==NULL){
        head = tail = c;
    }
    else if(p==0){
        c->next = head;
        head = c;
    }
    else{
        ptr = head;
        for (int i = 0; i < p-1 && ptr->next!= NULL; i++)
        {
            ptr = ptr->next;
        }
        if (ptr->next==NULL){
            tail->next = c;
            tail = c;
        }
        else{
            c->next = ptr->next;
            ptr->next = c;
        }
        
    }
}

int countt(struct node* head){
    struct node* c;
    int gg=0;
    c = head;
    while(c!=NULL){
        gg++;
        c = c->next;
    }
    return gg;
}


int search(struct node* head,int e){
    struct node* c;
    int gg=0;
    c = head;
    while(c!=NULL){
        if (c->data == e) return gg;
        gg++;
        c = c->next;
    }
    return -1;
}

int delete(struct node **h,int pos,int *k){
    int i;
	struct node *prv,*p;
	if(*h==NULL){
		return 1;
	}else{
		for(i=1,p=*h;i<pos && p!=NULL;i++){
			prv=p;
			p=p->next;
		}
		if(p==NULL){
			return 1;
		}else{
			*k=p->data; 
			if(p==*h)
				*h=p->next;
			else
				prv->next=p->next;
			free(p);
			return 0;	
		}
	}
}

void reverse(struct node**h){
    struct node* prev=NULL, *curr=*h, *next=NULL;
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *h = prev;
}


void main(){
    int choice,condition=1,n=0,v,p=0,count=0,e,gg,k;
    while (condition)
    {
        printf("\n\n\nEnter\n 1 to create a list \n 2 to display the content of the list \n 3 to Insert a node at the beginning of the list \n 4 to Insert a node at the end of the list \n 5 to Insert a node after kth node into the list \n 6 to count the total number of nodes \n 7 to search an element \n 8 to remove an element from the beginning \n 9 to remove an element from the end \n 10 to remove an element from kth position \n 11 to reverse the linked list \n 20 to quit the program \n Enter your choice:- ");
        scanf("%d",&choice);
        if (choice==1){
            printf("\n\nEnter the number of nodes:- ");
            scanf("%d",&n);
            count+=n;
            crnode(n);
        }
        else if(choice == 2){
            printf("\n");
            display();
        }
        else if(choice == 3){
            printf("\n\nEnter the value to be inserted:- ");
            scanf("%d",&v);
            insert(v,0);
            printf("The list after adding %d in position 0 is:-",v);
            display();
            count++;
        }
        else if(choice == 4){
            printf("\n\nEnter the value to be inserted:- ");
            scanf("%d",&v);
            insert(v,count++);
            printf("The list after adding %d in the end is:-",v);
            display();
        }
        else if(choice == 5){
            printf("\n\nEnter the value to be inserted:- ");
            scanf("%d",&v);
            printf("Enter the position:- ");
            scanf("%d",&p);
            insert(v,p);
            count++;
            printf("The list after adding %d in the end is:-",v);
            display();
        }
        else if(choice == 6){
            gg = countt(head);
            printf("There are %d number of nodes in total!!\n",gg);
        }
        else if(choice == 7){
            printf("Enter the value to search:- ");
            scanf("%d",&e);
            gg = search(head,e);
            if (gg<0) printf("Element not found!!");
            else printf("The elemend %d is present in %d",e,gg);
        }
        else if(choice == 8){
            delete(&head,0,&k);
            count--;
        }
        else if(choice == 9){
            delete(&head,count,&k);
            count--;
        }
        else if(choice == 10){
            printf("Enter the position of the element:- ");
            scanf("%d",&p);
            delete(&head,p,&k);
            count--;
        }
        else if(choice==11) reverse(&head);
        else if(choice == 20) condition = 0;
        else printf("Please enter correct choice!!");
    }
}