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
        if(arr[mid]>arr[mid+1]){
            end=mid;
        }
        if(start==end){
            return start;
        }
    }
    return -1;
}

int binSearch(int arr[], int siz, int x){
    int pivot= findPivotIndex(arr, siz);
    // cout<<pivot;

    int s1=0;
    int s2=pivot+1;
    int e1=pivot;
    int e2=siz-1;

    while(s1 <= e1 && s2 <= e2  ){
        int m1=(s1+e1)/2;
        int m2=(s2+e2)/2;

        if(x==arr[m1]){
            return m1;
        }
        if(x==arr[m2]){
            return m2;
        }

        if(x<arr[m1]){
            e1=m1;
        }
        if(x>arr[m1]){
            s1=m1+1;
        }

        if(x<arr[m2]){
            s2=m2+1;
        }
        if(x>arr[m2]){
            e2=m2;
        }

        
    }
    return -1;



}

int main(){


    int arr[11]={1,3,23,44,100,99,95,90,42,21,4};

    int x=44;

    int ans = binSearch(arr, 11, x); 

    if(ans!=-1){
        cout<< ans;
    }
    else{
        cout<< "not found\n";
    }
    





    return 0;
}