#include<stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("Enter the number of elements:-");
    scanf("%d",&n);
    int *arr = (int*)calloc(n,sizeof(int));
    printf("Enter all the elements spearated by space:- ");
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    int search;
    printf("Enter the element to search:- ");
    scanf("%d",&search);
    printf("%d is present in index:- ",search);
    for(int j=0;j<n;j++){
        if (arr[j]==search) printf("%d,",j);
    }
}

