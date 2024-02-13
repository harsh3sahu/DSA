#include<iostream>
using namespace std;

void bSort(int arr[], int size){
    if(size==0 || size==1){
        return ;
    }

    for(int i=1;i<size;i++){
        if(arr[i-1]>arr[i]){
            swap(arr[i-1],arr[i]);
        }
    }

    return bSort(arr, size-1);

}

int main(){

    int arr[10]={12,100,32,11,34,54,23,4,67,2};

    int size=10;

    bSort(arr,size);

    for(auto i:arr){
        cout<<i<<"   ";
    }

    return 0;
}