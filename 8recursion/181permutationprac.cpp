#include<iostream>
#include<vector>

using namespace std;

void solve(vector<int> arr, vector<vector<int>> &ans, vector<int> &output, int index, int n){

    if(index>=arr.size()){
        ans.push_back(arr);
        return ;
    }

    for(int i=index;i<n;i++){
        swap(arr[index],arr[i]);

        solve(arr,ans,output,index+1,n);

        swap(arr[index],arr[i]);
    }

}

int main(){

    int n;
    cout<<"enter number of elements\n";
    cin>>n;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    vector<vector<int>> ans;
    vector<int> output;
    int index=0;
    solve(arr, ans, output, index,n);

    for(auto &row : ans){
        for(auto &col: row){
            cout<<col<<" ";
        }
        cout<<endl;
    }

    return 0;
}
