#include<iostream>
#include<stack>

using namespace std;

void makestringvalid(string &str){
    stack<char> stac;
    int opencount=0;
    int closecount=0;

    for(int i=0;i<str.length();i++){
        char ch=str[i];

        if(ch=='{'){
            stac.push(ch);
        }

        if(!stac.empty() && ch=='}'){

            stac.pop();
        }

        else if(ch=='}' && stac.empty()==0){
            closecount++;
        }


    }

    while(!stac.empty()){
        opencount++;
        stac.pop();

    }

    int openans=0;
    int closeans=0;
    if(opencount!=0 && opencount%2==0){
        openans=opencount/2;
    }

    else if(closecount!=0 && closecount%2==0){
        closeans=closecount/2;
    }

    if(openans!=0){
        cout<<"change "<<openans<<" { to }";
    }

    else if(closeans!=0){
        cout<<"change "<<closeans<<" } to {";
    }

    else {
        cout<<"there is no need to change\n";
    }


}



int main(){


    string str;
    cout<<"enter the string\n";
    cin>>str;

    makestringvalid(str);




    return 0;
}