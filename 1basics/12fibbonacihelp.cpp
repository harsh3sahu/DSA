#include<iostream>
using namespace std;

int fib(int x){
    int count=0;
    int ans;
    int prans=1;
    for(int i=0;i<x ;i++){
        
        ans=count+prans;
        prans=count;
        count=ans;
        
    }
    
    return ans;
}

int main(){

    int n;
    cout<<"enter the number \n";
    cin>>n;
    

    int ans=fib(n);

    cout<<ans;


    return 0;
}