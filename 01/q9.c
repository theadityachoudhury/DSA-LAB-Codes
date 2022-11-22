#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void check_submatrix(int** arr, int n, int k){
    
}
int main(){

    int n=0;
    printf("Enter the size of matrix: ");
    scanf("%d", &n);

    int** arr=(int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++){
        arr[i]=(int*)malloc(n*sizeof(int));
    }

    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j]=count++;
        }
    }

    int k=0;
    printf("Enter the required number: ");
    scanf("%d", &k);

    check_submatrix(arr, n, k);
    return 0;

}