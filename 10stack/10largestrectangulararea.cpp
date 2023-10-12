#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> prevSmallElements(int arr[],int size){

    stack<int> s;
    s.push(-1);
    vector<int> ans(size);

    for(int i=0;i<size;i++){

        int curr=arr[i];

        while(!s.empty() && arr[s.top()]>=curr){
            s.pop();
        }
    
        ans[i]=s.top();

        s.push(i);

    }

    return ans;

}

vector<int> nextSmallElements(int arr[],int size){

    stack<int> s;
    s.push(-1);
    vector<int> ans(size);

    for(int i=size-1;i>=0;i--){

        int curr=arr[i];

        while(!s.empty() && arr[s.top()]>=curr){
            s.pop();
        }

        ans[i]=s.top();

        s.push(i);

    }

    return ans;

}


int maxArea(int arr[], int size){
   
    vector<int> prev(size);
    
    prev=prevSmallElements(arr,size);

    vector<int> next(size);
    
    next=nextSmallElements(arr,size);

    int area=INT_MIN;
    

    int l;
    int b;

    // for(int i=0;i<size;i++){
    //     cout<<prev[i]<<endl;
    // }

    for(int i=0;i<size;i++){
        
        int l=arr[i];

        if(next[i]==-1){
            next[i] =size;
        }

        b=next[i]-prev[i]-1;
        cout<<b<<endl;
        int newarea=l*b;

        area=max(area,newarea) ;


    }
    
    return area;

}

int main(){


    int arr[6]={2,1,5,6,2,3};
    int ans=0;

    int size=sizeof(arr)/sizeof(int);

    // for(int i=0;i<6;i++){
    //     int curr=arr[i];

    //         int j=i+1;
        
    //         while(arr[j]>=curr){
    //             curr=curr+curr;
    //             j++;
    //         }
            
    //         j=i-1;
    //         while(arr[j]>=curr){
    //             curr=curr+curr;
    //             j--;
    //         }

    //         if(curr>ans){
    //             ans=curr;
    //         }
        
    // }

    // cout<<ans;


    // we will do this same question with the help of stack in O(n) time complexity.

    int ans1=maxArea(arr,size);
    cout<<"the max area = "<<ans1<<endl;

    return 0;
}