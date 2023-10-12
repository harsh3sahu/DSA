#include<iostream>
#include<queue>

using namespace std;

int main(){

    string str="harsh";
    
    queue<char> q;
    int i=0;
    int arr[26]={0};
    char ch=0;
    while(str[i]!='\0'){
        int index = str[i]-'a';
        
        arr[index]++;

        if(ch == '0'){
            ch=str[i];
        }

        else if(arr[ch]-'a'<1){
            ch=str[i];
        }


        
        if(arr[index]>1){
            q.push('#');
        }

        else{
            q.push(ch);
           

        }

        i++;
       
    }
   
  
    while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
    }



    return 0;
}