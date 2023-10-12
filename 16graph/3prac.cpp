#include<iostream>
#include<vector>

using namespace std;


int main(){

    int nodes;
    cout<<"enter number of nodes\n";
    cin>>nodes;


    vector<vector<int>>adjMatrix(nodes,vector<int> (nodes,0));
    int n;
    cout<<"enter number of edges\n";
    cin>>n;

    for(int i=0;i<n;i++){
        int p;
        int q;
        cin>>p>>q;
        adjMatrix[p][q]=1;
        adjMatrix[q][p]=1;
        cout<<endl;
    }

    for(auto i:adjMatrix){
        for(auto j:i){
            cout<<j<<"  ";
        }
        cout<<endl;
    }






    return 0;
}