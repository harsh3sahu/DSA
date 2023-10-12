#include<iostream>
using namespace std;

bool checkPalindrome(string& s,int i, int j){
   
    if(i>=j){
        cout<<"palindrome\n";
    }

    if(s[i]!=s[j]){
        cout<<"not a palindrome\n";
    }

    i++;
    j--;


    checkPalindrome(s, i, j);



    
}

int main(){

    string str="abcba";

    bool ans=checkPalindrome(str, 0, str.length()-1);

    cout<<ans;
    


    return 0;
}