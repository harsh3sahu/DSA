#include<iostream>
using namespace std;

int findPivotIndex(int arr[], int size){
    int start=0;
    int end=size-1;

    while(start<end){
        int mid = (start+end)/2;
        if(arr[mid]<arr[mid+1]){
            start=mid+1;
        }
        else{
            end=mid;
        }
    }
    return start;
}

int binSearch(int arr[], int siz, int x){
    int pivot= findPivotIndex(arr, siz);

    int s, e;
    if (x >= arr[0]) {
        s = 0;
        e = pivot;
    } else {
        s = pivot + 1;
        e = siz - 1;
    }

    while(s <= e){
        int m=(s+e)/2;

        if(x==arr[m]){
            return m;
        }

        if(x<arr[m]){
            e=m-1;
        }
        else{
            s=m+1;
        }
    }
    return -1;
}

int main(){
    int arr[11]={4,3,23,44,100,99,95,90,42,21,1};
    int x=1;
    int ans = binSearch(arr, 11, x); 

    if(ans!=-1){
        cout<< ans;
    }
    else{
        cout<< "not found\n";
    }
    return 0;
}
