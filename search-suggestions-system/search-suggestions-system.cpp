class Solution {
public:
    struct TrieNode{
      
        TrieNode* child[26];
        bool end;
        
    };
    vector<vector<string>>ans;
    int i = 0;
    TrieNode* getnode(){
        TrieNode* root = new TrieNode;
        for(int i = 0 ; i < 26 ; i++)
            root->child[i] = NULL;
        
        root->end = false;
        
        return root;
    }
    
    void insert(TrieNode* root, string word){
        TrieNode* t = root;
        
        for(auto c : word){
            if(!t->child[c - 'a'])
                t->child[c - 'a'] = getnode();
            t = t->child[c - 'a'];
        }
        
        t->end = true;
    }
    
    void dfs(TrieNode* curr, string word, vector<string>&res){
        if(res.size() == 3)
            return;
        if(curr->end)
            res.push_back(word);
        
        for(auto c = 'a' ; c <= 'z' ; c++){
            if(curr->child[c - 'a']){
                word.push_back(c);
                dfs(curr->child[c - 'a'], word, res);
                word.pop_back();
            }
        }
        
    }
    void search(TrieNode* root, string word, vector<string>&res){
        TrieNode* t = root;
        
        for(auto c : word){
            if(!t->child[c - 'a'])
                return;
            
                t = t->child[c - 'a'];
          
        }
        
        dfs(t,word,res);
        
    }
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        TrieNode* root = getnode();
        
        for(auto word : products){
            insert(root,word);
        }
        
        for(int i = 0 ; i < searchWord.size() ; i++){
            string sub = searchWord.substr(0, i + 1);
            vector<string>res;
            search(root,sub,res);
            ans.push_back(res);
            
        }
        return ans;
    }
};