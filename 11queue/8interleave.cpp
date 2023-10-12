#include<iostream>
#include<stack>
#include<queue>

using namespace std;

int main(){


    int size;
    cin>>size;

    queue<int> q;
    for(int i=0;i<size;i++){
        int e;
        cin>>e;
        q.push(e);
    }

    stack<int>s;

    int mid=size/2;

    for(int i=0;i<mid;i++){
        int e=q.front();
        q.pop();
        s.push(e);
    }

    










    return 0;
}