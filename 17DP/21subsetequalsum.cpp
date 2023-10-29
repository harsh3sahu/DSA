
class Solution{
    
private:
    // bool solve(int n, int arr[],int sum){
        
    //     if(sum==0 ){
    //         return true;
    //     }
    //     if(n==0 && sum!=0){
    //         return false;
    //     }
        
    //     if(arr[n]>sum){
    //         return solve(n-1,arr,sum);
    //     }
        
    //     return solve(n-1,arr,sum) || solve(n-1,arr,sum-arr[n]);
        
        
    // }
    
    // bool solveMem(int n, int arr[],int sum, vector<vector<int>> &dp){
        
    //     if(sum==0 ){
    //         return true;
    //     }
    //     if(n==0 && sum!=0){
    //         return false;
    //     }
    //     if(dp[n][sum]!=-1){
    //         return dp[n][sum];
    //     }
    //     if(arr[n]>sum){
    //         return solveMem(n-1,arr,sum,dp);
    //     }
        
    //     dp[n][sum]= solveMem(n-1,arr,sum,dp) || solveMem(n-1,arr,sum-arr[n],dp);
    //     return dp[n][sum];
        
    // }
    
    bool solveTab(int N, int arr[], int SUM){
        vector<vector<bool>> dp(N+2, vector<bool> (SUM+2,false));
        
        for(int i=0;i<N;i++){
            dp[i][0]=true;
        }
        
        for(int sum=1;sum<=SUM;sum++){
            for (int n=1;n<=N;n++){
                
                dp[n][sum]=dp[n-1][sum];
                
                if(arr[n-1]<=sum){
                    
                    dp[n][sum]= dp[n][sum] || dp[n-1][sum-arr[n-1]];
                }
                
                
                
            }
                
                
                        
            }
            
        return dp[N][SUM];
    }
        
        
        
    
    
    
    
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<N;i++){
            sum=sum+arr[i];
        }
        
        // if(sum%2==0){
        //     if( solve(N-1,arr,sum/2)){
        //         return true;
        //     }
            
        // }
        // return false;
        
        
        // vector<vector<int>> dp(N+1, vector<int> ((sum/2 )+1,-1));
        //  if(sum%2==0){
        //     if( solveMem(N-1,arr,sum/2,dp)){
        //         return true;
        //     }
            
        // }
        // return false;
        
        if(sum%2==0){
        
       return solveTab(N,arr,sum/2);
            
        }
       return false;
    }
};