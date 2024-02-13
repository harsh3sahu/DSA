#include<iostream>
using namespace std;

void bSort(int arr[], int size){

    for(int i=1;i<size;i++){
        for(int j=0; j<size-i ;j++){
            if(arr[j+1]<arr[j]){
                swap(arr[j+1],arr[j]);
            }
        }
    }


}


int main(){

    int arr[10]={24,43,12,56,1,64,23,10,87,5};
    int size=sizeof(arr)/sizeof(int);

    bSort(arr,size);

    for(auto i:arr){
        cout<<i<<"  ";
    }

    return 0;
}