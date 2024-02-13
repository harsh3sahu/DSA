#include<iostream>

using namespace std;

class heap{

public:
    int arr[100];
    int size=0;

    heap(){
        arr[0]=-1;
        size=1;
    }

    void insert(int data){
        arr[size]=data;
        size++;
        // this->heapify();

    }

    void print(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<endl;
        }
    }

    void heapify(){
        int index=size-1;

        for(int i=index/2;i>0;i--){
            int leftChild=2*i;
            int rightChild=(2*i)+1;

            if(arr[i]<arr[leftChild] && leftChild<=index){
                swap(arr[i],arr[leftChild]);
                i++;
            }

            if(arr[i]<arr[rightChild] && rightChild<=index){
                swap(arr[i],arr[rightChild]);
                i++;
            }

        }
    
    }


    void deletefromHeap(){
        if(size==0){
            cout<<"heap is empty\n";
            return ;
        }
        int lastIndex=size-1;

        arr[1]=arr[lastIndex];
        size--;
        int index=1;
        while(index<=size){
            int left=index*2;
            int right=(index*2)+1;

            if(arr[left]>arr[index] && left<=size-1){
                swap(arr[left],arr[index]);
                index=left;
            }
            else if(arr[right]>arr[index] && right<=size-1){
                swap(arr[right],arr[index]);
                index=right;
            }
            else{
                return ;
            }

        }
        



    }
    

};



int main(){

    heap h;
    h.insert(10);
    h.insert(20);
    h.insert(0);
    h.insert(90);
    h.insert(50);
    h.insert(60);

    h.heapify();

    h.deletefromHeap();

    
    
    h.print();





    return 0;
}