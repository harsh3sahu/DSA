#include<iostream>
using namespace std;

int stairs(int x){
    if(x<0){
        return 0;
    }
    if(x==0){
        return 1;
    }

    return stairs(x-1)+stairs(x-2);
}

int main(){

    int n;
    cout<<"enter number of stairs\n";
    cin>>n;

    int ans= stairs(n);
    cout<<ans;




    return 0;
}