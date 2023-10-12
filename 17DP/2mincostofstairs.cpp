class Solution {
    private:
    int solve(vector<int> &cost,int n,vector<int> &prevTotal){
        if(n==0){
            return cost[0];
        }
        if(n==1){
            return cost[1];
        }
        if(prevTotal[n]!=-1){
            return prevTotal[n];
        }

        prevTotal[n]=cost[n]+ min(solve(cost,n-1,prevTotal),solve(cost,n-2,prevTotal));
        return prevTotal[n];
    }
    int solve2(vector<int>&cost){
        int n=cost.size();
        vector<int> dp(n);

        dp[0]=cost[0];
        dp[1]=cost[1];

        for(int i=2;i<n;i++){
            dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        }

        return min(dp[n-1],dp[n-2]);



    }

    int solve3(vector<int>&cost){
        int n=cost.size();

        int prev2=cost[0];
        int prev1=cost[1];

        for(int i=2;i<n;i++){
            int temp= cost[i]+min(prev1,prev2);

            prev2=prev1;
            prev1=temp;
        }

        return min(prev1,prev2);



    }

public:
    int minCostClimbingStairs(vector<int>& cost) {

        int n=cost.size();
        vector<int> prevTotal(n,-1);

        int ans=min(solve(cost,n-1,prevTotal),solve(cost,n-2,prevTotal));
        return solve2(cost);

        return solve3(cost);
        
    }
};