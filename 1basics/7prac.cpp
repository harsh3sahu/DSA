#include<iostream>
using namespace std;

int main(){

    int n;
    cout<<"enter a number\n";
    cin>>n;

    int ans=0;

    while(n!=0){

        int digit=n%10;
        n=n/10;

        ans= (ans*10) + digit; 

        
    }

    cout<<ans;



    return 0;
}