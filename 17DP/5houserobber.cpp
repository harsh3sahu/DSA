https://www.codingninjas.com/studio/problems/house-robber_839733?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar


#include <bits/stdc++.h> 

long long int solveTab(vector<int>& value){
    int n=value.size();
    if(n==0) return 0;
    if(n==1) return value[0];

    vector<long long int> dp(n,0);
    dp[0]=value[0];
    dp[1]=max(value[0],value[1]);

    for(int i=2;i<n;i++){
        long long int incl=dp[i-2]+value[i];
        long long int excl=dp[i-1];

        dp[i]=max(incl,excl);
    }

    return dp[n-1];
}
long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    vector<int> first,second;
    int n=valueInHouse.size();
    if(n==0){
        return 0;
    }
    if(n==1){
        return valueInHouse[0];
    }
    for(int i=0;i<n;i++){
        if(i!=0){
            second.push_back(valueInHouse[i]);
        }
        if(i!=n-1){
            first.push_back(valueInHouse[i]);
        }

    }

    long long int ans =max(solveTab(first),solveTab(second));

    return ans;

}
