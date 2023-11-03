class Solution {
private:
    int solveTab(vector<int> &prices, int fee){
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
            profit=max(prices[index]+nextbuy-fee , 0+nextleft);
            nextleft=profit;
             }

             
            }

            
            
        }

    return nextbuy;   
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        
        return solveTab(prices,fee);
    }
};