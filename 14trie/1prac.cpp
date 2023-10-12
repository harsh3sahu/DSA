#include<iostream>

using namespace std;

class trieNode{

    public:
    char ch;
    trieNode* children[26];
    bool isTerminal;

    trieNode(char data){
        ch=data;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
    }



};


class trie{

    public:
    trieNode* root;
    
    trie(){
        root=new trieNode('\0');
    }

    void insertUtil(trieNode* root,string word){
        if(word.length()==0){
            root->isTerminal=true;
            return ;
        }

        int index= word[0]-'a';
        trieNode* child;

        if(root->children[index]!=NULL){
            child=root->children[index];
        }

        else{
            child=new trieNode(word[0]);
            root->children[index]=child;

        }

        insertUtil(child,word.substr(1));
    }

    void insertWord(string word){
        insertUtil(root,word);
    }

    bool searchUtil(trieNode* root, string word){
        if(word.length()==0 && root->isTerminal==true){
            return true;
        }
        if(word.length()==0){
            return false;
        }

        int index=word[0]-'a';
        trieNode* child;

        if(root->children[index]!=NULL){
            child=root->children[index];
        }

        else{
            return false;
        }

        return searchUtil(child,word.substr(1));
    }

    bool searchWord(string word){
        bool ans=searchUtil(root,word);
        return ans;
    }

    bool deleteUtil(trieNode* root, string word){
        if(word.length()==0 && root->isTerminal==true){
            root->isTerminal=false;
            return true;
        }
        if(word.length()==0){
            return false;
        }

        int index=word[0]-'a';
        trieNode* child;

        if(root->children[index]!=NULL){
            child=root->children[index];
            return deleteUtil(child,word.substr(1));
        }
        else{
            return false;
        }
    }

    void deleteWord(string word){
        if(deleteUtil(root,word)){
            cout<<"word deleted\n";
        }
        else{
            cout<<"word does not exist";
        }
        return ;
    }


};



int main(){

    trie root;

    root.insertWord("harsh");
    root.insertWord("navjot");
    root.insertWord("anany");

    cout<< root.searchWord("harsh")<<endl;
    cout<<root.searchWord("anan")<<endl;

    root.deleteWord("harsh");
    root.deleteWord("nav");

    return 0;
}