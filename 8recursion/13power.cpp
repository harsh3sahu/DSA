#include<iostream>
using namespace std;

int pow(int a, int x){

    if(x==1){
        return a;
    }
    if(x==0){
        return 1;

    }

    if(x%2==0){
        return pow(a,x/2)*pow(a,x/2);
    }

    else 
    return pow(a,x/2)*pow(a,x/2)*a;





}

int main(){


    int num;
    cout<<"enter the number\n";
    cin>>num;

    int power;
    cout<<"enter the power\n";
    cin>>power;

    int ans = pow(num, power);
    cout<<ans;

    return 0;
}