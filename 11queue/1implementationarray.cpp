#include<iostream>

using namespace std;

class Queue{

    public:
    int size;
    int data;
    int *arr;
    int front=0;
    int rear=0;

    Queue(int size){
        this->size=size;
        arr=new int[size];
    }

    void enque(int data){
        if( rear<size && (rear==0 || front!=rear)){
        arr[rear]=data;
        rear++;
        }

        else if(rear==size && front >0){
            rear=0;
            arr[rear]=data;
            rear++;
        }

        else {
            cout<<"queue overflow\n";
        }
        
    }

    void deque(){
        if(front==rear){
            cout<<"queue empty";
        }

        else {
            arr[front]=-1;
            front++;

            if(front>=size && front != rear){
                front=0;
            }

            else if(front >= size && front==rear){
                cout<<"queue overflow\n";
            }

        }
    }

    bool empty(){
        if(front == rear){
            return true;
        }

        else 
            return false;
    }

    int first(){
        return arr[front];
    }

    int last(){
        return arr[rear-1];
    }

    
};


int main(){

    Queue q(5);

    q.enque(10);
    cout<<q.first()<<endl;
    cout<<q.last()<<endl<<endl;
    q.enque(20);
    cout<<q.first()<<endl;
    cout<<q.last()<<endl<<endl;
    q.enque(30);
    cout<<q.first()<<endl;
    cout<<q.last()<<endl<<endl;
    q.enque(40);
    cout<<q.first()<<endl;
    cout<<q.last()<<endl<<endl;
    q.enque(50);
    cout<<q.first()<<endl;
    cout<<q.last()<<endl<<endl;

    q.deque();
    q.enque(60);
    cout<<q.first()<<endl;
    cout<<q.last()<<endl<<endl;

    q.enque(70);
    cout<<q.first()<<endl;
    cout<<q.last()<<endl<<endl;



    return 0;
}