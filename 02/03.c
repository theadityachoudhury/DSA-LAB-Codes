#include <stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    printf("Enter the number of elements:-");
    scanf("%d", &n);
    int *arr = (int*)calloc(n,sizeof(int));
    printf("Enter all the elements spearated by space:- ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Element | NGE\n");
    int nge, i, j;
    for (i = 0; i < n; i++)
    {
        nge = -1;
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                nge = arr[j];
                break;
            }
        }
        printf("%d\t -- %d \n", arr[i], nge);
    }
}