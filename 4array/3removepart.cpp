#include<iostream>
#include<string>

using namespace std;

string rem(string s,string part){
    size_t pos = s.find(part);
    if (pos != string::npos) {
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