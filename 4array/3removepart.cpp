#include<iostream>
#include<string>

using namespace std;

string rem(string s,string part){
    size pos = s.find(part);
    while (pos != string::npos) {
        s.erase(pos, part.length());
        pos = s.find(part);
    }
    return s;
}


int main(){

    string s;
    string part;
    cout<<"enter string\n";
    getline(cin,s);
    cout<<"enter part\n";
    getline(cin,part);

    cout<<rem(s,part);




    return 0;
}