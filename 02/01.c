#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    printf("Enter the number of elements:-");
    scanf("%d",&n);
    int *arr = (int*)calloc(n,sizeof(int));
    printf("Enter all the elements spearated by space:- ");
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);

    int last = n-1;
    for (int j=0;j<n/2;j++){
        int temp = arr[j];
        arr[j] = arr[last];
        arr[last] = temp;
        last--;
    }

    printf("Reversed array is:- ");
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
}