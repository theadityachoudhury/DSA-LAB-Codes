#include<stdio.h>
#include<stdlib.h>

void transpose(int** arr,int** arr2,int n){
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) arr2[j][i] = arr[i][j];
}

void print(int** arr,int n){
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(arr[i][j]!=0){
                printf("%d\t%d\t%d\n",i,j,arr[i][j]);
            }   
        }
    }
    
}

void main(){
    int n,row,column,value;
    printf("Enter the number of rows:- ");
    scanf("%d",&n);
    int** arr = (int**)malloc(n*sizeof(int*));
    int** arr2 = (int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++){
        *(arr+i) =(int*)calloc(n,sizeof(int));
        *(arr2+i) =(int*)calloc(n,sizeof(int));
    }
    int n1;
    printf("Enter the number of non-zero elements:- ");
    scanf("%d",&n1);
    printf("Enter rows columns values:-");
    for(int i=0;i<n1;i++){
        scanf("%d %d %d",&row,&column,&value);
        arr[row][column] = value;
    }
    printf("The matrix entered by the user is:- \n");
    print(arr,n);
    transpose(arr,arr2,n);
    printf("The matrix after the transpose is:- \n");
    print(arr2,n);
}