#include<iostream>
using namespace std;

class Queue{

    public:
    int size;
    int *arr;
    int front=-1;
    int rear=-1;

    Queue(int size){
        this->size=size;

        arr= new int[size];
    }

    void push(int data){

        if(front==-1 && rear==-1){
            front = 0;
            rear=0;
            arr[rear]=data;
            rear++;
        }
        else{
            arr[rear]=data;
            rear++;
        }

    }

    void pop(){
        if(front==-1 && rear==-1){
            cout<<"queue empty\n";
        }
        else {
            arr[front]=-1;
            front++;
        }
    }

    void printQueue(){
        for(int i=front;i<rear;i++){
            cout<<arr[i]<<endl;
        }
    }

};


int main(){

    Queue q(5);

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.printQueue();
    q.pop();
    cout<<endl<<endl;
    q.printQueue();




    return 0;
}