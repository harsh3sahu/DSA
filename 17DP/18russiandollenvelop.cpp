class Solution {
private:
    int solve(vector<vector<int>> &env, int curr, int prev, int n){

        if(curr==n){
            return 0;
        }
        
        int incl=0;
        if(prev==-1 || (env[prev][0]<env[curr][0]  && env[prev][1]<env[curr][1])){
            incl=1+solve(env,curr+1,curr,n);
        }

        int excl=0+solve(env,curr+1,prev,n);

        return max(incl,excl);

    }
    int solveMem(vector<vector<int>> &env, int curr, int prev, int n,vector<vector<int>>&dp){

        if(curr==n){
            return 0;
        }

        if(dp[curr][prev+1]!=-1){
            return dp[curr][prev+1];
        }
        
        int incl=0;
        if(prev==-1 || (env[prev][0]<env[curr][0]  && env[prev][1]<env[curr][1])){
            incl=1+solveMem(env,curr+1,curr,n,dp);
        }

        int excl=0+solveMem(env,curr+1,prev,n,dp);

        return dp[curr][prev+1]=max(incl,excl);

    }

  
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        for( auto a: envelopes){
            sort(a.begin(), a.end());
        }

        sort(envelopes.begin(),envelopes.end());
        int n=envelopes.size();
        
        return solve(envelopes,0,-1,n);

        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solveMem(envelopes,0,-1,n,dp);

        
    }
};