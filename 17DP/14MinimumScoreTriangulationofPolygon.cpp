class Solution {
private:
int solve(vector<int> &v, int i ,int j,vector<vector<int>>&dp){
    if(i+1==j){
        return 0;
    }

    if(dp[i][j]!=INT_MAX){
        return dp[i][j];
    }

    
    for(int k=i+1;k<j;k++){
        dp[i][j]=min(dp[i][j],v[i]*v[k]*v[j] + solve(v,i,k,dp)+ solve(v,k,j,dp));
    }

    return dp[i][j];

}

public:
    int minScoreTriangulation(vector<int>& values) {
       

        vector<vector<int>> dp(values.size(),vector<int>(values.size(),INT_MAX));
        return solve(values, 0 ,values.size()-1,dp);
        
    }
};