#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool tri_diagonal(int** arr, int k){
    for(int i=0; i<k; i++){
        for(int j=0; j<k; j++){
            if (i == j && arr[i][j] != 0){
                if (arr[i][j+1]==0 && j<k){
                    return false;
                }
                if(arr[i][j-1]==0 && j>0){
                    return false;
                }
            }
        }
    }
return true;
}

bool upper_diagonal(int** arr, int n)
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (j>=i && arr[i][j]==0) return false;
        }
    }
    return true;
}

bool lower_diagonal(int** arr, int n)
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (i>=j && arr[i][j]==0) return false;
        }
    }
    return true;
}


int main(){ 
    int n=0;
    printf("Enter the size of array: ");
    scanf("%d",&n);

    int** arr= (int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++){
        *(arr+i) = (int*)malloc(n*sizeof(int));
    }

   printf("Enter the array elements: ");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }

    if(arr[0][n-1]==0 && lower_diagonal(arr,n)) printf("Lower Triangular!!");
    else if(arr[n-1][0]==0 && upper_diagonal(arr,n)) printf("Upper triangular!!");
    else if (arr[n-1][0]==0 && arr[0][n-1]==0 && tri_diagonal(arr,n)) printf("Tri-Diagonal!!");
    else printf("Not a triangular matrix!!");
    return 0;
}