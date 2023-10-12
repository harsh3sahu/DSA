
// https://www.codingninjas.com/studio/problems/sudoku-solver_699919?leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

#include <bits/stdc++.h> 


void adSolution(vector<vector<int>> &board, vector<vector<int>> &ans, int n){
	vector<int> temp;
	for(int row=0;row<n;row++){
		for(int col=0;col<n;col++){
			temp.push_back(board[row][col]);
		}
	}

	ans.push_back(temp);
	
}

bool isSafe(int row, int col, vector<vector<int>> board, int n){

	int x=row;
	int y=col;

	while(y>=0){
		if(board[x][y]==1){
			return false;
		}
		y--;
	}

	x=row;
	y=col;
	while(x>=0 && y>=0){
		if(board[x][y]==1){
			return false;
		}
		x--;
		y--;
	}

	x=row;
	y=col;
	while(y>=0 && x<n){
		if(board[x][y]==1){
			return false;
		}
		x++;
		y--;
	}

	return true;

}

void solve(int col, int n, vector<vector<int>> &board, vector<vector<int>> &ans){
	if(col==n){
		adSolution(board, ans, n);
		return ;
	}



	for(int row=0;row<n;row++){

		if(isSafe(row, col,board,n)){
			board[row][col]=1;

			solve(col+1,n,board,ans);

			board[row][col]=0;
		}
	}
}

vector<vector<int>> nQueens(int n)
{
	// Write your code here
	vector<vector<int>> board(n, vector<int>(n,0));
	vector<vector<int>> ans;

	solve(0,n,board,ans);

	return ans;
	
}