#include<iostream>
#include<stack>
#include<vector>

using namespace std;

void nextMin(vector<int> &num, vector<int> &ans, int size){
    stack<int> s;
    s.push(-1);

    for(int i=size-1;i>=0;i--){
        int curr= num[i];

        while(!s.empty() && curr<=s.top()){
            s.pop();
        }

        ans[i]=s.top();
        s.push(curr);

    }


    return ;

}

int main(){


    int size;
    cout<<"enter size of array\n";
    cin>>size;

    vector<int> numbers(size);
    for(int i=0;i<size;i++){
        cin>>numbers[i];
    }

    vector<int> ans(size);
    nextMin(numbers, ans, size);
    for(auto i: ans){
        cout<<i<<endl;
    }




    return 0;
}