#include<iostream>
using namespace std;

void merge(int* arr, int start, int end){

    int mid=(start+end)/2;

    int len1=mid+1-start;
    int len2=end-mid;

    int *first=new int[len1];
    int *second=new int[len2];

    int index=start;

    for(int i=0;i<len1;i++){
        first[i]=arr[index++];
    }
    int k=mid+1;

    for(int i=0;i<len2;i++){
        second[i]=arr[k++];
    }

    int index1=0;
    int index2=0;
    index=start;

    while(index1<len1 && index2<len2){
        if(first[index1]<second[index2]){
            arr[index]=first[index1];
            index1++;
            index++;
            // cout<<"everything is okay1\n";
        }

        else {
            arr[index]=second[index2];
            index2++;
            index++;
        }
    }

    while(index1<len1){
        arr[index]=first[index1];
        index1++;
        index++;
                    // cout<<"everything is okay 2\n";

    }

    while(index2<len2){
        arr[index]=second[index2];
        index2++;
        index++;
    }


    delete[] first;
    delete[] second;


}

void mSort(int* arr, int start, int end){

    cout<<"start="<<start<<endl<<"end="<<end<<endl;
        // cout<<"everything is okay 4 \n";

    if(start>=end){
        return ;
    }
    int mid=(start+end)/2;
    mSort(arr, start,mid);
    mSort(arr, mid+1, end);
    // cout<<"everything is okay3 \n";

    merge(arr,start,end);
}



int main(){

    int arr[10]={12,100,32,11,34,54,23,4,67,2};
    int size=sizeof(arr)/sizeof(int);
    mSort(arr,0, size-1);

    for(int i=0;i<size;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}