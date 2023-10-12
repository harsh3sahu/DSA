#include<iostream>
using namespace std;    

int sumArray(int arr[],int size){

    int x=0;
    int sum=0;
    while(x<size){
        sum=sum+arr[x];
        x++;
    }

    return sum;

}

int main(){

    int a[10]={4,3,523,54,65,50,76,12,34,66};
    int s=sizeof(a)/sizeof(int);
    int ans=sumArray(a,s);

    cout<<ans;




    return 0;
}