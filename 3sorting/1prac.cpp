#include<iostream>
using namespace std;

void sSort(int arr[], int size){

    for(int i=0; i<size;i++){
        int min=i;

        for(int j=i;j<size;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        swap(arr[min],arr[i]);



    }



}

int main(){

    int arr[10]={24,43,12,56,1,64,23,10,87,5};
    int size= sizeof(arr)/sizeof(int);

    sSort(arr,size);

    for(auto i: arr){
        cout<<i<<"  ";
    }



    return 0;
}