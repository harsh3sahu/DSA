class Solution
{
    private:
    // int solve(int n,int a[], int curr, int prev){
    //     if(curr==n){
    //         return 0;
    //     }
    //     int incl=0;
    //     if(prev==-1 || a[prev]<a[curr]){
    //          incl=1+solve(n,a,curr+1,curr);
    //     }
        
    //     int excl=0+solve(n,a,curr+1,prev);
        
    //     return max(incl,excl);
        
    // }
    
    // int solveMem(int n,int a[], int curr, int prev,vector<vector<int>> &dp){
    //     if(curr==n){
    //         return 0;
    //     }
        
    //     if(dp[curr][prev+1]!=-1){
    //         return dp[curr][prev+1];
    //     }
        
    //     int incl=0;
        
    //     if(prev==-1 || a[prev]<a[curr]){
    //          incl=1+solveMem(n,a,curr+1,curr,dp);
    //     }
        
    //     int excl=0+solveMem(n,a,curr+1,prev,dp);
        
    //     // dp[curr][prev+1]= max(incl,excl);
    //     return dp[curr][prev+1]= max(incl,excl);
        
    // }
    
    // int solveTab(int n , int a[]){
        
    //     vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
        
    //     for(int curr=n-1;curr>=0;curr--){
    //         for(int prev=curr-1;prev>=-1;prev--){
                
    //             int incl=0;
        
    //             if(prev==-1 || a[prev]<a[curr]){
    //              incl=1+dp[curr+1][curr+1];
    //               }
        
    //             int excl=0+dp[curr+1][prev+1];
        
    //           dp[curr][prev+1]= max(incl,excl);
                
    //           }
            
            
    //     }
        
    //     return dp[0][0];
        
    // }
    
    int solveTab(int n, int a[]) {
  vector<int> dp(n + 1);

  for (int curr = n - 1; curr >= 0; curr--) {
    int prevIncl = dp[curr + 1];
    int prevExcl = dp[curr];

    for (int prev = curr - 1; prev >= -1; prev--) {
      int incl = 0;
      if (prev == -1 || a[prev] < a[curr]) {
        incl = 1 + dp[curr + 1];
      }

      int excl = 0 + dp[prev + 1];

      dp[prev + 1] = max(incl, excl);
    }
  }

  return dp[0];
}
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {   
        
       // your code here
       //   return solve(n,a,0,-1);
       
    //   vector<vector<int>> dp(n,vector<int>(n+1,-1));
    //   return solveMem(n,a,0,-1,dp);


        return solveTab(n,a);       
    }
};