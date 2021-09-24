class Solution {
public:
    
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
    
    void insert(TrieNode*head, string s){
        TrieNode*t = head;
        int index;
        
        for(int i = 0 ; i < s.size() ; i++){
            index = s[i] - 'a';
            if(t->child[index] == NULL)
                t->child[index] = getNode();
                
            t = t->child[index];
        }
        
        t->isEndhere = true;
        
    }
    
    bool search(TrieNode*head, string s){
        TrieNode*t = head;
        int index;
        
        for(int i = 0 ; i < s.size() ; i++){
            index = s[i] - 'a';
            if(t->child[index] == NULL)
               return false;
                
            t = t->child[index];
        }
        
        return t->isEndhere;
        
    }

struct TrieNode*root = getNode();
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        for(int i = 0 ; i < wordDict.size() ; i++)
            insert(root,wordDict[i]);
            
        
        int n = s.size();
		vector<bool> dp(n+1,false);
        dp[0] = true;
        for(int i=1;i<=n;i++) {
            for(int j=i-1;j>=0;j--) {
                if(dp[j]) {
                    string word = s.substr(j,i-j);
                    if(search(root,word)){
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[n];
    }
};