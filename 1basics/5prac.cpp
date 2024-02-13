#include<iostream>

using namespace std;
 
int main(){


    int n;
    cout<<"enter a numner"<<endl;
    cin>>n;

    int ans=0;
    int i=0;

    while(n!=0){
        int temp=n&1;

        ans= (ans*10)+temp;
        i++;
        n=n>>1;

    }

    cout<<ans<<endl;




    return 0;
}