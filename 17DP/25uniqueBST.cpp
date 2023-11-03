class Solution {

private:
    // int solve(int n,vector<int> &dp){

    //     if(n<=1){
    //         return 1;
    //     }
    //     if(dp[n]!=-1){
    //         return dp[n];
    //     }
    //     int ans=0;
    //     for(int i=1;i<=n;i++){
    //         ans = ans + (solve(n-i,dp)*solve(i-1,dp));
    //     }

    //     return dp[n]= ans;
    // }

    int solveTab(int nums){
        vector<int> dp(nums+1,1);

        for(int n=1;n<=nums;n++){


            int ans=0;
            for(int i=1;i<=n;i++){
            ans = ans + (dp[n-i]*dp[i-1]);
            }

            dp[n]= ans;

        }

        return dp[nums];
    }
public:
    int numTrees(int n) {
        // vector<int> dp(n+1,-1);
        // return solve(n,dp);
        
        return solveTab(n);
    }
};