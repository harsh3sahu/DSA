#include<iostream>
using namespace std;

class heap{

    public:
    int arr[100];
    int size=0;

    void insert(int val){
        size=size+1;
        int index=size;
        arr[index]=val;

        while(index>1){
            int parent=index/2;

            if(arr[parent]< arr[index]){
                swap(arr[parent], arr[index]);
                index=parent;
            }

            else{
                return ;
            }
        }
    }

    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }

        cout<<endl;
    }

    void deleteNode(){
        if(size==0){
            cout<<"nothing to delete\n";
            return;
        }

        swap(arr[1],arr[size]);
        size--;

        int index=1;
        while(index<size){
            int leftchild=2*index;
            int rightchild=2*index +1;

            if(leftchild<size && arr[leftchild]> arr[index]){
                swap(arr[leftchild], arr[index]);
                index=leftchild;
            }

            else if(rightchild<size && arr[rightchild]> arr[index]){
                swap(arr[rightchild], arr[index]);
                index=rightchild;
            }

            else{
                return ;
            }
        }
    }


};


int main(){

    heap h;
    h.insert(54);
    h.insert(53);
    h.insert(55);
    h.insert(52);
    h.insert(50);

    h.print();

    h.deleteNode();
    h.print();



    return 0; 
}