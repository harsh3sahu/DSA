#include<iostream>
#include<vector>
using namespace std;

void per(vector<int> nums, vector<vector<int>>& ans ,int index ){

    if(index>=nums.size()){
        ans.push_back(nums);
        return ;
    }

    for(int i=index;i<nums.size();i++){

        swap(nums[index], nums[i]);

        per(nums,ans,index+1);

        swap(nums[index], nums[i]);


    }


}


int main(){

    int n;
    cout<<"enter number of elements\n";
    cin>>n;

    vector<int> nums(n);
    for(int i=0; i < n ; i++){
        cin>>nums[i];
    }
    int index=0;
   vector<vector<int>> ans;
    per(nums, ans, index);

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