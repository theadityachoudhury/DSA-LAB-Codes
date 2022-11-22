#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    printf("Enter the number of elements:-");
    scanf("%d",&n);
    int *arr = (int*)calloc(n,sizeof(int));
    printf("Enter all the elements spearated by space:- ");
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    int search1,search2;
    printf("Enter starting ending elemnts:- ");
    scanf("%d %d",&search1,&search2);
    printf("Elements between %d and %d are ",search1,search2);
    for(int j=0;j<n;j++){
        if (arr[j]>=search1 && arr[j]<=search2) printf("%d,",arr[j]);
    }
}