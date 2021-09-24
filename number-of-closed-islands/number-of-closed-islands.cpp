class Solution {

public:
    int m, n;
    
    void dfs(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 || j< 0 || i >= m || j >= n || grid[i][j]) return;
        
        grid[i][j] = 1;
        
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        
     
        for(int i=0; i<m; i++) 
            dfs(grid, 0, i), dfs(grid, m-1, i);
        
        
        for(int i=0; i<m; i++) 
            dfs(grid, i, 0), dfs(grid, i, n-1);
        
        
       
        int res=0;
        for(int i=1; i<m-1; i++) 
            for(int j=1; j<n-1; j++) 
                if(grid[i][j] == 0) 
                    dfs(grid, i, j), res++;
        
        return res;
    }
};