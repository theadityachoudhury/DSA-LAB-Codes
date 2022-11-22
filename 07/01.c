#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head = NULL, *tail = NULL, *h = NULL, *t = NULL;

void create(int n)
{
	struct node *cur;
	for (int i = 0; i < n; i++)
	{
		cur = malloc(sizeof(struct node));
		cur->next = NULL;
		scanf("%d", &cur->data);
		if (head == NULL)
			head = tail = cur;
		else
		{
			tail->next = cur;
			tail = cur;
		}
	}
}
void display()
{
	struct node *cur;
	cur = head;
	while (cur != NULL)
	{
		printf("%d\t", cur->data);
		cur = cur->next;
	}
}
void insert(int n, int pos)
{
	struct node *ptr, *cur;
	cur = malloc(sizeof(struct node));
	cur->data = n;
	cur->next = NULL;
	if (h == NULL)
		h = t = cur;
	else if (pos == 0)
	{
		cur->next = h;
		h = cur;
	}
	else
	{
		ptr = h;
		for (int i = 0; i < pos - 1 && ptr->next != NULL; i++)
			ptr = ptr->next;
		if (ptr->next == NULL)
		{
			t->next = cur;
			t = cur;
		}
		else
		{
			cur->next = ptr->next;
			ptr->next = cur;
		}
	}
}
void sort(int n)
{
	struct node *cur = head, *nex;
	insert(cur->next->data, 0);
	cur = cur->next->next;
	if (n % 2 != 0)
	{
		while (cur->next != NULL)
		{
			int k = 1;
			nex = h->next;
			if (cur->next->data < h->data)
				insert(cur->next->data, 0);
			else
			{
				while (nex->data < cur->next->data)
				{
					k++;
					nex = nex->next;
				}
				insert(cur->next->data, k);
			}
			cur = cur->next->next;
		}
		struct node *p = head, *q = h;
		while (p->next != NULL)
		{
			p->next->data = q->data;
			p = p->next->next;
			q = q->next;
		}
	}
	else
	{
		while (cur != NULL)
		{
			int k = 1;
			nex = h;
			if (cur->next->data < h->data)
				insert(cur->next->data, 0);
			else
			{
				while (nex->data < cur->next->data && nex->next != NULL)
				{
					k++;
					nex = nex->next;
				}
				insert(cur->next->data, k);
			}
			cur = cur->next->next;
		}
		struct node *p = head, *q = h;
		while (p != NULL)
		{
			p->next->data = q->data;
			p = p->next->next;
			q = q->next;
		}
	}
	display();
}
int main()
{
	int n, x, y, ch;

	printf("Enter no of elements:");
	scanf("%d", &n);
	create(n);
	printf("\noriginal list:\n");
	display();
	printf("\nEven places sorted list:\n");
	sort(n);
	return 0;
}
