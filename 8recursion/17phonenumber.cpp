#include<iostream>
#include<vector>
using namespace std;

void phoneComb(string digit, string output, vector<string>& ans, int index, string mapping[]){

    if(index>=digit.length()){
        ans.push_back(output);
        return ;
    }
    

    int number=digit[index]-'0';
    string value=mapping[number];
    
    for(int i=0;i<value.length();i++){
        output.push_back(value[i]);
        phoneComb(digit,output,ans,index+1,mapping);
        output.pop_back();
    }       


}

int main(){

    string number="34";
    
    string output;
    vector<string> ans;
    int index=0;
    string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    phoneComb(number,output,ans,index,mapping);
    for (const auto& row : ans) {
        // Iterate over the columns of the vector
        for (const auto& col : row) {
            // Print the current element
            cout << col << ' ';
        }
        // Print a newline character after each row
        cout << '\n';
    }



    return 0;
}