#include <stdio.h>
#include <stdlib.h>


int main(){
    int n,sum,minimum=0,maximum=0;
    printf("Enter the number of elements:-");
    scanf("%d",&n);
    int *arr = (int*)calloc(n,sizeof(int));
    printf("Enter all the elements spearated by space:- ");
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    maximum = arr[0];
    minimum = arr[0];
    for(int j=0;j<n;j++){
        sum+=arr[j];
        if (arr[j]<minimum) minimum = arr[j];
        else if (arr[j]>maximum) maximum = arr[j]; 
    }
    printf("Minimum = %d \n Maximum = %d \n Sum = %d \n Average = %d \n",minimum,maximum,sum,sum/n);


}