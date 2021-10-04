class Solution {
public:
    int id = 0, m, n;
     bool border(vector<vector<int>>grid, int i, int j, int curr){
        if(i == 0 or j == 0 or i == m - 1 or j == n - 1){
            return 1;
        }
        if(grid[i + 1][j] == curr && grid[i][j + 1] == curr && grid[i - 1][j] == curr && grid[i][j - 1] == curr)
            return 0;
        return 1;
    }
    void dfs(int i, int j, vector<vector<int>>&grid, vector<vector<int>>g, vector<vector<bool>>&vis, int curr, int color){
        if(i < 0 || j < 0 || i >= m || j >= n || vis[i][j] == true || grid[i][j] != curr)
            return ;
        vis[i][j] = true;
        if(border(g,i,j,curr))
            grid[i][j] = color;
        
        dfs(i + 1, j, grid, g, vis, curr, color);
        dfs(i - 1, j, grid, g, vis, curr, color);
        dfs(i, j + 1, grid, g, vis, curr, color);
        dfs(i, j - 1, grid, g, vis, curr, color);
        
     
    }
    
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        
         m = grid.size();
         n = grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
       
        dfs(row,col,grid,grid,vis,grid[row][col],color);
              
        return grid;
             
        
    }
};