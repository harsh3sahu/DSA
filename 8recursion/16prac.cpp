#include<iostream>
#include<string>
#include<vector>

using namespace std;

void seq(string str, string output, vector<string> &ans, int index){

    if(index>=str.length()){
        ans.push_back(output);
        return ;
    }

    seq(str,output,ans,index+1);

    output.push_back(str[index]);

    seq(str,output,ans,index+1);


}

int main(){

    string str="abc";

    string output;
    vector<string>ans;

    int index=0;

    seq(str,output,ans,index);

    for(auto i:ans){
        cout<<i<<endl;
    }


    return 0;
}