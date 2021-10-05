class Solution {
public:

     int m,n;
    vector<string>ans;
    unordered_map<string,int>mp;
    struct Trienode{
        string word;
        Trienode* child[26];
    };
    
    
    Trienode*getnode(){
        Trienode*t = new Trienode;
        t->word = "";
        for(int i = 0 ; i < 26 ; i++){
            t->child[i] = NULL;
            
        }
        return t;
    }
    
    void insert(Trienode*root,string s){
        Trienode*temp = root;
        
        for(int i = 0 ; i < s.size() ; i++){
            int index = s[i] - 'a';
            
            if(temp->child[index] == NULL){
                temp->child[index] = getnode();
                
            }
            temp = temp->child[index];
        }
        temp->word = s;
        return;
    }
  
    
    void search(int i, int j, vector<vector<char> >& board,Trienode*root){
      if(i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '0'|| !root->child[board[i][j] - 'a']) return;
        root = root->child[board[i][j] - 'a'];
        if(root->word.size()>0){
            ans.push_back(root->word);
            root->word = "";
        }
        char tmp = board[i][j];
        board[i][j] = '0';
        search(i - 1,j,board,root);
        search(i + 1, j,board,root);
        search(i, j + 1,board,root);
        search(i, j - 1,board,root);
        board[i][j] = tmp;
    }
    
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
         m = board.size();
         n = board[0].size();
    
          Trienode *root = getnode();
	   for(int i = 0 ; i < words.size() ; i++){
	       insert(root,words[i]);
	   }
	  
	   for(int i = 0 ; i < m ; i++){
	       for(int j = 0 ; j < n ; j++){
	           search(i,j,board,root);
	       }
	   }
	    return ans;
    }
};