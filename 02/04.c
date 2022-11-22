#include<stdio.h>

struct kmm{
    float km;
    float m;
};

void convert(struct kmm* b){
    printf("The total distance in km is %.2f\n",b->km+(b->m/1000));
    printf("The total distance in meter is %.2f\n",b->m+(1000*b->km));
}

int main(){
    struct kmm a;
    printf("Enter the distance in km:- ");
    scanf("%f",&a.km);
    printf("Enter the distance in m:- ");
    scanf("%f",&a.m);
    convert(&a);
}