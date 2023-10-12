class trieNode{

    public:
    char ch;
    trieNode* children[26];
    bool isTerminal;
    
    trieNode(char data){
        ch=data; 
        for (int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal =false;
    }
        
};

class trie{

    public:
    trieNode* root;
    
    trie(){
        root= new trieNode('\0');
    }

    void insertUtil(trieNode* node,string word){
        if(word.length()==0){
            node->isTerminal=true;
            return ;
        }

        int index=word[0]-'a';
        trieNode* child;
        
       if(node->children[index]!=NULL){
            child=node->children[index];

        }

        else{
            child=new trieNode (word[0]);
            node->children[index]=child;
        }

        insertUtil(child, word.substr(1));
    }

    void insertWord(string word){
        insertUtil(root,word);
    }

    void printSuggestions(trieNode* curr,vector<string> &temp,string prefix){
        if(curr->isTerminal){
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


    vector<vector<string>> findContact(vector<string>&contactList, string &str){
        
        trieNode* prev=root;
        vector<vector<string>>ans;
   
        string prefix="";

       
       for(int i=0;i<str.length();i++){
           
            char lastchar=str[i];
            prefix.push_back(lastchar);  

            trieNode* curr=prev->children[lastchar-'a'];            
           
           if(curr==NULL){
               break;
           }
           
           vector<string>temp;
           printSuggestions(curr, temp, prefix);

           ans.push_back(temp);
           temp.clear();
           prev=curr;
       }

       return ans;
        
        
    }

};

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    //    Write your code here.
    trie *t=new trie();
    
   
    string str;
    
    for(int i=0;i<contactList.size();i++){
        string str=contactList[i];
        t->insertWord(str);
    }
    
    return t->findContact(contactList,queryStr);
;
}c 