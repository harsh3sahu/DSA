#include<iostream>
#include<stack>
#include<vector>

using namespace std;

vector<int> nextSmall(int arr[], int size){

    stack<int> s;
    s.push(-1);
    vector<int> ans(size);

    for(int i=size-1;i>=0;i--){
        int curr= arr[i];

        while(!s.empty() && curr<=arr[s.top()] && s.top()!=-1){
            s.pop();
        }

        ans[i]=s.top();
        s.push(i);
    }

    return ans;

}

vector<int> prevSmall(int arr[], int size){

    stack<int> s;
    s.push(-1);
    vector<int> ans(size);

    for(int i=0;i<=size-1;i++){
        int curr= arr[i];

        while(!s.empty() && curr<=arr[s.top()] && s.top()!=-1){
            s.pop();
        }

        ans[i]=s.top();
        s.push(i);
    }

    return ans;

}



int maxArea(int arr[], int size){

    vector<int> prev(size);
    prev= prevSmall(arr, size);

    vector<int> next(size);
    next=nextSmall(arr, size);

    for(int i=0;i<size;i++){
        if(next[i]==-1){
            next[i]=size;
        }
    }

    int area=0;

    for(int i=0;i<size;i++){
        int l= next[i]-prev[i]-1;

        int b=arr[i];

        int newarea= l*b;

        area=max(area,newarea);

    }
    return area;


}

int main(){

    int arr[6]={7,4,5,6,6,3};

    int ans = maxArea(arr, 6);

    cout<<ans<<endl;




    return 0;
}