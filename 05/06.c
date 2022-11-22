#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
    int flag;
};
struct node* create_node(int n){
    struct node* head=(struct node*) malloc(sizeof(struct node));
    struct node* ptr=head;

    int i=1;
    while(i<=n){
        printf("Enter the data for node %d: ", i);
        scanf("%d", &ptr->data);

        ptr->next=(struct node*) malloc(sizeof(struct node));
        ptr=ptr->next;
        i++;
    }
    ptr->next=head;
    //take ptr->next=null for linear linked list
    return head;
}

int detectL(struct node* h)
{
    while (h != NULL) {
        if (h->flag == 1)
            return 1;

        h->flag = 1;

        h = h->next;
    }
    return 0;
}

int main(){
    int n=0;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct node* head=create_node(n);
    struct node* temp=head;
    /*while(head!=NULL){
        printf("The data is %d\n", head->data);
        head=head->next;
        if(temp==head){
            exit(0);
        }
    }*/

    int answer=detectL(head);
    printf("answer is %d\n", answer);
    return 0;
}