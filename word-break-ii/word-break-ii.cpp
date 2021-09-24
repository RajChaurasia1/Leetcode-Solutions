class Solution {
public:
    vector<string>result;
      struct TrieNode{
      bool isEndhere;
      TrieNode* child[26];
    };
    
    
    TrieNode *getNode(void){
        TrieNode* newnode = new TrieNode;
        newnode->isEndhere = false;
        for(int i = 0 ; i < 26 ; i++){
            newnode->child[i] = NULL;
        }
        
        return newnode;
    }
    
    void insert(string s){
        TrieNode*t = root;
        int index;
        
        for(int i = 0 ; i < s.size() ; i++){
            index = s[i] - 'a';
            if(t->child[index] == NULL)
                t->child[index] = getNode();
                
            t = t->child[index];
        }
        
        t->isEndhere = true;
        
    }
    
    bool search(string s){
        TrieNode*t = root;
        int index;
        
        for(int i = 0 ; i < s.size() ; i++){
            index = s[i] - 'a';
            if(t->child[index] == NULL)
               return false;
                
            t = t->child[index];
        }
        
        return t->isEndhere;
        
    }
    
    void backtrack(string& s, int pos, string curStr)
    {        
        if(pos >= s.size())
        {
            curStr.pop_back();
            
            result.push_back(curStr);
            return;
        }
        
        for(int i = pos; i < s.size(); i++)
        {
            string str = s.substr(pos, i - pos + 1);
            
            if(search(str))
                backtrack(s, i+1, curStr + str + " ");
        }
    }

    struct TrieNode*root = getNode();
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        for(int i = 0 ; i < wordDict.size() ; i++){
           
            insert(wordDict[i]);
        }
            
        
        for(int i = 0 ; i < s.size() ; i++){
            if(search(s.substr(0,i+1))){
                backtrack(s,i+1,s.substr(0,i+1) + " ");
            }
        }
        
        return result;
    }
};