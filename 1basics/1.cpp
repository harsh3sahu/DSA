#include<iostream>
using namespace std;

int main(){
int a;
cout<<"enter a number"<<endl;
cin>>a;
int n =1;
int j=1;
while (n<=a){
    for(int j=1; j<=n; j++){
        cout<<"*";
        
    }
    cout<<endl;
    n++;
}


return 0;

}