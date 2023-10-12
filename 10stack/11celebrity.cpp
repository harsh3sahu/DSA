#include<iostream>
#include<stack>

using namespace std;

int celebrity(int arr[3][3] , int n){
    stack<int> s;

    for(int i=0;i<n;i++){
        s.push(i);
    }

    while(s.size()>1){
        int a= s.top();
        s.pop();
        int b=s.top();
        s.pop();
        

        if(arr[a][b]==1){
            s.push(b);
        }

        else{
            s.push(a);
        }
        cout<<"Check point\n";
        
    }

    int p=s.top();
    
    for(int i=0;i<n && i!=p ;i++){
        if(arr[i][p]!=1){
            return -1;
            
        }
        if(arr[p][i]!=0){
            return -1;
        }
        
    }
    return p;


}

int  main(){


    int n=3;
    int arr[3][3] = {0, 0,1, 1, 0, 1,1, 0, 0};


    int ans=celebrity(arr,n);


    if(ans!=-1){
        cout<<"the celebrity is "<< ans <<endl;
    }

    else{
        cout<<"there is no celebrity\n";
    }



    return 0;
}