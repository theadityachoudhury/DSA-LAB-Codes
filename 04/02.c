#include<stdio.h>
#include<stdlib.h>


void main(){
    int m,n,count=0;
    printf("Enter rows columns:- ");
    scanf("%d %d",&m,&n);
    int** arr = (int**)malloc(m*sizeof(int*));
    for(int i=0;i<m;i++){
        *(arr+i) = (int*)malloc(n*sizeof(int));
    }

    printf("Enter the elements:- ");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d",(*(arr+i)+j));
            if (*(*(arr+i)+j) == 0) count++;
        }
    }
    if (count>(m*n)/2) printf("It is a sparse matrix!!\n");
    else printf("It is not a sparse matrix!!\n");
    
}