class Solution {

private:
    int solve(int k , vector<int>& prices , int index, int buy, vector<vector<vector<int>>>& dp){
        if(index==prices.size() || k<=0){
            return 0;
        }

        if(dp[index][k][buy]!=-1){
            return dp[index][k][buy];
        }

        int profit=0;

        if(buy){
            profit=max( -prices[index] + solve(k,prices,index+1,0,dp) , 0+solve(k,prices,index+1,1,dp));
        }
        else{
            profit=max( prices[index] + solve(k-1,prices,index+1,1,dp) , 0+solve(k,prices,index+1,0,dp));
        }
        return dp[index][k][buy]=profit;
    }

    int solveTab(int K ,vector<int> &prices){
        int n=prices.size();

        vector<vector<int>> curr(k+1,vector<int>(2,0));
        vector<vector<int>> prev(k+1,vector<int>(2,0));


        for(int index=n-1;index>=0;index--){
            for(int k=K, k>)
        }




    // }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(k+1,vector<int>(2,-1)));
        // vector<vector<int>> curr(k,vector<int> (2,-1))
        return solve(k,prices, 0,1,dp);
    }
};