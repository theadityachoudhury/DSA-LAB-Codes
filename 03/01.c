#include<stdio.h>
#include<stdlib.h>

int palindrome(char *str,int n){
    int i=0,j = n-1;
    while(j>i){
        if (str[i++] != str[j--]) return 0;
    }
    return 1;
}

void main(){
    int n,x;
    printf("Enter the size of the word:- ");
    scanf("%d",&n);
    char* s = (char *)malloc(n*sizeof(char)+1);
    printf("Enter the word:- ");
    scanf("%s",s);
    x = palindrome(s,n);
    if (x) printf("Palindrome");
    else printf("Not palindrome");

}