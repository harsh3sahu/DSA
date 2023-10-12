#include<iostream>

class dQueue{

public:
    int size;
    int *arr;
    int front=-1;
    int rear=-1;

    dQueue(int data){
        arr=new int[size];
    }


    void push_front(int data){
        if(front == -1 && rear ==-1 ){
            front =rear=0;
            arr[front]=data;
            

        else {
            if(front != rear){
                front--;
                arr[front]=data;
            }

            else{
                
            }
        }
    }

    void push_back(int data){
        if(front ==-1 &&  rear ==-1){
            front =rear=0;
            arr[rear]=data;
        }

        else{
            if(front !=rear ){
                rear++;
                arr[rear]=data;
            }

            else{
                cout<<"overflow\n";
            }
        }
    }

};


int main(){

    


    return 0;
}