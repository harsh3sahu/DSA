#include<iostream>

using namespace std;

void insort(int arr[], int size){
    for(int i=1;i<size;i++){
        for(int j=i-1;j>=0;j--){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
            
        }
    }

}

int main(){


    int arr[10] = {24, 58, 12, 56, 1, 64, 90, 10, 87, 90};
    int size = sizeof(arr) / sizeof(int);
    
    insort(arr,size);

    for(auto i:arr){
        cout<<i<<"  ";
    }

    return 0;
}