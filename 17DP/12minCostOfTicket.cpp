https://www.codingninjas.com/studio/problems/minimum-coins_2180776?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar


int solveRec(int n,vector<int> &days, vector<int> &cost , int index){

    if(index>=n){
        return 0;
    }


    int op1=cost[0]+solveRec(n,days,cost,index+1);
    
    int i;
    for(i=index;i<n && days[i]<days[index]+7;i++);
    int op2=cost[1]+solveRec(n,days,cost,i);

    for(i=index;i<n && days[i]<days[index]+30;i++);
    int op3=cost[2]+solveRec(n,days,cost,i);
    
    return min(op1,min(op2,op3));


}

int solveMem(int n,vector<int> &days, vector<int> &cost,vector<int>&dp , int index){

    if(index>=n){
        return 0;
    }

    if(dp[index]!=INT_MAX){
        return dp[index];
    }


    int op1=cost[0]+solveMem(n,days,cost,dp,index+1);
    
    int i;
    for(i=index;i<n && days[i]<days[index]+7;i++);
    int op2=cost[1]+solveMem(n,days,cost,dp,i);

    for(i=index;i<n && days[i]<days[index]+30;i++);
    int op3=cost[2]+solveMem(n,days,cost,dp,i);
    
    int mini= min(op1,min(op2,op3));
    dp[index]=min(mini,dp[index]);

    return dp[index];
}

int solveTab(int n, vector<int> &days, vector<int> &cost){
    vector<int> dp(n+1,INT_MAX);
    dp[n]=0;

    for(int index=n-1;index>=0;index--){
        int op1=cost[0]+dp[index+1];
    
        int i;
        for(i=index;i<n && days[i]<days[index]+7;i++);
        int op2=cost[1]+dp[i];

        for(i=index;i<n && days[i]<days[index]+30;i++);
        int op3=cost[2]+dp[i];
    
        dp[index]=min(op1,min(op2,op3));
    }


    return dp[0];

}


int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    // Write your code here.
    return solveRec(n,days,cost,0);

    vector<int> dp(n+1,INT_MAX);
    return solveMem(n,days,cost,dp,0);

    return solveTab(n,days,cost);
}