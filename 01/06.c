#include<stdio.h>

void non_zero(int n,int (*p)[n]){
    int count = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if (p[i][j]==0) count++;
        }
    }
    printf("Number of non-zero elements is %d\n",count);
}

void sum_diag(int n,int (*p)[n]){
    int sum = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if (j>i) sum+=p[i][j];
        }
    }
    printf("Sum of upper diagonal elements is %d\n",sum);
}


void eb_mindiag(int n,int (*p)[n]){
    printf("The elements below the minor diagonal are:- ");
    for(int i=1;i<n;i++){
        for(int j=n-1;j>0;j--){
            if (i+j>=n)
            printf("%d,",p[i][j]);
        }
    }
}


void prod_diage(int n,int (*p)[n]){
    int prod=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if (i=j)
            prod *= p[i][j]; 
        }
    }
    printf("\nThe product of the diagonal elements is %d\n",prod);
}


int main(){
    int n,i,j;
    printf("Enter n of nxn square matrix:- ");
    scanf("%d",&n);
    // int arr[n][n];
     int **arr = (int**)calloc(n,sizeof(int*));
     for(i=0;i<n;i++){
        *(arr+i) = (int*)calloc(n,sizeof(int));
     }
    
    
    
    for(int i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }

    printf("The matrix entered by the user is:- \n");
    for(int i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }    
    printf("\n");
    non_zero(n,arr);
    sum_diag(n,arr);
    eb_mindiag(n,arr);
    prod_diage(n,arr);
}