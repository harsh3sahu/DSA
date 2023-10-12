#include<iostream>
using namespace std;

void rot(int arr[][3], int row, int col){
    int i=0,j=0;

    for(;i<row;i++){
        for(;j<col;j++){
            swap(arr[i][j],arr[j][i]);
        }
    }
}
int main(){

    int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<arr[i][j]<<"  ";
        }
        cout<<endl;

    }
    rot(arr,3,3);

for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<arr[i][j]<<"  ";
        }
        cout<<endl;

    }


    return 0;
}