#include <stdio.h>
#include <math.h>

float comp_dist(float x1,float y1, float x2, float y2){
    return pow(pow(x2-x1,2)+pow(y2-y1,2),0.5);
}

float comp_area(float x1,float y1, float x2, float y2,float x3, float y3){
    return 0.5*( ( (x1*y2) + (x2*y3) + (x3*y1) ) - ( (x2*y1) + (x3*y2) + (x1*y3) ) );
}


int main(){
    int choice;
    printf("Enter\n 1 to Compute distance b/w 2 points \n 2 to compute area of a triangle\n 3 to exit\n Enter your choice:- ");
    scanf("%d",&choice);
    if (choice==1){
        float x1,y1,x2,y2;
        printf("Enter x1 y1 x2 y2:- ");
        scanf("%f %f %f %f",&x1,&y1,&x2,&y2);
        float k = comp_dist(x1,y1,x2,y2);
        printf("The distance between the 2 points is %.2f",k);
    }
    else if (choice==2){
        float x1,y1,x2,y2,x3,y3;
        printf("Enter x1 y1 x2 y2 x3 y3:- ");
        scanf("%f %f %f %f",&x1,&y1,&x2,&y2,&x3,&y3);
        float k = comp_area(x1,y1,x2,y2,x3,y3);
        printf("The area of the triangle is %.2f",k);
    }
}

//Code By Aditya Choudhury