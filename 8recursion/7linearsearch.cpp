#include<iostream>
using namespace std;

bool linearSearch(int arr[], int size, int key){

    if(key== arr[0]){
        return true;
    }

    if(size<0){
        return false;
    }

    bool  ans=linearSearch (arr+1,size-1,key);
    
    return ans;

}

int main(){

    int arr[5]={2,4,5,7,10};

    int size=sizeof(arr)/sizeof(int);
    int key;
    cout<<"enter the key\n";
    cin>>key;
    bool ans= linearSearch(arr, size, key);

    if(ans){
        cout<<"found\n";

    }

    else {
        cout<<"not found\n";
    }


    return 0;
}