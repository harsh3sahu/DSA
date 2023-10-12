#include<iostream>
using namespace std;

int main(){

    int a;
    cout<<"enter rows"<<endl;
    cin>>a;

    int row,col;
    row=col=0;

    while(row<=a){
        while (col<row){
            cout<<"*";
            col++;
        }
    cout<<endl;
    col=0;
    row++;
    }


    return 0;
}