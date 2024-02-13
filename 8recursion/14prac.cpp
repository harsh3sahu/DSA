#include<iostream>
using namespace std;

int partition(int arr[], int s , int e){
    int pivot=arr[s];
    int count =0;
    for(int i=s+1;i<=e;i++){
        if(arr[i]<pivot){
            count++;
        }
    }

    int pivotIndex=count+s;

    swap(arr[s],arr[pivotIndex]);

    int i=s;
    int j=e;

    while(i<pivotIndex && j>pivotIndex){
        while(arr[i]<pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(arr[i]>pivot && arr[j]<pivot){
            swap(arr[i],arr[j]);
        }
        



    }

            return pivotIndex;




}

void qSort(int arr[], int s, int e){
    if(s>e){
        return ;
    }

    int pivotIndex=partition(arr, s,e);
    
    qSort(arr,s,pivotIndex-1);
    qSort(arr,pivotIndex+1,e);


}

int main(){

    int arr[10] = {12, 100, 32, 11, 34, 54, 23, 4, 67, 2};

    int size= 10;

    qSort(arr, 0, 9);


    for(auto i: arr){
        cout<<i<<endl;
    }

    return 0;
}