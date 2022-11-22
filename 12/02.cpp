#include<stdio.h>


int main(){
	n = 5;
	int arr[n] = {10,20,30,40,50};
	for(int i=1;i<n;i++){
		arr[i] = arr[i]+(arr[i]-arr[i-1]);
	}

	for(int i=0;i<n;i++) printf("%d\t",arr[i]);
}

