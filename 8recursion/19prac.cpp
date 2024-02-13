#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool isSafe(vector<vector<int>> m, int x, int y, vector<vector<int>> visited, int n){
    if(x>=0 && x<n && y>=0 && y<n && visited[x][y]==0 && m[x][y]==1){
        return true;
    }
    else return false;
}

void solve(vector<vector<int>> &m, string output, vector<string> &ans, int x, int y,int n,vector<vector<int>> visited){
    if(x==n-1 && y==n-1){
        ans.push_back(output);
        return;
    }

    visited[x][y]=1;
    

    //down
    int newx=x+1;
    int newy=y;
    if(isSafe(m,newx,newy,visited,n)){
        output.push_back('D');
        solve(m,output,ans,newx,newy,n,visited);
        output.pop_back();
    }

    //right
     newx=x;
     newy=y+1;
    if(isSafe(m,newx,newy,visited,n)){
        output.push_back('R');
        solve(m,output,ans,newx,newy,n,visited);
                output.pop_back();

    }


    //left
     newx=x;
     newy=y-1;
    if(isSafe(m,newx,newy,visited,n)){
        output.push_back('L');
        solve(m,output,ans,newx,newy,n,visited);
                output.pop_back();

    }

    //up
     newx=x-1;
     newy=y;
    if(isSafe(m,newx,newy,visited,n)){
        output.push_back('U');
        solve(m,output,ans,newx,newy,n,visited);
                output.pop_back();

    }



    visited[x][y]=0;

}




int main(){

    int n;
    cout<<"enter size of maze\n";
    cin>>n;

    vector<vector<int>> m(n,vector<int>(n,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>m[i][j];
        }
    }

    vector<vector<int>> visited(n,vector<int> (n,0));

    string output="";
    vector<string> ans;
    int i=0;
    int j=0;


    solve(m,output,ans,i,j,n,visited);


    for(auto i:ans){
        cout<<i<<endl;
    }


    return 0;
}