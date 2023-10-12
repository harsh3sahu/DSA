#include<iostream>
using namespace std;

int binSearch(int arr[], int size, int x){

    int start=0;
    int end=size-1;
    int mid=(start+end)/2;

    while(start<end){

        if(x==arr[mid]){
            return mid;
        }

       if((arr[mid]>arr[mid+1])&& x<arr[mid]){
        start = mid;
       }

       if((arr[mid]>arr[mid+1])&& x>arr[mid]){
        end = mid;
       }

       if((arr[mid]<arr[mid+1])&& x<arr[mid]){
        end = mid;
       }

       if((arr[mid]<arr[mid+1])&& x>arr[mid]){
        start = mid;
       }
       
        

       mid=(start+end)/2;

    }
    
    return mid;


}



int main(){

    int array[11]={1,3,23,44,100,99,95,90,42,21,4};
    cout<<"enter a number\n";
    int n;
    cin>>n;

    int s=sizeof(array)/sizeof(int);
    int piv=binSearch(array, s,n);

    
    cout<<array[piv];
    return 0;
}