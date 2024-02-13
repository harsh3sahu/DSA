#include<iostream>
#include<vector>

using namespace std;

class Stack{

    public:
    int size;
    int *arr;
    int top;

    Stack(int size){
        this->size=size;
        arr= new int[size];
        top=-1;

    }    

    void push(int data){
        if(top<size-1){
            arr[top+1]=data;
            top++;
        }
        else{
            cout<<"stack full\n";
        }
    }

    void pop(){
        if(top>-1){
            top--;
        }
        else{
            cout<<"stack empty\n";
        }
    }

    void print(){
        int temp=top;
        while(temp>-1){
            cout<<arr[temp]<<endl;
            temp--;
        }
    }
    void peek(){
        if(top>-1 && top<size-1){
            cout<<arr[top]<<endl;

        }
        else{
            cout<<"error\n";
        }
    }

    void isEmpty(){
        if(top==-1){
            cout<<"yes, empty\n";
        }
        else{
            cout<<"not empty\n";
        }
    }

};


int main(){


    Stack s(5);
    s.push(11);
    s.push(12);
    s.push(13);
    s.push(14);
    s.push(15);

    s.pop();

    s.print();
    s.pop();
    s.peek();
    
    s.isEmpty();


    return 0;
}