#include <stdio.h>
#include <stdlib.h>
void even_odd(int* arr, int n){
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]%2==0){
            int temp=arr[count];
            arr[count]=arr[i];
            arr[i]=temp;
            count++;
        }

    }
}
int main(){

    int n=0;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int* arr=(int*) malloc(n * sizeof(int));
    printf("Enter the Elements of Array: ");
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    
   even_odd(arr, n);

    for(int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}