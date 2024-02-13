#include<iostream>

using namespace std;

bool binSearch(int arr[], int start,int end, int key){
    
    if(start>end){
        return false;
    }
    int mid = (start+end)/2;
    if(key==arr[mid]){
        return true;
    }

    if(arr[mid]==key){
        return true;
    }

    

    else if(key>arr[mid]){
        return binSearch(arr, mid+1, end, key);
    }
    else{
        return binSearch(arr, start, mid-1, key);
    }
} 

int main(){

    int arr[10]={11,12,23,34,45,48,50,51,65,76};

    int key=23;

    int size=10;

    bool ans = binSearch(arr,0,9, key);

    cout<<ans<<endl;

    return 0;
}