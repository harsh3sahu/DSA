#include<iostream>
using namespace std;

int sumArray(int arr[], int size){
    
    if(size==0){
        return 0;
    }

    if(size==1){
        return arr[0];
    }

    int remainingpart=sumArray(arr+1,size-1);
    int sum=arr[0]+ remainingpart;
    return sum;


}


int main(){

    int arr[5]={2,4,5,7,8};

    int size=sizeof(arr)/sizeof(int);

    int ans= sumArray(arr,size);
    cout<<ans<<endl;



    return 0;
}

