class Solution {
private:
    int solveMem(vector<int> &obstacles, int pos, int currLane, int &n,vector<vector<int>> &dp){
        if(pos==n){
            return 0;
        }

        if(dp[pos][currLane]!=-1){
            return dp[pos][currLane];
        }

        if(obstacles[pos+1]!=currLane){
            dp[pos][currLane]= solveMem(obstacles,pos+1,currLane,n,dp);
            return dp[pos][currLane];
        }

        
        else {
                    int ans=INT_MAX;

            for(int i=1;i<=3;i++){
                if(obstacles[pos]!=i && currLane!=i){
                    ans=min(ans,1+solveMem(obstacles,pos,i,n,dp));
                }
            }
            dp[pos][currLane]=ans;
            return dp[pos][currLane];
        }
        
    }

    int solveTab(vector<int> &obstacles){
        int n=obstacles.size()-1;
        vector<vector<int>> dp(n+1,vector<int>(4,INT_MAX));

        dp[n][1]=0;
        dp[n][2]=0;
        dp[n][3]=0;

        for(int pos=n-1;pos>=0;pos--){

        for(int currLane=1;currLane<=3;currLane++){
            if(obstacles[pos+1]!=currLane){
            dp[pos][currLane]= dp[pos+1][currLane];
        }

        else{
            int ans=1e9;

            for(int i=1;i<=3;i++){
                if(obstacles[pos]!=i && currLane!=i){
                    ans=min(ans,1+dp[pos+1][i]);

                }

            }
            dp[pos][currLane]=ans;

        }
        }
        }


        

        
        return min(dp[0][2], min(dp[0][1]+1, dp[0][3]+1));

    }


    int solve(vector<int> &obstacles, int pos, int currLane, int &n){
        if(pos==n){
            return 0;
        }

        if(obstacles[pos+1]!=currLane){
            return solve(obstacles,pos+1,currLane,n);
        }
        else {
                    int ans=INT_MAX;

            for(int i=1;i<=3;i++){
                if(obstacles[pos]!=i && currLane!=i){
                    ans=min(ans,1+solve(obstacles,pos,i,n));
                }
            }
            return ans;
        }
        
    } 

public:
    int minSideJumps(vector<int>& obstacles) {
        int n=obstacles.size()-1;
        vector<vector<int>> dp(n,vector<int>(4,-1));
        return solveMem(obstacles,0,2,n,dp);


        return solveTab(obstacles);
    }
};