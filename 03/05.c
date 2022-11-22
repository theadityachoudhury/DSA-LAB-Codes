#include<stdio.h>

int hcf(int n1, int n2){
    if (n2!=0) return hcf(n2,n1%n2);
    else return n1;
}

void main(){
    int n1,n2,r;
    printf("Enter two numbers:- ");
    scanf("%d %d",&n1,&n2);
    r = hcf(n1,n2);
    printf("%d",4%2);
    printf("GCD of %d and %d is %d!!\n",n1,n2,r);
}