#include<iostream>
using namespace std;

int main(){

    int n=-23;
    n=~n;
    cout<<n<<endl;
    int bit;
    int ans=0;
    while(n!=0){
        
        bit=n&1;
        ans=(ans*10)+bit;

       n= n>>1;

    }
    // ans=ans&0;

    cout<<ans;





    return 0;
}