#include<iostream>
using namespace std;

void bSort(int arr[], int s){
    for(int j=1;j<s;j++){
    for(int i=0; i<s-j;i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    }
}



int main(){


    int arr[10]={24,43,12,56,1,64,23,10,87,5};
    
    int size=sizeof(arr)/sizeof(int);
    bSort(arr,size);

    for(int i=0;i<size;i++){
        cout<<arr[i]<<endl;
    }



    return 0;
}