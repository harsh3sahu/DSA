#include<iostream>
#include<stack>
#include<vector>
using namespace std;

// vector<int> nextMin(vector<int> &arr, int size){

//     stack<int> s;
//     s.push(-1);
//     vector<int>ans(size);

//     for(int i=size-1;i>=0;i--){
//         int curr=arr[i];
        
//         while(!s.empty() && s.top()>=curr){
//             s.pop();

//         }
//         cout<<"check point \n";
        
//         ans[i]=s.top();

//         s.push(curr);



//     }

//     return ans;

// }


vector<int> nextMin(vector<int> &arr, int size){

    stack<int> s;
    s.push(-1);
    vector<int> ans(size);
    for(int i=size-1;i>=0;i--){
        int curr=arr[i];

        while(!s.empty() && curr<=s.top()){
            s.pop();
        }


        ans[i]=s.top();
        s.push(curr);
    }

    return ans;


}

int main(){

    
    int size;
    cout<<"enter size\n";
    cin>>size;

    vector<int> arr(size);

    for(int i=0;i<size;i++){
        cin>>arr[i];
    }

    
    vector<int> ans;

    ans=nextMin(arr,size);

    int sa=ans.size();

    for(int i=0;i<sa;i++){
        cout<<"  "<<ans[i]<<"  ";
    }



    return 0;
}