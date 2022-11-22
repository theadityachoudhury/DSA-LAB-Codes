#include<stdio.h>
#include<stdlib.h>

void non_zero(int n,int **p){
    int count = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if (p[i][j]==0) count++;
        }
    }
    printf("Number of non-zero elements is %d\n",count);
}

void sum_udiag(int n,int **p){
    int sum = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if (j>i) sum+=*(*(p+i)+j);
        }
    }
    printf("Sum of the elements above major diagonal is %d\n",sum);
}


void swap_major_minor(int n,int** arr){
    int j,temp;
    for(int i=0;i<n;i++){
        j = i;
        temp = *(*(arr+i)+j);
        *(*(arr+i)+j) = *(*(arr+i)+(n-j-1));
        *(*(arr+i)+(n-j-1)) = temp;
    }
}

void print_mat(int n,int** arr){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
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
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }

    printf("The matrix entered by the user is:- \n");
    // for(i=0;i<n;i++){
    //     for(j=0;j<n;j++){
    //         printf("%d ",arr[i][j]);
    //     }
    //     printf("\n");
    print_mat(n,arr);


    // }    
    printf("\n");
    non_zero(n,arr);
    sum_udiag(n,arr);
    swap_major_minor(n,arr);
    printf("The matrix after the major diagonal matrix and minor diagonal matrix is swapped:- \n");
    print_mat(n,arr);   
}


// Code by Aditya Choudhury