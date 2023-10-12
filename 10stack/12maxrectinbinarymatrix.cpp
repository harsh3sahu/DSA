#include<iostream>
#include<stack>
#include<vector>

using namespace std;
vector<int> prevElements(vector<int> &h, int n){

    stack<int> s;
    s.push(-1);
    vector<int> ans(n);


    for(int i=0;i<n;i++){
        int curr=h[i];
        
 

        while(s.size()!=1 && h[s.top()]>=curr){
            s.pop();
        }
        ans[i]=s.top();

        s.push(i);


    }

    return ans;


}


vector<int> nextElements(vector<int> &h, int n){

    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i=n-1;i>=0;i--){
        int curr=h[i];
            


        while( (s.size()!=1) && h[s.top()]>=curr){
            s.pop();
        }

        ans[i]=s.top();

        s.push(i);


    }

    return ans;


}



int maxArea(vector<int> &h, int n){
    
    
    
    vector<int> prev;
    vector<int> next;

    prev=prevElements(h,n);

    next=nextElements(h,n);


    int l;
    int b;
    int area=0;
    int newarea;
    
    for(int i=0;i<n;i++){

        l=h[i];

       

        if(next[i]==-1){
            next[i]=n;
        }

        b=next[i]-prev[i]-1;

        

        newarea=l*b;

        area=max(area,newarea);

    }

    return area;

}



int matrixArea(vector<vector<int>> matrix, int row, int col){

    int area;

    area=maxArea(matrix[0], col);

    for(int i=1;i<row;i++){

        for(int j=0;j<col;j++){
            if( matrix[i][j]!=0){
                matrix[i][j]=matrix[i][j]+matrix[i-1][j];

            }

        }


        area=max(area,maxArea(matrix[i], col));
    }

    return area;
}


int main(){

    int row;
    int col;

    cout<<"enter number of rows\n";
    cin>>row;

    cout<<"enter number of cols\n";
    cin>>col;

    

    vector <vector<int>> matrix(row,vector<int>(col));
    for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                cin>>matrix[i][j];
            }
        }


    int ans;

    ans=matrixArea(matrix,row,col);

    cout<<ans;

    return 0;
}
