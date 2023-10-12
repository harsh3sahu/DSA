#include<iostream>
#include<vector>
#include<stack>

using namespace std;



int main(){

    int s;
    cout<<"enter number of bars i.e. size of array\n";
    cin >>s;

    vector<int> bar(s);

    for(int i=0;i<s;i++){
        cin>>bar[i];
    }

    int ans;

    ans=maxArea(bar,s);


    cout<<"the maximum possible area is "<<ans<<endl;

    return 0;
}