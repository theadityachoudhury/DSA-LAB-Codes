#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct emp{
    char name[20];
    char gender[5];
    char designation[20];
    char department[20];
    float basic;
    float gross;
};


void display(struct emp *st,int n){
    int i;
    for(i=0;i<n;i++){
        printf("Details of employee %d\n",i+1);
        printf("Name:- %s \n",st[i].name);
        printf("Gender:- %s\n",st[i].gender);
        printf("Designation:- %s\n",st[i].designation);
        printf("Department:- %s\n",st[i].department);
        printf("Basic Salary:- %.2f\n",st[i].basic);
        printf("Gross Salary:- %.2f\n",st[i].gross);
        printf("\n");
    }
}


int main(){
    int n;
    printf("Enter the number of emoloyees:- ");
    scanf("%d",&n);
    struct emp* data = (struct emp*)malloc(n*sizeof(struct emp));

    for(int i=0;i<n;i++){
        printf("Details for employee %d!\n",i+1);
        printf("Enter the name:- ");
        scanf("%s",data[i].name);
        printf("Enter M or F:- ");
        scanf("%s",data[i].gender);
        printf("Enter the designation:- ");
        scanf("%s",data[i].designation);
        printf("Enter the department:- ");
        scanf("%s",data[i].department);
        printf("Enter the basic pay:- ");
        scanf("%f",&data[i].basic);
        data[i].gross = data[i].basic+(data[i].basic*0.25)+(data[i].basic*0.75);
    }
    display(data,n);



}