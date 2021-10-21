class WordFilter {
public:
    
    struct TrieNode{
      
        TrieNode* child[27];
        int index;
        
    };
    
    
    TrieNode*getnode(){
        TrieNode* root = new TrieNode;
        
        for(int i = 0 ; i < 27 ; i++)
            root->child[i] = NULL;
        
        root->index = -1;
        
        return root;
    }
    TrieNode* root = getnode();
    
    void insert(string word, int id){
        TrieNode*t = root;
        
        for(auto c : word){
            if(t->child[c - 'a'] == NULL)
                t->child[c - 'a'] = getnode();
            t = t->child[c - 'a'];
            t->index = id;
        }
        
        return;
    }
    
    int search(string pfsf){
         TrieNode*t = root;
        
        for(auto c : pfsf){
            if(t->child[c - 'a'] == NULL)
                return -1;
            t = t->child[c - 'a'];
            
        }
        return t->index;
    }
    
    WordFilter(vector<string>& words) {
        for(int i = 0 ; i < words.size() ; i++){
            for(int j = 0 ; j < words[i].size() ; j++){
                string word = words[i].substr(j) + "{" + words[i];
                insert(word,i);
            }
        }
    }
    
    int f(string prefix, string suffix) {
        return search(suffix + "{" + prefix);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */