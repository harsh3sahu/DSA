#include<iostream>
#include<stack>

using namespace std;

int main(){

    stack<int> first;
    int size;
    cout<<"enter the size of stack to be created \n";
    cin>>size;
    int element;
    for(int i=0;i<size;i++){
        cin>>element;
        first.push(element);
    }

    stack<int> second;

    for(int i=1;i<size;i++){
        if(i== (size/2)+1){
            first.pop();
            break;
        }

        else{
            second.push(first.top());
            first.pop();
        }
    }

    while(!second.empty()){
        first.push(second.top());
        second.pop();
    }

    while(!first.empty()){
        cout<<first.top()<<endl;
        first.pop();

    }





    return 0;
}