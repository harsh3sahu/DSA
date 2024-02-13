#include<iostream>

using namespace std;

class dQueue{

    public:
    int size;
    int *arr;
    int front=-1;
    int rear=-1;

    dQueue(int size){
        this->size=size;

        arr=new int[size];
    }

    void push_front(int data){
        if(front==-1 && rear==-1){
            front=0;
            rear=0;

            arr[front]=data;
            

        }
        else if(front >0 && front<size && front-1!=rear){
            front--;
            arr[front]=data;
        }
        else if(front==0 && rear!=size-1){
            front=size-1;
            arr[front]=data;
        }
    }


    void push_back(int data){
        if(front==-1 && rear==-1){
            front=0;
            rear=0;
            arr[rear]=data;
        }
    
    
        else if(rear>=0 && rear<size-1 && rear+1!=front){
        rear++;
        arr[rear]=data;
        }
        else if(rear==size-1 && front!=0){
        rear=0;
        arr[rear]=data;
        }

    }

    void pop_front(){
        if(front>=0 && front<size-1){

            arr[front]=-1;
            front++;
        }
        else if(front==size-1){
            arr[front]=-1;
            front=0;
        }
        else{
            cout<<"not possible\n";
        }
    }

    void pop_back(){
        if(rear>0 && rear<size){
            arr[rear]=-1;
            rear--;
        }
        else if(rear==0){
            arr[rear]=-1;
            rear=size-1;
        }
        else{
            cout<<"not possible\n";
        }
    }

    void printdQueue(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<endl;
        }
    }




};


int main(){

    dQueue dq(5);

    dq.push_front(10);
    dq.push_back(20);
    dq.push_back(30);
    dq.push_back(50);
    dq.push_back(40);

    dq.pop_front();
    dq.pop_back();

    dq.printdQueue();




    return 0;
}