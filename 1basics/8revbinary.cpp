#include<iostream>
using namespace std;

int main(){

   int n;
   cout<<"enter a number\n";
   cin>>n;
    int mask=0;
    int x=n;
    while(x!=0){
        mask=(mask<<1)|1;
        x=x>>1;
    }
    int t=~n;
    for(int i=0;i<32;i++){
        if(t&1){
            cout<<1<<" ";
        }
        else{
            cout<<0<<" ";
        }
        t=t>>1;
    }

    int ans=(~n)&mask;


    cout<<endl<<ans;

    return 0;
}