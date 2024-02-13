#include<iostream>
#include<string>
#include<vector>

using namespace std;

void phoneComb(string input, string mapping[], string output, vector<string> &ans, int index){
    if(index>=input.length()){
        ans.push_back(output);
        return ;
    }

    int digit = input[index]-'0';
    int len = mapping[digit].length();


    for(int i=0;i<len;i++){
        output.push_back(mapping[digit][i]);
        phoneComb(input,mapping,output,ans,index+1);
        output.pop_back();

    }




}

int main(){


    string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    string input="34";
    string output;

    vector<string> ans;

    int index=0;

    phoneComb(input,mapping,output,ans,index);


    for(auto i:ans){
        cout<<i<<endl;
    }



    return 0;
}