#include<iostream>
#include<queue>

using namespace std;

int solve(int arr[], int s, int k){

    deque<int> maxi;
    deque<int> mini;
    int ans=0;
    for(int i=0;i<k;i++){

        while(!maxi.empty() && arr[maxi.back()]<=arr[i]){
            maxi.pop_back();
        }
        
        while(!mini.empty() && arr[mini.back()]>=arr[i]){
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);

    }
            ans = arr[mini.front()]+arr[maxi.front()];

    for(int i=k;i<s;i++){



        while(i- maxi.front()>=k && !maxi.empty()){
            maxi.pop_front();
        }

        while(i-mini.front()-i>=k && !mini.empty()){
            mini.pop_front();
        }

        
        while(!maxi.empty() && arr[maxi.back()]<=arr[i]){
            maxi.pop_back();
        }
        
        while(!mini.empty() && arr[mini.back()]>=arr[i]){
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);

        ans = ans+arr[mini.front()]+arr[maxi.front()];


    }
    
    return ans;

}



int main(){

    int arr[7]= {2, 5, -1, 7, -3, -1, -2};

    int size=7;
    int k=4;
    

    int ans=solve(arr, size, k);


    cout<<ans;


    return 0;
}