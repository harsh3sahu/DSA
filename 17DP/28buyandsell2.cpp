class Solution {
private:
    // int solve( int index, int buy, vector<int> &prices , vector<vector<int>> &dp){
    //     if(index==prices.size()){
    //         return 0;
    //     }

    //     if(dp[index][buy]!=-1){
    //         return dp[index][buy];
    //     }

    //     int profit=0;
    //     if(buy){
    //         profit=max(-prices[index]+solve(index+1,0,prices,dp), 0+solve(index+1,1,prices,dp));
    //     }
    //     else{
    //         profit=max(prices[index]+solve(index+1,1,prices,dp), 0+solve(index+1,0,prices,dp));
    //     }

    //     return dp[index][buy]=profit;
    // }

    int solveTab(vector<int> &prices){
        // int n=prices.size();
        // vector<vector<int>> dp(n+1,vector<int> (2,0));
        int nextbuy=0;
        int nextleft=0;

        for(int index=prices.size()-1;index>=0;index--){

            for(int buy=0;buy<=1;buy++){

            int profit=0;
            if(buy){
            profit=max(-prices[index]+nextleft, 0+nextbuy);
            nextbuy=profit;
             }
            else{
            profit=max(prices[index]+nextbuy, 0+nextleft);
            nextleft=profit;
             }

             
            }

            
            
        }

    return nextbuy;   
    }
public:
    int maxProfit(vector<int>& prices) {
        // int n=prices.size();
        // vector<vector<int>> dp(n+1,vector<int>(2,-1));
        // return solve(0,1,prices,dp);

        return solveTab(prices);
        
    }
};