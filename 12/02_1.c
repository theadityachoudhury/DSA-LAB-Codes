#include<stdio.h>


int main(){
	int arr[5] = {10,20,30,40,50};
	for(int i=0;i<5;i++) printf("%d\t",arr[i]);

	arr[1] = arr[1]+arr[0];
	for(int i=2;i<5;i++){
		arr[i] = arr[i] + (arr[i-1]-arr[i-2]);
	}

	for(int i=0;i<5;i++) printf("%d\t",arr[i]);
	printf("\n");
}
