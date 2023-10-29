class Solution {
private:
    int solve(vector<int> &arr,int diff, int curr, int prev){

        if(curr==arr.size()){
            return 0;
        }

        int count=0;

        if(prev==-1 || arr[curr]-arr[prev]==diff){
            count=1+solve(arr,diff,curr+1,curr);
        }

        return max(count, solve(arr,diff,curr+1,prev));

    }
    int solveMem(vector<int> &arr,int diff, int curr, int prev,vector<vector<int>> &dp){

        if(curr==arr.size()){
            return 0;
        }

        if(dp[curr][prev+1]!=-1){
            return dp[curr][prev+1];
        }


        int take=INT_MIN;


        if(prev==-1 || arr[curr]-arr[prev]==diff){
            take=1+solveMem(arr,diff,curr+1,curr,dp);
        }

        int notTake=solveMem(arr,diff,curr+1,prev,dp);
        return dp[curr][prev+1]= max(take,notTake );

    }

    int solveTab(vector<int> &arr, int diff){

    if (arr.empty()) {
        return 0;
    }

    int n = arr.size();
    int count = 0;

  
    unordered_map<int, int> dp;

    for(int i=0;i<n;i++){
       
        if (dp.count(arr[i] - diff)) {
            dp[arr[i]] = dp[arr[i] - diff] + 1;
        } 
        else {
            dp[arr[i]] = 1;
        }

      
        count = max(count, dp[arr[i]]);
    }

    return count;
}


public:
    int longestSubsequence(vector<int>& arr, int difference) {
        
        return solve(arr,difference, 0 ,-1);


        int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solveMem(arr,difference, 0 ,-1,dp);

        return solveTab(arr,difference);
    }
};