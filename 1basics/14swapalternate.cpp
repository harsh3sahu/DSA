#include<iostream>
using namespace std;

void swapAlter(int arr[],int size){
    int x=0;
    while(x<size-1){
        swap(arr[x],arr[x+1]);
        x=x+2;
    }

    // return arr;
}

int main(){

    int a[10]={1,2,3,4,5,6,7,8,9,10};
    // cout<<a<<endl;
    int s=sizeof(a)/sizeof(int);
    // int ans[]=swapAlter(a,s);
    swapAlter(a,s);
    int i=0;
    while(i<s){
    cout<<a[i];
    i++;
    }


    return 0;
}