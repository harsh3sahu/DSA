#include<iostream>

using namespace std;

bool pos(int arr[],int mid, int n , int m){

    
    int count=0;
    int studentCount=1;
    int sum=0;

    

        for(int i=0;i<=n;i++){
            if(sum<mid){
                sum=sum+arr[i];
            }

            else{

                if(studentCount<m ){
                    studentCount++;
                    sum=0;
                }
                else{
                    return false;
                }


            }



        }
        return true;

    


}



int pageCount(int arr[], int n , int m){

    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
    }

    int start=0;
    int end=sum;
    int mid=(start+end)/2;
    int pages=0;

    while(start<=end){

        if(pos(arr,mid,n,m)){
            pages=mid;
            end=mid-1;
        }

        else{
            start=mid+1;
        }

        mid=(start+end)/2;


    }

    return pages;


}



int main(){

    int n=4;//number of books
    int m=2;//number of students

    int arr[4] = {12, 34, 67, 90};

    int ans= pageCount(arr, n ,m);

    cout<<ans;

    return 0;
}