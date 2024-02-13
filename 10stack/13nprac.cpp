#include<iostream>
#include<vector>
#include <cstring>


using namespace std;

class Nstack{
    public:
    int size;
    int *arr;
    int *next;
    int *top;
    int freespace=0;

    Nstack(int size, int num){
        this->size=size;
        

        arr=new int[size];
        next=new int[size];
        top = new int[num];

    
        memset(top,-1,num);
        


        for(int i=0;i<size-1;i++){
            next[i]=i+1;
        }
        next[size-1]=-1;

        
     
    }

    void push(int data, int s){

        if(freespace<size){

            arr[freespace]=data;

            int curr= freespace;

            freespace++;

            next[curr]=top[s];

            top[s]=curr;

        }
    }





    void pop(int s){

        int curr= top[s];

        top[s]=next[curr];

        next[curr]=freespace;

        freespace= curr;

        arr[curr]=-1;

    }

    void printStack(){

    for(int i=0;i<size;i++){
        cout<<arr[i]<<endl;
    }
    }

    void printStackNumber(int s){
        
        int curr=top[s];

        for(int i=0;i<size;i++){
            cout<<next[i]<<endl;
        }

        // while(curr!=-1){
        //     cout<<arr[curr]<<endl;
        //     curr=next[curr];
        // }

    }
    


};

int main(){

    Nstack s(7,3);

    s.push(10,1);
    s.push(20,2);
    s.push(14,0);
    s.push(23,1);
    s.push(25,0);
    s.push(1454,1);
    s.push(1434,2);

    s.printStackNumber(1);
    cout<<endl<<endl;

    s.pop(1);
    s.pop(1);
    s.pop(2);
    
    // s.printStack();
    // cout<<endl<<endl;
    //     s.printStackNumber(1);




    return 0;
}