#include <bits/stdc++.h> 
#include<stack>
using namespace std;
int findMinimumCost(string str) {
  // Write your code here

  stack <char> s;
  int opencount=0;
  int closecount=0;

  for(int i=0;i<str.length();i++){
    char ch=str[i];

    if(ch=='{'){
      s.push(ch);
    }
    else if(ch=='}' && !s.empty()){
      s.pop();
    }
    else{
      closecount++;
    }
    

  }

  while(!s.empty()){
    opencount++;
    s.pop();
  }

  int totalcount=opencount+closecount;

  if(totalcount%2!=0){
    return -1;
  }
  else if(opencount!=0 || closecount!=0){
    return ((opencount+1)/2 + (closecount+1)/2);
  }

  return 0;

}

int main(){

    string str="{}}{}}";

    int ans =findMinimumCost(str);

    cout<<ans<<endl;






    return 0;
}