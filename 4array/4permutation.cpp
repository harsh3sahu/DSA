#include<iostream>
using namespace std;


bool equal(int a[],int b[]){
    for(int i=0;i<26;i++){
        if(a[i]!=b[i]){
            return 0;
        }
    }
    return 1;
}

bool check(string s1,string s2){
    
    int count1[26]={0};
    int index;
    for (int i=0;i<s1.length(); i++){
        index=s1[i]-'a';
        count1[index]++;
    }
    int i=0;
    int window=s1.length();
    int count2[26]={0};
    while(i<window){
        int index=s2[i]-'a';
        count2[index]++;
        i++;
    }
    if(equal(count1,count2)){
        return 1;
    }

    // while(i<s2.length()){
    //     char newChar=s2[i];
    //     int index=newChar-'a';
    //     count2[index]++;

    //     char oldChar=s2[i-s1.length()];
    //     index=oldChar-'a';
    //     count2[index]--;
    //     i++;

    //     if(equal(count1,count2)){
    //         return 1;
    //     }


    // }
    return 0;

}



int main(){

    string s1 = "harsh";
    string s2= "hsarh";

    bool ans=check(s1,s2);





    cout<<ans;

    return 0;
}