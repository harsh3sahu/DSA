#include <bits/stdc++.h> 
int solve(vector<int>&num, int tar){

    if(tar==0){
        return 1;
    }
    if(tar<0 ){
        return 0;
    }
    int ans=0;
    for(int i=0;i<num.size();i++){
        ans=ans+solve(num,tar-num[i]);
    }

    return ans;
    
}

int solveMem(vector<int> num, int tar,vector<int> &dp){

    if(tar==0){
        return 1;
    }
    if(tar<0){
        return 0;
    }
    if(dp[tar]!=-1){
        return dp[tar];
    }
    int ans=0;

    for(int i=0;i<num.size();i++){
        ans=ans+solveMem(num,tar-num[i],dp);    
    }
    dp[tar]=ans;
    return dp[tar];


}

int solveTab(vector<int>&num,int tar){

    vector<int>dp(tar+1,0);

    dp[0]=1;

    for(int j=1;j<=tar;j++){

        for(int i=0;i<num.size();i++){
            if(j-num[i]>=0){
            dp[j]+=dp[j-num[i]];
            }
        }

    }

    return dp[tar];



}
int findWays(vector<int> &num, int tar)
{
    Write your code here.
    int size=num.size()-1;
    return  solve(num,tar);

    vector<int> dp(tar+1,-1);
    return solveMem(num,tar,dp);

    return solveTab(num,tar);
}