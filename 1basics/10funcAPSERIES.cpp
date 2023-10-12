#include<iostream>
using namespace std;

int apSeries(int x){

 return 3*x+7;

}   

int main(){


    int n;
    cout<<"enter a number"<<endl;
    cin>>n;

    int ans= apSeries(n);
    cout<<ans<<endl;



    return 0;
}