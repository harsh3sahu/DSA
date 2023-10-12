#include<iostream>
#include<stack>

using namespace std;


class minStack{

    public:
    int mini;
    int size;
    stack<int> st;

    minStack(int size){
        this->size=size;
    }

    void push(int n){
        if(st.empty()){
        st.push(n);
        mini=n;
        }

        else {
            
            if(n>mini){
                st.push(n);
            }

            else{

                int value= (2*n)-mini;
                st.push(value);
                mini=n;

            }
        }
    }

    void pop(){
        if(!st.empty()){
            if (st.top()> mini){
                st.pop();
            }

            else{
                int value= (2*mini-st.top());
                st.pop();
                mini=value;
            }
        }

        else {
            cout<<"stack underflow\n";
        }
    }
    

};

int main(){

    minStack ms(5);

    ms.push(5);
    cout<<ms.mini<<endl;

    ms.push(3);
    cout<<ms.mini<<endl;

    ms.push(8);
    cout<<ms.mini<<endl;

    ms.push(2);
    cout<<ms.mini<<endl;

    ms.push(4);
    cout<<ms.mini<<endl;

    ms.pop();
    // ms.pop();

    cout<<ms.st.top();

    return 0;
}

