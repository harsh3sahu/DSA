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
        
    //     vector<int> currRow(n+1,0);
    //     vector<int>nextRow(n+1,0);
        
    //     for(int curr=n-1;curr>=0;curr--){
    //         for(int prev=curr-1;prev>=-1;prev--){
                
    //             int incl=0;
        
    //             if(prev==-1 || a[prev]<a[curr]){
    //              incl=1+nextRow[curr+1];
    //               }
        
    //             int excl=0+nextRow[prev+1];
        
    //           currRow[prev+1]= max(incl,excl);
                
    //           }
    //           nextRow=currRow;
            
            
    //     }
        
    //     return nextRow[0];
        
    // }
    
    //   int solveSpace(int n,int a[])
    // {
    //     vector<int> curr(n+1,0);
    //     vector<int> next(n+1,0);
        
    //     for(int i=n-1;i>=0;i--)
    //     {
    //         for(int j=i-1;j>=-1;j--)
    //         {
    //             int include=0;
    //             if(j==-1 || a[i]>a[j])
    //                 include=1+next[i+1];
    //             int exclude=next[j+1];
                
    //             curr[j+1]=max(include,exclude);
    //         }
    //         next=curr;
    //     }
    //     return next[0];
    // }
    
    int solveOpt(int n, int a[]){
        if(n==0){
            return 0; 
        }
        
        vector<int> ans;
        ans.push_back(a[0]);
        
        for(int i=0;i<n;i++){
            if(ans.back()<a[i]){
                ans.push_back(a[i]);
            }
            
            else{
                
                
                int index=lower_bound(ans.begin() , ans.end(),a[i])-ans.begin();
                ans[index]=a[i];
            }
            }
        
        
        return ans.size();
        
        
    }
    

    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {   
        
       // your code here
       //   return solve(n,a,0,-1);
       
    //   vector<vector<int>> dp(n,vector<int>(n+1,-1));
    //   return solveMem(n,a,0,-1,dp);


        // return solveTab(n,a);       
        // return solveSpace(n,a);
        
        return solveOpt(n,a);
    }
};