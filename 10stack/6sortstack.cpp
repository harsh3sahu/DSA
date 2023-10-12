#include<iostream>
#include<stack>

using namespace std;

void sortinsert(stack<int> &s, int num ){

    if(s.empty() || s.top() < num){
        s.push(num);
        return;
    }

    int n=s.top();
    s.pop();
    sortinsert(s,num);

    s.push(n);
}

void sortstack(stack<int> &s){
    if(s.empty()){
        return;
    }

    int n=s.top();
    s.pop();
    sortstack(s);

    sortinsert(s,n);
}

int main(){

    stack<int> s;
    int size;

    cout<<"enter size of stack\n";
    cin>>size;
    for(int i=0; i<size ; i++){
        int n;
        cin>>n;
        s.push(n);
    }

    sortstack(s);


    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }


    return 0;
}