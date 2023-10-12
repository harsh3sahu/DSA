#include<iostream>
using namespace std;


bool binSearch(int arr[], int start, int end, int key){
    int mid=(start+end)/2;
   

    if(start>end){
        return false;
    }

      
    if(key==arr[mid]){
        return true;
    }
    

    else if(key<arr[mid]){
        return binSearch(arr,start, mid-1,key);
    }

    else if(key>arr[mid]){
        return binSearch(arr,mid+1, end,key);
    }
    
    return false;
}

int main(){


    int arr[10]={11,12,23,34,45,48,50,51,65,76};

    int size=sizeof(arr)/sizeof(int);
    int key;

    cout<<"enter the number\n";
    cin>>key;

    bool ans=binSearch(arr, 0, size, key);

    if(ans==true){
        cout<<"number found\n";

    }

    else
        cout<<"not found\n";


    return 0;
}