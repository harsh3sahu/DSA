#include<iostream>
#include<queue>
#include<stack>


using namespace std;

int main(){

    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    int size=10;
    queue<int> q;
    int k=7;

    for(int i=0;i<size;i++){
        q.push(arr[i]);
    }

    stack<int> s;

    for(int i=0;i<k;i++){
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }

    for(int i=0;i< size-k;i++){
        int element = q.front();
        q.pop();
        q.push(element);
    }

    while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
    }





   return 0;
}