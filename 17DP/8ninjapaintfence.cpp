#include <bits/stdc++.h> 
#define MOD 1000000007

int add(int a,int b){
    return ( (a%MOD)+(b%MOD))%MOD;
}

int mul(int a ,int b){
    return ((a%MOD)*1LL*(b%MOD))%MOD;
    
}

// int solveRec(int n, int k){
//     if(n==1){
//         return k;
//     }
//     if(n==2){
//         return k*k;
//     }
    
    
//     int ans= add(mul(solveRec(n-2,k),k-1),mul(solveRec(n-1,k),k-1));

//     return ans;

    
// }

// int solveMem(int n, int k,vector<int> &dp){
//     if(n==1){
//         return k;
//     }
//     if(n==2){
//         return k*k;
//     }
//     if(dp[n]!=-1){
//         return dp[n];
//     }
    
//     dp[n]= add(mul(solveMem(n-2,k,dp),k-1),mul(solveMem(n-1,k,dp),k-1));

//     return dp[n];

    
// }


int solveTab(int n, int k){
    vector<int> dp(n+1,0);
    
   long long int  prev2=k;
    long long int prev1=add(k,mul(k,k-1));
    
    for(int i=3;i<=n;i++){
        long long int temp =add (mul(prev2,k-1)%MOD,mul(prev1,k-1) %MOD) %MOD;
        prev2=prev1;
        prev1=temp;
    }
    return prev1;
}


int numberOfWays(int n, int k) {
    // Write your code here.
    // int ans=solveRec(n,k);
    // return ans;

    // vector<int> dp(n+1,-1);
    // return solveMem(n,k,dp);

    int ans=solveTab( n, k);
    return ans;
    
}