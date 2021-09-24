class MagicDictionary {
public:
    /** Initialize your data structure here. */
    
    
    struct TrieNode {
        bool isLeaf;
        struct TrieNode* child[26];
        TrieNode() {
            for (int i = 0; i < 26; i++) {
                child[i] = NULL;
            }
            isLeaf = false;
        }
    };

    TrieNode*root;
   
    MagicDictionary() {
        root = new TrieNode();
    }
        
    void insert(string word) {
        TrieNode*t = root;
        
        for(int i = 0 ; i < word.size() ; i++){
            if(t->child[word[i] - 'a'] == NULL){
                t->child[word[i] - 'a'] = new TrieNode();
            }
            
            t = t->child[word[i] - 'a'];
        }
        
        t->isLeaf = true;
    }
    
       bool magicsearch(string word) {
        TrieNode*t = root;
        
        for(int i = 0 ; i < word.size() ; i++){
            if(t->child[word[i] - 'a'] == NULL){
               return false;
            }
            
            t = t->child[word[i] - 'a'];
        }
        
        return t->isLeaf;
    }
    
    
    void buildDict(vector<string> dictionary) {
        for(int i = 0 ; i < dictionary.size() ; i++){
            insert(dictionary[i]);
        }
    }
    
    bool search(string searchWord) {
           for(int i = 0 ; i < searchWord.size() ; i++){
               string temp = searchWord;
               for(int j = 0 ; j < 26 ; j++){
                   if(j == searchWord[i] - 'a')
                       continue;
                   temp[i] = 'a' + j;
                   if(magicsearch(temp))
                       return true;
               }
           }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */