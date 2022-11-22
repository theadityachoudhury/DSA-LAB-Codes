#include<stdio.h>
#include<stdlib.h>

struct data{
    char name[20];
    int roll;
    int marks_cs;
    char add[20];
};

int main(){
    int n;
    printf("n:- ");
    scanf("%d",&n);

    struct data* info = (struct data*)malloc(n*sizeof(struct data));

    for(int i=0; i<n;i++){
        printf("Enter details of student %d\n",i+1);
        printf("Enter your name:- ");
        scanf("%s",info[i].name);

        printf("Roll number:- ");
        scanf("%d",&info[i].roll);

        printf("Enter marks in CS:- ");
        scanf("%d",&info[i].marks_cs);

        printf("Enter address:- ");
        scanf("%s",info[i].add);
    }

    for(int i=0; i<n;i++){
        printf("Details of student Entered %d\n",i+1);
        printf("Name :- %s \n ",info[i].name);

        printf("Roll number:- %d\n",info[i].roll);

        printf("marks:- %d\n",info[i].marks_cs);

        printf("address:- %s\n",info[i].add);
    }

    

}

//Code by Aditya Choudhury