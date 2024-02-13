#include<iostream>
#include<string>

using namespace std;

bool check(string s1, string s2){

    int count1[26]={0};
    for(int i=0;i<s1.length();i++){
        int index= s1[i]-'a';
        count1[index]++;
    }

    int count2[26]={0};
    for(int i=0;i<s2.length();i++){
        int index= s2[i]-'a';
        count2[index]++;
    }

    for(int i=0;i<26;i++){
        if(count1[i]!=count2[i]){
            return false;
        }
    }
    return true;

}


int main(){

    string s1="harsh";
    string s2="arsh";

    cout<<check(s1,s2);
   
    return 0;
}