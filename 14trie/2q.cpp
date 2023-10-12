// implement a phone directory

// https://www.codingninjas.com/studio/problems/implement-a-phone-directory_1062666?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
class trieNode{
    public:
    char data;
    trieNode* children[26];
    bool isterminal;

    trieNode(char ch){
        data=ch;

        for(int i=0;i<26;i++){
            children[i]=NULL;
        }

        isterminal=false;

    }



};

class trie{
    public:
    trieNode* root;

    trie(){
        root=new trieNode('\0');
    }

     void insertUtil(trieNode* root, string word){

        if(word.length()==0){
            root->isterminal=true;
            return;
        }
        
        int index=word[0]-'a';
        trieNode* child;

        if(root->children[index]!=NULL){
            child=root->children[index];

        }

        else{
            child=new trieNode (word[0]);
            root->children[index]=child;
        }

        insertUtil(child,word.substr(1));


    }

    void insertWord(string word){
        insertUtil(root,word);
    }

    void printSuggestions(trieNode* curr, vector<string> &temp, string prefix){
        if(curr->isterminal){
            temp.push_back(prefix);
        }

        for(char ch='a'; ch<'z';ch++){
            trieNode* next=curr->children[ch-'a'];

            if(next!=NULL){
                prefix.push_back(ch);
                printSuggestions(next, temp,prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getsuggestions(string str){
        trieNode* prev=root;
        vector<vector<string>> output;

        string prefix="";

        for(int i=0;i<str.length();i++){
            char lastch=str[i];

            prefix.push_back(lastch);

            trieNode* curr=prev->children[lastch-'a'];


            if(curr==NULL){
                break;
            }

            vector<string> temp;
            printSuggestions(curr, temp, prefix);

            output.push_back(temp);
            temp.clear();
            prev=curr;

        }

        return output;
    }


};


vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    //    Write your code here.

    trie* t= new trie();

    for(int i=0;i<contactList.size();i++){
        string str=contactList[i];
        t->insertWord(str);
    }

    return t->getsuggestions(queryStr);


}