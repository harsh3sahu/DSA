// top down approach

#include<bits/stdc++.h>
using namespace std;

int fib(int n,vector<int> &dpArr){
        if(n==1 || n==0){

                return n;
        }

        if(dpArr[n]!=-1){
                return dpArr[n];
        }

        dpArr[n]=fib(n-1,dpArr)+fib(n-2,dpArr);
        return dpArr[n];

}


int main()
{
        int n;
        cin>>n;
        vector<int> dpArr(n+1,-1);
        int ans=fib(n,dpArr);
        cout<<ans;
        

}


// bottom up/


int main()
{
        int n;
        cin>>n;
        
        vector<int> arr(n+1);
        dp[1]=1;
        dp[0]=0;

        for(int  )
}