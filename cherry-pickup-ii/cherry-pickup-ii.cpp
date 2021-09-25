class Solution {
public:
    int dp[72][72][72];
    int m,n;
    int solve(vector<vector<int>>& grid, int x, int y1, int y2){
     if(x >= m || y1 < 0 || y2 < 0 || y1 >= n || y2 >= n) return INT_MIN;
        if(x == (m-1)) 
            return (y1==y2) ? grid[x][y1] : (grid[x][y1] + grid[x][y2]);
        if(dp[x][y1][y2]!=-1) 
            return dp[x][y1][y2];
        
        int ans = INT_MIN;
        int temp = (y1==y2) ? grid[x][y1] : (grid[x][y1] + grid[x][y2]);
        ans = max(ans, solve(grid,x+1, y1, y2));
        ans = max(ans, solve(grid,x+1, y1, y2+1));
        ans = max(ans, solve(grid,x+1, y1, y2-1));
        
        ans = max(ans, solve(grid,x+1, y1-1, y2));
        ans = max(ans, solve(grid,x+1, y1-1, y2+1));
        ans = max(ans, solve(grid,x+1, y1-1, y2-1));
        
        ans = max(ans, solve(grid,x+1, y1+1, y2));
        ans = max(ans, solve(grid,x+1, y1+1, y2+1));
        ans = max(ans, solve(grid,x+1, y1+1, y2-1));
        
        return dp[x][y1][y2] = ans + temp;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        
        memset(dp,-1,sizeof(dp));
      
        m = grid.size(), n = grid[0].size();
    
        return solve(grid,0,0,n-1);
    }
};