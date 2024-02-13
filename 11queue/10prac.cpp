#include<iostream>
#include<queue>

using namespace std;

int solve(int arr[], int size, int k){

    deque<int> maxi;
    deque<int> mini;

    for(int i=0;i<k;i++){
        int element=arr[i];

        while(!maxi.empty() && element> arr[maxi.front()]){
            maxi.pop_front();
        }

        while(!mini.empty() && element<arr[mini.front()] ){
            mini.pop_front();
        }

        maxi.push_back(i);
        mini.push_back(i);

    }
    int ans= arr[maxi.front()]+arr[mini.front()];

    for(int i=k;i<size;i++ ){
        int element=arr[i];

        while(!maxi.empty() && i-maxi.front()>=k){
            maxi.pop_front();
        }

        while(!mini.empty() && i-mini.front()>=k){
            mini.pop_front();
        }

        while(!maxi.empty() && arr[maxi.back()] <= element){
            maxi.pop_back();
        }
        while(!mini.empty() && arr[mini.back()] >=element){
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);

        ans=ans+arr[maxi.front()]+arr[mini.front()];
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