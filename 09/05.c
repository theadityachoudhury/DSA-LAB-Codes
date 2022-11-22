#include<stdio.h>
int main(){
    int arr[50],n,t;
    printf("Enter the length of the array:- ");
    scanf("%d",&n);
    printf("Enter the elements of the array:- ");
    for (int inp = 0; inp < n; inp++)
        scanf("%d",&arr[inp]);
    
    for (int i = 0; i < (n); i++)
    {
        int value = arr[i];
        int j = i-1;
        while (j>=0 && value>arr[j])
        {
            arr[j+1] = arr[j];
            j-=1;
        }
        arr[j+1] = value;   
    }

    for (int h = 0; h < n; h++)
    {
        printf("%d ",arr[h]);
    }
    
}