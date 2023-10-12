#include<iostream>
using namespace std;


int bitCount(int x){
    int count=0;
    while(x){
        count= count+(x&1);
        x=x>>1;
    }


    return count;
}

int  main(){


    int a,b;
    cout<<"enter two numbers"<<endl;
    cin>>a>>b;
    int ansa=bitCount(a);
    int ansb=bitCount(b);
    cout<<ansa+ansb;




}