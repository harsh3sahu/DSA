#include<iostream>

using namespace std;

class heap{

    public:
    int arr[100];
    int size=0;

    void insert(int data){
        size++;
        int index=size;

        arr[index]=data;
        while(index>1){
            int parent=index/2;

            if(arr[parent]<arr[index]){
                swap(arr[index],arr[parent]);
            }
            else{
                return ; 
            }
        }
    }

    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<"  ";
        }
    }

    void delete(){
        if(size==0){
            cout<<"nothing to delete\n";
            return ;
        }

        int index=1;

        while(index<size){
            int leftindex=index*2;
            int rightindex=(index*2)+1;

            if(leftindex<size && arr[index]<arr[leftindex]){
                swap(arr[index],arr[leftindex]);
                index=leftindex;
            }

            else if(rightindex<size && arr[index]<arr[rightindex]){
                swap(arr[index],arr[rightindex]);
                index=rightindex;
            }

            else{
                return ;
            }

        }
    }

    void heapify(){
        
        int leafindex=size/2+1;


        for(int i=leafindex;i>=1;i--){
            
            
        }


    }

};



int main(){


    heap h;
    h.insert(60)



    return 0;
}