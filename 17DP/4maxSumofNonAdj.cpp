#include <bits/stdc++.h> 

int solveRec(vector<int>&nums, int i,int n){
    if(i>n){
        return 0;
    }
    if(i==n){
        return nums[n];
    }

    int incl=solve(nums,i+2,n)+nums[i];
    int excl=solve(nums,i+1,n)+0;

    return max(incl,excl);

}

int solveMem(vector<int>&nums, vector<int>&dp, int i){
    if(i<0){
        return 0;
    }
    if(i==0){
        return nums[0];
    }
    if(dp[i]!=-1){
        return dp[i];

    }

    int incl=solveMem(nums,dp,i-2)+nums[i];
    int excl=solveMem(nums,dp,i-1)+0;

    dp[i]=max(incl,excl);

    return dp[i];



}

int solveTab(vector<int>&nums){
    int n=nums.size();
    vector<int> dp(n,0);

    dp[0]=nums[0];

    for(int i=1;i<n;i++){
       
         int incl=dp[i-2]+nums[i];
        
        int excl=dp[i-1]+0;
        dp[i]=max(incl,excl);
    }

    return dp[n-1];

}


int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.

    //  recursion
    int n=nums.size();
    return solveRec(nums,0,n-1);

    // memoization
    int n=nums.size();
    vector<int> dp(n,-1);
    return solveMem(nums,dp,n-1);


    // tab
    return solveTab(nums);



}