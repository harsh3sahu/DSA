#include<iostream>
#include<vector>

using namespace std;

class solution{

    private:

    bool isSafe(vector<vector<int>>& m,int n, int x, int y, vector<vector<int>>& visit){
        if( ((x>=0) && (x<n)) && (y>=0 && y<n) && visit[x][y]==0 && m[x][y]==1){
            return true;
        }
        else return false;
    }

    void solve(vector<vector<int>>& m, int n, int x, int y, vector<string>& ans, string path, vector<vector<int>>& visit){
        if(x==n-1 && y==n-1){
            ans.push_back(path);
            return ;
        }

        visit[x][y]=1;
        // down
        int newx=x+1;
        int newy=y;
        if(isSafe(m,n,newx,newy,visit)){
            path.push_back('D');
            solve(m,n,newx,newy,ans,path,visit);
            path.pop_back();
        }

        //right
        newx=x;
         newy=y+1;
        if(isSafe(m,n,newx,newy,visit)){
            path.push_back('R');
             solve(m,n,newx,newy,ans,path,visit);
            path.pop_back();
        }

        //up
         newx=x-1;
         newy=y;
        if(isSafe(m,n,newx,newy,visit)){
            path.push_back('U');
             solve(m,n,newx,newy,ans,path,visit);
            path.pop_back();

        }

         newx=x;
         newy=y-1;
        if(isSafe(m,n,newx,newy,visit)){
            path.push_back('L');
             solve(m,n,newx,newy,ans,path,visit);
            path.pop_back();
        }

        visit[x][y]=0;




    }

    public:
    vector<string> findpath(vector<vector<int>>& m, int n){
        vector<string> ans;
        if(n==0){
            return ans;
        }

        int srcx=0;
        int srcy=0;
        string path = "";
        vector <vector<int>> visit=m;

        for(int i=0; i<n;i++){
            for(int j=0;j<n;j++){
                visit[i][j]=0;
            }
        }


        solve(m,n,srcx,srcy, ans, path, visit);

        return ans;

    }

};

int main(){

    int n;
    cout<<"enter size of maze\n";
    cin>>n;

    vector<vector<int>> m(n , vector<int>(n,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>> m[i][j];
        }
    }

    solution obj;
    vector<string> ans=obj.findpath(m,n);
    cout<<ans.size()<<endl;

    if(ans.size()==0){
        cout<<-1<<endl;
    }
    else {
        for(int i=0;i<ans.size(); i++){
            cout<<ans[i]<<endl;
        }
    }



    return 0;
}