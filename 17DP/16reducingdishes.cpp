#include<limits.h>
class Solution {
private:
    int solve(vector<int> &sat, int n , int index,int time){
        if(index==n){
            return 0;
        }

        int incl= (sat[index] * (time+1))+ solve(sat,n,index+1,time+1);
        int excl=0+solve(sat,n,index+1,time);

        return max(incl,excl);

    }
    int solveMem(vector<int> &sat, int n , int index,int time,vector<vector<int>> &dp){
        if(index==n){
            return 0;
        }

        if(dp[index][time]!=-1){
            return dp[index][time];
        }

        int incl= (sat[index] * (time+1))+ solveMem(sat,n,index+1,time+1,dp);
        int excl=0+solveMem(sat,n,index+1,time,dp);

        dp[index][time]= max(incl,excl);
        return dp[index][time];

    }

    int solveTab(vector<int>&sat){
        int n=sat.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        

        for(int index=n-1;index>=0;index--){
            for(int time=index;time>=0;time--){
                int incl= (sat[index] * (time+1))+ dp[index+1][time+1];
                int excl=0+dp[index+1][time];

                dp[index][time]=max(incl,excl);
            }
        }

        return dp[0][0];

    }
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort (satisfaction.begin(),satisfaction.end());
        int n=satisfaction.size();
    

        return solve(satisfaction,n,0,0);

        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solveMem(satisfaction,n,0,0,dp);

        return solveTab(satisfaction);


    }
};