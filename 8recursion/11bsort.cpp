#include<iostream>
using namespace std;

void bSort(int arr[], int size){

    if(size==0 || size==1){
        return ;
    }
    for(int i=0;i<size-1;i++){
    if(arr[i]>arr[i+1]){
        swap(arr[i],arr[i+1]);
    }
    }
    
    

    
    bSort(arr, size-1);
        
      
}

int main(){

    int arr[10]={12,100,32,11,34,54,23,4,67,2};

    int size=sizeof(arr)/sizeof(int);

    bSort(arr, size);

    for(int i=0;i<size;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}