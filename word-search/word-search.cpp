class Solution {
public:
    int m, n;
    bool dfs(int i, int j, vector<vector<char>>&board, string &word, int pos){
        
        if(pos == word.size())
            return true;
      if(i < 0 || j < 0 || i >= m || j >= n || board[i][j]!=word[pos])
          return false;
        char ch = board[i][j];
        board[i][j] = '*';
        bool ans = dfs(i + 1, j, board, word, pos + 1) || dfs(i - 1, j, board, word, pos + 1) || dfs(i, j + 1, board, word, pos + 1) || dfs(i, j - 1, board, word, pos + 1);
        board[i][j] = ch;
        return ans;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
         m = board.size();
         n = board[0].size();
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(board[i][j] == word[0] && dfs(i,j,board,word,0))
                    return true;
            }
        }
        
        return false;
    }
    

};