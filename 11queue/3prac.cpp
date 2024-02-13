#include<iostream>

using namespace std;

class dQueue{

    public:
    int size;
    int *arr;
    int front;
    int rear;

    dQueue(int s ize){
        this->size=size;
        
        arr=new int[size];
        memset(arr,-1,size);
        front=0;
        rear=0;

    }

    void push_front(int data){
        if(front==0){
            arr[front]=data;
            front=size-1;
        }
        else if( front>0 && front<size){
            arr[front]=data;
            front--;
        }
        
    }

    void push_rear(int data){
        if(rear=>0 &&  ){
            arr[rear]=data;
            rear++;
        }

    }



}


int main(){





    return 0;
}