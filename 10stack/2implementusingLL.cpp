#include<iostream>


using namespace std;

class Stack{

    public:
    int size;
    int *arr;
    int top1,top2;

    Stack(int size){
        this->size=size;
        arr=new int[size];
        top1=-1;
        top2=size;
    }

    void push1(int n){
        if(top2-top1>1){
            top1++;
            arr[top1]=n;
        }

        else {
            cout<<"stack overflow\n";
        }
        
    }

    void push2(int n){
        if(top2-top1>1){
            top2--;
            arr[top2]=n;
        }

        else {
            cout<<"stack overflow\n";
        }
        
    }


    void pop1(){
        if(top1>=0){
            top1--;
        }

        else{
            cout<<"stack underflow\n";
        }
    }

    void pop2(){
        if(top2<size){
            top2++;
        }

        else{
            cout<<"stack underflow\n";
        }
    }

    void peek1(){
        cout<<arr[top1]<<endl;
    }

    void peek2(){
        cout<<arr[top2]<<endl;
    }

    bool empty1(){
        if(top1==-1){
            return true;
        }

        else 
            return false;
    }

     bool empty2(){
        if(top2==size-1){
            return true;
        }

        else 
            return false;
    }


};



int main(){

    int size;
    cout<<"enter size of both the stacks combined\n";
    cin>>size;
    
    Stack st(size);

    st.push1(1);
    st.push1(3);
    st.push1(5);
    st.push1(7);

    st.push2(2);
    st.push2(4);
    st.push2(6);
    st.push2(8);

    st.peek1();
    st.peek2();

    st.pop1();
    st.pop2();

    st.peek1();
    st.peek2();


    return 0;
}