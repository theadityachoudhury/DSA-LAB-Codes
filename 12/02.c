#include<stdio.h>


int main(){
	int arr[5] = {10,20,30,40,50};
	for(int i=0;i<5;i++) printf("%d\t",arr[i]);
	printf("\n");
	for(int i=0;i<5;i++){
		arr[i] = arr[i]+(i*10);
	}

	for(int i=0;i<5;i++) printf("%d\t",arr[i]);
	printf("\n");
}
