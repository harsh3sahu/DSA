#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> firstNegative(int arr[], int k, int size){
    vector<int> ans;
    
    deque<int> dq;
    for(int i=0;i<k;i++){
        if(arr[i]<0){
            dq.push_back(i);
             
        }
    }

    cout<<"fine\n";

    if(dq.size()>0){
        ans.push_back(arr[dq.front()]);

    }

    else{
        ans.push_back(0);
    }

    for(int i=k;i<size;i++){
        if(!dq.empty() && i-dq.front()>=k){
            dq.pop_front();
        }
        

        if(arr[i]<0){
            dq.push_back(i);
        }
      

        ans.push_back(arr[dq.front()]);

    }

    return ans;
}

int main(){

    int arr[8]={12, -1, -7, 8, -15, 30, 16, 28};
    int size=8;
    int k=3;

    vector<int> ans;
 
    ans=firstNegative(arr, k, size);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }



    return 0;
}