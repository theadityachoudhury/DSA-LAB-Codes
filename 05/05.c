#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

void create(struct node **h, int no)
{
    int i;
    struct node *cur, *l;
    for (i = 0; i < no; i++)
    {
        cur = malloc(sizeof(struct node));
        scanf("%d", &cur->data);
        cur->next = NULL;
        cur->prev = NULL;
        if (*h == NULL)
        {
            *h = l = cur;
        }
        else
        {
            l->next = cur;
            cur->prev = l;
            l = cur;
        }
    }
}
int insert(struct node **h, int v, int pos)
{
    int i;
    struct node *cur, *p;
    cur = malloc(sizeof(struct node));
    if (cur == NULL)
        return 1;
    cur->data = v;
    cur->prev = NULL;
    cur->next = NULL;
    if (*h == NULL)
    {
        *h = cur;
    }
    else if (pos == 0)
    {
        cur->next = *h;
        (*h)->prev = cur;
        *h = cur;
    }
    else
    {
        for (i = 1, p = *h; i < pos && p->next != NULL; p = p->next, i++);
        cur->next = p->next;
        cur->prev = p;
        p->next = cur;
    }
    return 0;
}
int del(struct node **h, int pos, int *k)
{
    int i;
    struct node *prv, *p;
    if (*h == NULL)
    {
        return 1;
    }
    else
    {
        for (i = 1, p = *h; i < pos && p != NULL; i++)
        {
            // prv=p;
            p = p->next;
        }
        if (p == NULL)
        {
            return 1;
        }
        else
        {
            *k = p->data;
            if (p == *h)
            {
                *h = p->next;
                (*h)->prev = NULL;
            }
            else
                p->prev->next = p->next;
            free(p);
            return 0;
        }
    }
}

void display(struct node *h)
{
    struct node *cur = h;
    while (cur != NULL)
    {
        printf("%d\t", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

void display_rev(struct node *h)
{
    struct node *cur = h;
    while (cur != NULL)
    {
        printf("%d\t", cur->data);
        cur = cur->prev;
    }
    printf("\n");
}

int del_p(struct node **h, int v, int *k){
    struct node* p = *h;
    if (*h==NULL) return 1;
    else{
        while(p->data!=v && p!=NULL){
            p = p->next;
        }
        if (p==NULL) return 1;
        else{
            if(p==*h){
                p->next->prev = p->prev;
                *h = p->next;
            }
            else{
                p->prev->next = p->next;
                p->next->prev = p->prev;
            }
            free(p);
        }
    }

}

int main()
{
    int k;
    struct node *head = NULL;
    create(&head, 5);
    insert(&head, 69, 3);
    display(head);
    del(&head, 3, &k);
    del(&head,0,&k);
    del(&head,666,&k);
    display(head);
    del_p(&head,2,&k);
    display(head);
    return 0;
}
