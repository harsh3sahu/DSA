#include<iostream>
#include<string>

using namespace std;

string rem(string s, string subs){

    size_t pos= s.find(subs);

    while(pos!=string::npos){
        s.erase(pos,subs.length());
        pos=s.find(subs);
    }

    return s;
}

int main(){

    string s;
    string subs;

    cout<<"enter string\n";
    getline(cin,s);

    cout<<"enter substring\n";
    getline(cin,subs);

    cout<<rem(s,subs);


    return 0;
}