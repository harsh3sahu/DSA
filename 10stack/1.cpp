#include<iostream>

using namespace std;

class Stack{

    public:
    int top;
    int *arr;
    int size;


    Stack (int size){
        this->size=size;
        arr=new int [size];
        top=-1;
    }

    void push(int data){
        if (top<size-1){
            top++;
            arr[top]=data;
        }
        else{
            cout<<"stack overflow\n";
        }
    }

    void pop(){
        if(top>-1){
            top--;
        }

        else {
            cout<<"stack underflow\n";
        }
    }

    void peek(){
        cout<<arr[top]<<endl;
    }

    void isempty(){
        if(top==-1){
            cout<<"stack is empty\n";
        }

        else {
            cout<<"stack is not empty\n";
        }
    }

};

int main(){

  
    Stack s(5);

    s.push(10);
    s.push(15);
    s.push(20);

    s.peek();
    s.pop();
    s.peek();
    s.isempty();



    return 0;
}