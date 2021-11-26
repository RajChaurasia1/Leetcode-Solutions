class Solution {
public:
       int pos = 0;
    vector<vector<int>>ans;
    bool isvalid(vector<vector<int>>&board, int r, int c, int n){
        for(int i = r ; i >= 0 ; i--)
            if(board[i][c] == 1)
                return false;
        for(int i = 0; i < n ; i++)
            if(board[r][i] == 1)
                return false;
        for(int i = r,j = c; i >= 0&& j >= 0 ;i--,j--)
            if(board[i][j] == 1)
                return false;
        for(int i = r,j = c; i >= 0&& j < n ;i--,j++)
            if(board[i][j] == 1)
                return false;
        
        return true;
        //  for(int j=0;j<board[0].size();j++)
        // {
        //     if(board[r][j]) return false;
        // }
        // //check for row
        // for(int i=0;i<board.size();i++)
        // {
        //     if(board[i][c]) return false;
        // }
        // //check for left upward diagonal
        // for(int i=r,j=c;i>=0 && j>=0;i--,j--)
        // {
        //     if(board[i][j]) return false;
        // }
        // //check for right upward diagonal
        // for(int i=r,j=c;i>=0 && j<board[0].size();i--,j++)
        // {
        //     if(board[i][j]) return false;
        // }
        // return true;
    }
    
    void q(int n, int col, vector<vector<int>>&board, vector<int>&l, vector<int>&ld, vector<int>&ud){
        if(col == n){
            // for(int i = 0 ; i < n ; i++){
            //     vector<int>v(n,0);
            //     for(int j = 0 ; j < n ; j++){
            //         if(board[i][j] == 1){
            //             v[j] = 1;
            //         }
            //     }
            // }
            // ans.push_back(v);
            pos++;
            return;
        }
        
        for(int i = 0 ; i < n ; i++){
           // if(isvalid(board,row,i,n)){
            if(l[i] == 0 && ld[i + col] == 0 && ud[n - 1 + col - i] == 0){
                //board[i][col] = 1;
                l[i] = 1;
                ld[i + col] = 1;
                ud[n - 1 + col - i] = 1;
                q(n,col+1,board,l,ld,ud);
                l[i] = 0;
                ld[i + col] = 0;
                ud[n - 1 + col - i] = 0;
        }
                //board[i][col] = 0;
           // }
        }
        return;
    }
    
    int totalNQueens(int n) {
        
        
        vector<vector<int>>board(n,vector<int>(n,0));
        vector<int>l(n,0),ld(2*n - 1,0),ud(2*n - 1,0);
        q(n,0,board,l,ld,ud);
        return pos;
        
    }
};