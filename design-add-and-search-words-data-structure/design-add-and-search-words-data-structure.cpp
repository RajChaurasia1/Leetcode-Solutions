class WordDictionary {
public:
    
    struct TrieNode{
        bool end;
        TrieNode* child[26];
    };
    
    
    
    TrieNode* getnode(){
        
        TrieNode*root = new TrieNode;
        
        for(int i = 0 ; i < 26 ; i++)
            root->child[i] = NULL;
        
        root->end = false;
        
        return root;
    }
    TrieNode*root;
    WordDictionary() {
        root = getnode();
    }
    
    void addWord(string word) {
        TrieNode*t = root;
        
        for(int i = 0 ; i < word.size() ; i++){
            if(t->child[word[i] - 'a'] == NULL)
                t->child[word[i] - 'a'] = getnode();
            t = t->child[word[i] - 'a'];
        }
        
        t->end = true;
        
    }
    
    bool search(string word) {
      return search_helper(root,word,0);
    }
    
     bool search_helper(TrieNode* curr,string word,int ind){
        
        if(ind == word.size()){
            return (curr->end);
        }
                    
        int index = word[ind] - 'a';
        if(word[ind] != '.'){
            
            if(curr->child[index] == NULL)
                return false;
            
            return search_helper(curr->child[index],word,ind + 1);
        }
        else{
            //if it is a '.' , try all possibilities
            for(int i = 0; i < 26; i++){
                if(curr->child[i])
                {
                    
                    if(search_helper(curr->child[i],word,ind + 1))
                        return true;
                }
            }
            
            return false;
        }
        return false;
        
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */