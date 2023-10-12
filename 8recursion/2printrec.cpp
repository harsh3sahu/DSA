#include<iostream>
using namespace std;

void prin(int x){
    
    if(x==0)
        return;
    
    cout<<x;

    prin(x-1);
    

}

int main(){


    int a;
    cout<<"enter a number\n";
    cin>>a;


    prin(a);



    return 0;
}