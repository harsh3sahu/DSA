#include<iostream>
using namespace std;

int main(){


    int n;
    cout<<"enter the number\n";
    cin>>n;
    int number=n;
    int ans=0;
    int bit;
    while(n!=0){
        
        ans=(ans<<1)|1;
        n=n>>1;
    }
    cout<<ans<<endl;
    cout<<n;
    n=number;
    while(ans!=0){
        if(n&1){
            n
        }
    }











    return 0;
}