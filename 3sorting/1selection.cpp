#include<iostream>
using namespace std;

void ssort(int array[], int size){
    for(int i=0;i<size-1;i++){
        int min =i;

        for(int j=i+1; j <size; j++){
                if(array[j]<array[min]){
                    min=j;
                }
        }
        swap(array[min],array[i]);
        // cout<<array[i]<<endl;
    }

    
    

}


int main(){


    int arr[10]={24,43,12,56,1,64,23,10,87,5};
    int size=sizeof(arr)/sizeof(int);


    ssort(arr,size);

    for(int i=0;i<size;i++){
        cout<<arr[i]<<endl;
    }




    return 0;
}