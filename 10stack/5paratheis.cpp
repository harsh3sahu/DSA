#include<iostream>
#include<stack>

using namespace std;

int main(){

    string str;
    getline(cin,str);

    stack <char> s1;

    for(int i=0;i<str.length();i++){
        char ch=str[i];

        if(ch=='{' || ch=='(' || ch=='['){
            s1.push(ch);
        }

        else if( (ch=='}' && s1.top()=='{')  || (ch==')' && s1.top()=='(' ) || ( ch==']' && s1.top()=='[')){
            s1.pop();
        }

    }

    if(s1.empty()){
        cout<<"yes it is a valid parenthisis\n";
    }

    else{
        cout<<"it is not a valid parenthisis\n";
    }








    return 0;
}