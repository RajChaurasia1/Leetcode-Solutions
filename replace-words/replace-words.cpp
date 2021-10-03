class Solution {
public:
    string suc;
      struct TrieNode{
            TrieNode*child[26];
            bool word;
        };
        
        
        TrieNode*getnode(){
            TrieNode*root = new TrieNode;
            root->word = false;
            for(int i = 0 ; i < 26 ; i++)
                root->child[i] = NULL;
            
            return root;
        }
        
        void insert(TrieNode*root,string s){
            TrieNode*temp = root;
            for(auto c : s){
                if(temp->child[c - 'a'] == NULL)
                    temp->child[c - 'a'] =  getnode();
                
                temp = temp->child[c - 'a'];
            }
            
            temp->word = true;
        }
        
        string search(TrieNode*root,string s){
            TrieNode*temp = root;
            suc = "";
            for(auto c : s){
                if(temp->child[c - 'a'] == NULL){
                    suc = "";
                    break;}
                suc+=c;
                temp=temp->child[c - 'a'];
                if(temp->word)
                    break;
            }
            return (suc == "")?s:suc;
             
        }
    string replaceWords(vector<string>& dictionary, string sentence) {
     
        TrieNode*root =  getnode();
        string ans;
        for(int i = 0 ; i < dictionary.size() ; i++)
            insert(root,dictionary[i]);
        
        
        stringstream ss(sentence);
        string word;
        
        while(ss >> word){
           
            ans+=search(root,word);
            ans+=" ";
        }
      ans.pop_back();
        return ans;        
       
    }
};