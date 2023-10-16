https://practice.geeksforgeeks.org/problems/get-minimum-squares0538/1


class Solution{
    private:
    int solveRec(int n){
        if(n==0){
            return 0;
        }
        
        int ans=n;
        for(int i=1;i*i<=n;i++){
            ans=min(ans,solveRec(n-i*i));
        }
        
        return ans;
    }
    
    int solveMem(int n,vector<int>&dp){
        if(n==0){
            return 0;
        }
        
        if(dp[n]!=-1){
            return dp[n];
        }
        int ans=n;
        for(int i=1;i*i<=n;i++){
            ans=min(ans,1+solveMem(n-(i*i),dp));
        }
        
        dp[n]=ans;
        return dp[n];

    }
    
    int solveTab(int n){
        vector<int> dp(n+1,INT_MAX);
        
        dp[0]=0;
        
        for(int i=1;i<=n;i++){
            
            for(int j=1;j*j<=i;j++){
                dp[i]=min(dp[i],dp[i-(j*j)]+1);
            }
            
        }
        return dp[n];
        
    }
    
    
    
    
	public:
	int MinSquares(int n)
	{
	    // Code here
	    
	   return solveRec(n);
	    
	   vector<int> dp(n+1,-1);
	   return solveMem(n,dp);
	   
	   return solveTab(n);
	    
	}
};