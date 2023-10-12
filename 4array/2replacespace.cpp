#include<iostream>
#include<string>

using namespace std;


void rep(string s){
    string temp="";
    for(int i=0;i<s.length();i++){

        char ch=s[i];
        if(ch==' '){
           s.erase(i,1);
           s.insert(i,"@40");

        }

        
    }
    
    cout<<s;





}

int main(){

    string s;
    cout<<"enter a string"<<endl;
    getline(cin,s);

    rep(s);


    return 0;
}