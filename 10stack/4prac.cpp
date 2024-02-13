#include<iostream>
#include<stack>

using namespace std;

int main(){

    string str;
    getline(cin,str);

    stack<char> s;

    for(int i=0;i<str.length();i++){

        if(str[i]=='{' || str[i]=='('){
            s.push(str[i]);
        }
        else if((str[i]=='}' && s.top()=='{') || (str[i==')' && s.top()=='(']) ){
            s.pop();
        }

    }

    if(s.empty()==true){
        cout<<"correct parenthesis\n";
    }
    else{
        cout<<"wrong\n";
    }


    return 0;
}