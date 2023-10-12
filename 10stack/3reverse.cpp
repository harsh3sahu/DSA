#include<iostream>
#include<stack>

using namespace std;

void reverseStack(stack<int>& s){
    if(s.empty()){
        return ;
    }
    int element=s.top();
    s.pop();
    reverseStack(s);

    s.push(element);
}

int main(){

    // string str="harsh";

    // stack<char> s;

    // for(int i=0; i<str.size(); i++){
    //     char e=str[i];

    //     s.push(e);
    // }

    // string ans="";

    // while(!s.empty()){
    //     ans.push_back(s.top());
    //     s.pop();
    // }

    // cout<<"reversed string is "<<ans<<endl;


    //now using recurssion

    stack <int> s;
    int size;
    cout<<"enter size\n";
    cin>>size;
    cout<<"now enter elements\n";
    for(int i=0;i<size;i++){
        int num;
        cin>>num;
        s.push(num);
    }

    reverseStack(s);

    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }




    return 0;
}