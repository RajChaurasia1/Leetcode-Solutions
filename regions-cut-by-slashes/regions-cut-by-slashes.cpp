class Solution {
public:
    
    
    
    void dfs(int i, int j, vector<vector<int>>&g,int n){
        if(i < 0 || j < 0 || i >= n || j >= n || g[i][j]!=1)
            return;
        g[i][j] = 0;
        dfs(i+1,j,g,n);
        dfs(i-1,j,g,n);
        dfs(i,j-1,g,n);
        dfs(i,j+1,g,n);
    }
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        
        vector<vector<int>>g(3*n,vector<int>(3*n,1));
        
        for(int i = 0 ; i < n ; i++){
            int r = i*3;
            int c = 0, j = 0;
            while(c < grid[i].size()){
                if(grid[i][c] == '/'){
                    int x = r;
                    int y = j + 2, cnt = 3;
                    while(cnt--){
                        g[x][y] = 0;
                        x++,y--;
                    }
                }
                else if(grid[i][c] == '\\'){
                    int x = r;
                    int y = j, cnt = 3;
                    while(cnt--){
                        g[x][y] = 0;
                        x++,y++;
                    }
                }
                c++;
                j+=3;
            }
        }
        
        int ans = 0;
        
        for(int i = 0 ; i < 3*n ; i++){
            for(int j = 0 ; j < 3*n ; j++){
                if(g[i][j] == 1){
                    ans++;
                    dfs(i,j,g,3*n);
                }
            }
        }
        return ans;
    }
};