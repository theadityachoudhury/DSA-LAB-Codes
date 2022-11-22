#include<stdio.h>
#include<stdlib.h>

int sum(int* arr1,int* arr2,int* arr3,int z, int q){
    int last = z,c=0;
    for (int i = 0; i < z; i=i+2)
    {
        arr3[i] = arr1[i];
        arr3[i+1] = arr1[i+1];
    }

    for (int i = 0; i < q; i=i+2)
    {
        c=0;
        for (int j = 0; j < z; j=j+2)
        {
            if(arr2[i]==arr3[j]){
                arr3[j+1] = arr3[j+1]+arr2[i+1];
                c=1;
                break;
            }
        }
        if(c==0){
            arr3 = realloc(arr3,z+(2*sizeof(int)));
            arr3[last++] = arr2[i];
            arr3[last++] = arr2[i+1];
        }
        
    }
    return last;
}


void main(){
    int m,n,i;

    printf("Enter the number of terms of 1st polynomial:- ");
    scanf("%d",&m);
    int z = m*2;
    int* arr1 = (int*)malloc(z*sizeof(int));
    printf("Enter power coefficient:- ");
    for (i = 0; i < z; i++)
    {
        scanf("%d",arr1+i);
    }

    printf("Enter the number of terms of 2nd polynomial:- ");
    scanf("%d",&n);
    int q = n*2;
    int* arr2 = (int*)malloc(q*sizeof(int));
    printf("Enter power coefficient:- ");
    for (i = 0; i < q; i++)
    {
        scanf("%d",arr2+i);
    }

    int h = (z+q)*sizeof(int);
    int* arr3 = (int*)malloc(z*sizeof(int));
    int last=sum(arr1,arr2,arr3,z,q);

    for (int i = 0; i < last; i=i+2)
    {
        if (i==last-2) printf("%dx^%d",arr3[i+1],arr3[i]);
        else printf("%dx^%d + ",arr3[i+1],arr3[i]);
    }
    
}