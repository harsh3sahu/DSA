class Solution{   
private:
    int solve(int n, int a[], int index, int diff){
        if(index<0){
            return 0;
        }
        int ans=0;
        
        for(int j=index-1;j>=0;j--){
            if(a[index]-a[j]==diff){
                ans=max(ans, 1+solve(n,a,j,diff));
            }
        }
        return ans;
    }
public:
    int lengthOfLongestAP(int A[], int n) {
        
        if(n<=2){
            return n;
        }
        // code here
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                ans=max(ans,2+solve(n,A,i,A[j]-A[i]));
            }
        }
        return ans;
    }


    // tabular 


        if(n<=2){
            return n;
        }
        int x=A[n-1]-A[0]+1;
        int ans=0;
        vector<vector<int>> dp(n+1,vector<int>(x,-1));
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int diff=A[i]-A[j];
                int cnt=1;
                
                if(dp[j][diff]!=-1){
                    cnt=dp[j][diff];
                }
                
                
                dp[i][diff]=1+cnt;
                ans=max(ans,dp[i][diff]);
                
            
            }
        }
        
        return ans;
};