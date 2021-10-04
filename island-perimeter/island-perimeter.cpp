class Solution {
public:
    int m, n, perimeter = 0;

    bool isValid(int i, int j, int m, int n, vector<vector<int>>& grid){
        if(i < 0 or i >= m or j < 0 or j >= n or grid[i][j] == 0)
            return true;
         return false;
    }
    void dfs(vector<vector<int>>&grid, vector<vector<bool>>&vis, int i, int j){
        if(i < 0 || j < 0 || i >= m || j >= n || vis[i][j] == true || grid[i][j] == 0)
            return ;
        vis[i][j] = true;
          int c=0;
        if(isValid(i + 1,j,m,n,grid))
            c+=1;
        if(isValid(i - 1,j,m,n,grid))
            c+=1;
        
        if(isValid(i,j - 1,m,n,grid))
            c+=1;
        if(isValid(i,j + 1,m,n,grid))
            c+=1;
        
        perimeter+=c;
        
        dfs(grid,vis,i-1,j);
        dfs(grid,vis,i,j-1);
        dfs(grid,vis,i,j+1);
        dfs(grid,vis,i+1,j);
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        for(int i = 0 ; i < m ; i++){
          for(int j = 0 ; j < n ; j++){
              if(grid[i][j] == 1 && !vis[i][j]){
                  dfs(grid,vis,i,j);
              }
          }  
        }
        
       return perimeter;
        
    }
};