#include<stdio.h>

void percent(int n,int i){
    if (i<=50){
        float x = n*i*0.01;
        printf("%d %.2f\n",i,x);
        percent(n,++i);
    }
}

void main(){
    int n;
    printf("Enter a number:- ");
    scanf("%d",&n);
    percent(n,1);
}