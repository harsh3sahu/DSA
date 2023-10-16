#include <bits/stdc++.h> 

int solveRec(vector<int> &weight, vector<int> &value, int index, int capacity){
	
	if(index==0){
		if(weight[0]<=capacity){
			return value[0];
		}
		return 0;
	}

	int include=0;

	if(weight[index]<=capacity){
		include= value[index]+solveRec(weight,value,index-1,capacity-value[index]);
	}

	int exclude=0+solveRec(weight,value,index-1,capacity);

	int ans=max(include,exclude);
	return ans;

}
int solveMem(vector<int> &weight, vector<int> &value, int index, int capacity,vector<vector<int>>&dp){
	
	if(index==0){
		if(weight[0]<=capacity){
			return value[0];
		}
		return 0;
	}

	if(dp[index][capacity]!=-1){
		return dp[index][capacity];
	}

	int include=0;

	if(weight[index]<=capacity){
		include= value[index]+solveMem(weight,value,index-1,capacity-weight[index],dp);
	}

	int exclude=0+solveMem(weight,value,index-1,capacity,dp);

	dp[index][capacity]=max(include,exclude);
	return dp[index][capacity];

}

int solveTab(vector<int> &weight,vector<int> &value,int index, int capacity){

	vector<vector<int>> dp(n,vector<int>(capacity+1,0));
	
	




}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	// recursion
	return solveRec(weight,value,n-1,maxWeight);

	// memoization
	vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
	return solveMem(weight,value,n-1,maxWeight,dp);


	solveTab(weight,value,n,maxWeight);

}