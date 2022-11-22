#include<iostream>
using namespace std;

void call(int* x,int* y){
    cin>>*x;
    cin>>*y;
    cout<<*x<<*y;
}

int main(){
    int x,y;
    call(&x,&y);
}