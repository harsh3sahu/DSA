#include <iostream>
#include <queue>
#include<vector>

using namespace std;

int main()
{

    int size=4;

    vector<int> dis{6, 5, 3, 5};
    vector<int> pet{4, 6, 7, 4};

    int start=0;
    int rem=0;
    int def=0;
    int n=size;
    for(int i=0;i<n;i++){
        rem += pet[i]-dis[i];

        if(rem<0){
            def=rem;
            start=i+1;
            rem=0;
        }
    }


    if(rem-def>=0){
        cout<<"answer is "<< start<<endl;
    }

    else{
        cout<<"there is no point\n";
    }
    
}