#include<iostream>
using namespace std;
bool sea(int arr[5][5],int row, int col, int target){

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(arr[i][j]==target){

                 cout<<"row = "<<i<<endl;
                cout<<"col = "<<j<<endl;

                
                return true;
               
            }
        }
    }


    return false;
}



int main(){


    int arr[5][5]={{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int row=sizeof(arr)/sizeof(int);
    int col=sizeof(arr[0][0])/sizeof(arr[0]);
    int n;
    cout<<"enter the number \n";
    cin>>n;
    bool ans=sea(arr,5,5,n);

    cout<<ans<<endl;

    return 0;
}