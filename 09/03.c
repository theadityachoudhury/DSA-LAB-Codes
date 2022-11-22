//  #include<stdio.h>
//  typedef struct{
//     int dd,mm,yyyy;
//  }date;

// void swap(date* arr,int j){
//     date t = arr[j];
//     arr[j]=arr[j+1];
//     arr[j+1]=t;
// }
// int main(){
//     int n,t;
//     printf("Enter the length of the array:- ");
//     scanf("%d",&n);
//     date arr[n];
//     for (int inp = 0; inp < n; inp++)
//     {
//         printf("Enter dd mm yyyy:- ");
//         scanf("%d %d %d",&arr[inp].dd,&arr[inp].mm,&arr[inp].yyyy);
//     }
    
//     for (int i = 0; i < (n-1); i++)
//     {
//         for (int j = 0; j < n-1; j++)
//         {
//             if (arr[j].yyyy>arr[j+1].yyyy){
//                 if (arr[j].mm>arr[j+1].mm){
//                     if (arr[j].mm>arr[j+1].mm) swap(arr,j);
//                 }
//                 else swap(arr,j);
//             }
//             else{
//                 if (arr[j].mm>arr[j+1].mm){
//                     if (arr[j].mm>arr[j+1].mm) swap(arr,j);
//                 }
//             }
            
//         }
        
//     }

//     for (int h = 0; h < n; h++)
//     {
//         printf("%d %d %d \t",arr[h].dd,arr[h].mm,arr[h].yyyy);
//     }
    
// }


#include<stdio.h>
 typedef struct{
    int dd,mm,yyyy;
 }date;

void swap(date* arr,int j){
    date t = arr[j];
    arr[j]=arr[j+1];
    arr[j+1]=t;
}
int main(){
    int n,t;
    printf("Enter the length of the array:- ");
    scanf("%d",&n);
    date arr[n];
    for (int inp = 0; inp < n; inp++)
    {
        printf("Enter dd mm yyyy:- ");
        scanf("%d %d %d",&arr[inp].dd,&arr[inp].mm,&arr[inp].yyyy);
    }
    
    for (int i = 0; i < (n-1); i++)
    {
        for (int j = 0; j < (n-1); j++)
        {
            if(arr[j].yyyy>arr[j+1].yyyy) swap(arr,j);
            else if (arr[j].yyyy==arr[j+1].yyyy){
                if (arr[j].mm>arr[j+1].mm) swap(arr,j);
                else if(arr[j].mm==arr[j+1].mm){
                    if (arr[j].dd>arr[j+1].dd) swap(arr,j);
                }else continue;
            }
            else continue; 
        }
        
    }

    for (int h = 0; h < n; h++)
    {
        printf("%d %d %d \t",arr[h].dd,arr[h].mm,arr[h].yyyy);
        }
}