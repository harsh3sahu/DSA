class Solution {
private:
    // int solve(vector<int> &slices, int n, int index, int endIndex){

    //     if(n==0 || index>endIndex){
    //         return 0;
    //     }

    //     int take=slices[index]+solve(slices,n-1,index+2,endIndex);

    //     int notTake=solve(slices,n,index+1,endIndex);

    //     return max(take,notTake);

    // }

    int solveMem(vector<int> &slices, int n, int index, int endIndex, vector<vector<int>> &dp){

        if(n==0 || index>endIndex){
            return 0;
        }

        if(dp[index][n]!=-1){
            return dp[index][n];
        }

        int take=slices[index]+solveMem(slices,n-1,index+2,endIndex,dp);

        int notTake=solveMem(slices,n,index+1,endIndex,dp);

        return dp[index][n]=max(take,notTake);

    }
public:
    int maxSizeSlices(vector<int>& slices) {
        int n= slices.size() ;

        // int case1= solve(slices,n/3,0,n-2);
        // int case2=solve(slices,n/3,1,n-1);

        // return max(case1,case2);

        vector<vector<int>> dp1(n,vector<int>(n,-1));
        vector<vector<int>> dp2(n,vector<int>(n,-1));

        
        int case1= solveMem(slices,n/3,0,n-2,dp1);
        int case2=solveMem(slices,n/3,1,n-1,dp2);

        return max(case1,case2);
    }
};