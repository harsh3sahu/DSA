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

int solveTab(vector<int> &v){
    int n=v.size();
    vector<vector<int>>dp (n,vector<int>(n));

    for(int j=2;j<n;j++){
        for(int i=j-2;i>=0;--i){
            dp[i][j]=INT_MAX;

            for(int k=i+1;k<j;k++){
                dp[i][j]=min(dp[i][j], v[i]*v[k]*v[j] + dp[i][k]+ dp[k][j]);
            }
        }
    }

    return dp[0][n-1];


}
public:
    int minScoreTriangulation(vector<int>& values) {
       

        vector<vector<int>> dp(values.size(),vector<int>(values.size(),INT_MAX));
        return solve(values, 0 ,values.size()-1,dp);

        return solveTab(values);
        
    }
};