#include<iostream>
using namespace std;


int binSearch(int arr[], int x, int size){

    int start=0;
    int end=size-1;
    int middle =(start+end)/2;

    while(start<=end){

        if(x<arr[middle]){
            end=middle-1;
            // cout<<"endmiddle\n";
            // int middle =(start+end)/2;
        }
        if(x>arr[middle]){
            start=middle+1;
            // cout<<"start middle\n";
            // int middle =(start+end)/2;
        }

        if (x==arr[middle]){
            return middle;
        }

        middle =(start+end)/2;


    }

    return -1;


}

int main (){

    int array[9]={2,3,5,7,12,34,45,123,543};
    cout<<"enter a number\n";
    int x;
    cin>>x;
    int s=sizeof(array)/sizeof(x);

    int ans=binSearch(array, x, s);

    cout<<ans;






    return 0;
}