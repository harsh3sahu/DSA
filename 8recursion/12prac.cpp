#include<iostream>
using namespace std;

void merge(int arr[], int s, int e){

    int mid=(s+e)/2;

    int len1=mid+1-s;
    int len2=e-mid;

    int *first= new int[len1];
    int *second=new int [len2];

    int k=s;

    for(int i=0;i<len1;i++){
        first[i]=arr[k++];
    }
    k= mid+1;
    for(int i=0;i<len2;i++){
        second[i]=arr[k++];
    }

    int i=0;
    int j=0;
    int index=s;

    while(i<len1 && j<len2){
        if(first[i]<=second[j]){
            arr[index]=first[i];
            index++;
            i++;
        }
        else if(first[i]>second[j]){
            arr[index]=second[j];
            index++;
            j++;
        }
    }
    
    while(i<len1){
        arr[index]= first[i];
        i++;
        index++;
    }

    while(j<len2){
        arr[index]= second[j];
        j++;
        index++;
    }

    delete[] first;
    delete[] second;


}


void mergeSort(int arr[], int s, int e){
    if(s>=e){
        return ;
    }

    int mid=(s+e)/2;

    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1,e);

    merge(arr,s,e);


}

int main(){

    int arr[10]={12,100,32,11,34,54,23,4,67,2};

    mergeSort(arr, 0,9);

    for(auto i:arr){
        cout<<i<<"   ";
    }


    return 0;
}