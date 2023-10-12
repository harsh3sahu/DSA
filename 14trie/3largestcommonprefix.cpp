class trieNode{
    public:
    char ch;
    trieNode* children[26];
    bool isTerminal;
    int childCount;
    
    trieNode(char data){
        ch=data;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
        childCount=0;
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
            root->childCount++;

        }

        insertUtil(child,word.substr(1));
    }

    void insertWord(string word){
        return insertUtil(root,word);
    }
    

    void lcp(string word, string &ans){
        if(word.length()==0){
            return ;
        }

        for(int i=0;i<word.length();i++){
            int index=word[i]-'a';
            if(root->childCount>1){
                break;
                return ;
            }
            else{
                ans.push_back(word[i]);
            }
            root=root->children[index];
        }
        return ;
        
        
    }



    
};




string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    trie node;
    for(int i=0;i<n;i++){
        node.insertWord(arr[i]);
    }
    
    string ans;
    node.lcp(arr[0],ans);
    return ans;
    
    
}


