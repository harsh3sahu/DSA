#include<iostream>
using namespace std;

int main(){


    int arr[8]={5,5,6,6,6,9,1,2};

    int index;
    int count=0;
    int size=sizeof(arr)/sizeof(int);
    // int s=arr.size();
    for(int i=1;i<size;i++){
        if(arr[i-1]>arr[i]){
            index=i-1;
            count++;
        }

        if(i>1 && arr[i-1]>arr[i] && arr[i-2]<arr[i+1]){
            
            count++;
        }

        if (i==1 && arr[0]<arr[size-1]){
             count++;
        }
    }

    if(count==1){
        cout<<"it is rotated \n";
        cout<<index;
    }

    else if(count==0){
        cout<<"it is sorted \n";
    }

    else{
        cout<<"not sorted or rotated\n";
    }



    return 0;
}