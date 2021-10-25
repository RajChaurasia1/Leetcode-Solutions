class Solution {
public:
    
    int m, n;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    int dp[201][201];
    
    int dfs(int i, int j, vector<vector<int>>&matrix){
        if(dp[i][j] != 0)
            return dp[i][j];
        
        for(int k = 0 ; k < 4 ; k++){
            int nx = i + dx[k], ny = j + dy[k];
            
            if(nx >= 0 && ny >= 0 && nx < m && ny < n && matrix[nx][ny] > matrix[i][j])
                dp[i][j] = max(dp[i][j], 1 + dfs(nx, ny, matrix));
        }
        
        return dp[i][j];
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        m = matrix.size(), n = matrix[0].size();
        
        memset(dp, 0, sizeof(dp));
        
        int ans = INT_MIN;
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                int len = dfs(i,j,matrix);
                ans = max(ans, len);
            }
        }
        
        return ans + 1;
        
    }
};