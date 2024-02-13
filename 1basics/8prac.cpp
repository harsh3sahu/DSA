#include<iostream>

using namespace std;

int main(){

    int n;
    cout<<"enter number\n";
    cin>>n;

    int bin=0;
    int mask=0;
    int x=n;
    while(x!=0){
        int digit= x&1;
        x=x>>1;
        mask= 1| (mask<<1);


    }

    int revbin=~n;
    int ans

    for(int i=0;i<32;i++){
        if(revbin &1){

        }


    }





    return 0;
}