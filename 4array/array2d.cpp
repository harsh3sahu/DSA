#include<iostream>
using namespace std;



int main(){
    int arr[3][4]={10,23,1,4,65,20,54,80,40,9,13,45};
     
    // cout<<"enter the elements"<<endl;
    // for(int i=0;i<3;i++){
    //     for(int j=0;j<4;j++){
    //         cin>>arr[i][j];
    //     }
    // }
    int index=0;
    int max=0;
    for(int i=0;i<3;i++){
        int sum=0;
        
        for(int j=0;j<4;j++){
            sum=sum+arr[i][j];
        }
        // cout<<sum<<endl;

        if(sum>max){
            max=sum;
            index=i;
        }
    }
    cout<<index+1<<endl<<max;


    return 0;
}