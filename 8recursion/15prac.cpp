#include<iostream>
#include<vector>
using namespace std;

void subs(int arr[], vector<int> output, vector<vector<int>> &ans, int index, int &size){

    if(index>=size){
        ans.push_back(output);
        return ;
    }

    subs(arr,output,ans,index+1,size);

    output.push_back(arr[index]);

    subs(arr,output,ans,index+1,size);



}

int main(){


    int arr[3]={1,2,3};

    int size=3;
    vector<vector<int>> ans;
    vector<int> output;
    int index=0;

    subs(arr,output,ans,index,size);

    for(auto i:ans){
        for(auto j:i){
            cout<<j<<"  ";
        }
        cout<<endl;
    }

    return 0;   
}