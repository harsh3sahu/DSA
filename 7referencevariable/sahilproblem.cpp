#include<iostream>
using namespace std;

int main(){

    int x;
    cout<<"enter the length of array\n";
    cin>>x;

    int *arr=new int[x];
    cout<<"enter elements"<<endl;
    for(int i=0;i<x;i++){
        cin>>arr[i];
    }
    int p;
    cin>>p;
    // int arr2[p];
    int *arr1=new int[p];
    for(int i=0;i<p;i++){
        int temp=arr[i];
        arr1[temp]+=1;
    }
    cout<< arr1;
    // for(int i=0;i<p;i++){
    //     int temp=arr[i];
    //     cout<<arr1[i]<<endl;
    // }



    delete[] arr;
    delete[] arr1;
    return 0;
}