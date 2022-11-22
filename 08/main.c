#include<stdio.h>
int main(){
    int arr[5] = {54,4,1,52,199};
    for(int i = 0;i<5;i++){
        for(int j=i;j<5;j++){
            if(arr[i]>arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for(int i =0;i<5;i++){
        printf("%d\t",arr[i]);
    }
}