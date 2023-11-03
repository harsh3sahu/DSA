class Solution {
private:
    // int solve(string& text1, string& text2, int index1 , int index2,vector<vector<int>>& dp){
    //     if(index1==text1.length() || index2==text2.length()){
    //         return 0;
    //     }
    //     if(dp[index1][index2]!=-1){
    //         return dp[index1][index2];
    //     }
    //     int ans=0;
    //     if(text1[index1]==text2[index2]){
    //         ans = 1+solve(text1,text2,index1+1, index2+1,dp);
    //     }
    //     else{
    //         ans = max( solve(text1,text2,index1+1, index2,dp), solve(text1,text2,index1,index2+1,dp)  );
    //     }
        

    //     return dp[index1][index2]=ans;
    // }

    int solveTab(string& text1 , string& text2){

        // vector<vector<int>> dp(text1.length()+1,vector<int>(vector<int>(text2.length()+1,0)));

        int n=max(text1.length(), text2.length());

        vector<int>next(n+1,0);
        vector<int> curr(n+1,0);

        for(int index1=text1.length()-1; index1>=0;index1--){
            for(int index2=text2.length()-1; index2>=0; index2--){

                int ans=0;
                if(text1[index1]==text2[index2]){
                    ans = 1+next[index2+1];
                }
                else{
                    ans = max(next[index2], curr[index2+1]  );
                }
        
                curr[index2]=ans;
            }
            next=curr;
        }

        return curr[0];

    }
public:
    int longestCommonSubsequence(string text1, string text2) {

        // vector<vector<int>> dp(text1.length(),vector<int>(text2.length(),-1));

        // return solve(text1,text2,0,0,dp);

        return solveTab(text1, text2);
        
    }
};