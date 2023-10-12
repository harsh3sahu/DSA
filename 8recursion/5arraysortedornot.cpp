#include<iostream>
using namespace std;

bool isSorted(int arr[], int size){
    if(size==0 || size==1){
        return true;
    }

    if(arr[0]>arr[1]){
        return false;
    }

    else{
        bool ans=isSorted(arr+1, size-1);
        return ans;
    }
}

int main(){

    int arr[5]={2,4,6,5,9};

    int size=sizeof(arr)/sizeof(int);

    bool ans = isSorted(arr,size);

    if(ans){
        cout<<"array is sorted\n";

    }
    else {
        cout<<"array is not sorted\n";
    }


    return 0;
}