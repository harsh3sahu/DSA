#include<iostream>
#include<vector>

using namespace std;


int main(){

    vector<int> dp(5,0);

    for(int i=1;i<5;i++){
        cout<<dp[i-2]<<endl;
        
    }





    return 0;
}