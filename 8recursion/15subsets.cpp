#include<iostream>
#include<vector>
using namespace std;

void subsets(int arr[], vector<int>output ,vector<vector<int>>& ans,int size ,  int index ){
    
    if(index>=size){
        ans.push_back(output);
        return;
    }

    subsets(arr, output, ans,size , index+1);


    int element=arr[index];
    output.push_back(element);

    subsets(arr, output,ans,size, index+1);

    
   

}



int main(){

    int arr[3]={1,2,3};

    vector<vector<int>> ans;
    vector<int>output;
    int index=0;
    int size=sizeof(arr)/sizeof(int);
    subsets(arr, output, ans,size, index);

    for (const auto& row : ans) {
        // Iterate over the columns of the vector
        for (const auto& col : row) {
            // Print the current element
            cout << col << ' ';
        }
        // Print a newline character after each row
        cout << '\n';
    }

    cout<<endl<<ans.size()<<endl;

    return 0;
}