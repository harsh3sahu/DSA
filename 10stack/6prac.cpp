#include<iostream>
#include<stack>

using namespace std;

void sortInsert(stack<int> &s, int num){

    if(s.empty() || s.top()<num){
        s.push(num);
        return ;
    }

    int temp=s.top();
    s.pop();
    sortInsert(s,num);

    s.push(temp);



}

void ssort(stack<int> &s){
    if(s.empty()){
        return ;
    }

    int element=s.top();
    s.pop();
    
    ssort(s);

    sortInsert(s,element);

    



}


int main(){

    stack<int> s;
    s.push(12);
    s.push(15);
    s.push(13);
    s.push(10);
    s.push(230);
    s.push(1);

    ssort(s);

    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
}