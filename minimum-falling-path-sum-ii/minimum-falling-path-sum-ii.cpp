class Solution {
public:
    
    int dp[201][201];
    int n;
    int minpath(vector<vector<int>>&grid, int i, int j){
        if(i >= n)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans = INT_MAX;
        
        for(int idx = 0 ; idx < n ; idx++){
            if(idx != j){
            int a = grid[i][j] + minpath(grid,i+1,idx);
            ans = min(ans,a);
            }
        }
        
        return dp[i][j] = ans;
    }
    
    int minFallingPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        memset(dp,-1,sizeof(dp));
        int ans = INT_MAX;
           if(n == 1){
    
            for(int j = 0; j < n ; j++)
                ans = min(ans,grid[0][j]);
            
            return ans;
        }
        
        for(int j = 0; j < n ; j++){
            ans = min(ans,minpath(grid,0,j));
        }
            
        return ans;
    }
};