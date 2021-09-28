class Solution {
public:
    
     int dp[201][201];
    int n;
    int minpath(vector<vector<int>>&matrix, int i, int j){
        if(i >= n)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans = INT_MAX;
        
        for(int idx = -1 ; idx <= 1 ; idx++){
           if(j + idx >= 0 && j + idx < n){
            int a = matrix[i][j] + minpath(matrix,i + 1,j + idx);
            ans = min(ans,a);
            }
        }
        
        return dp[i][j] = ans;
    }
    
    
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        n = matrix.size();
        memset(dp,-1,sizeof(dp));
        int ans = INT_MAX;
           if(n == 1){
    
            for(int j = 0; j < n ; j++)
                ans = min(ans,matrix[0][j]);
            
            return ans;
        }
        
        for(int j = 0; j < n ; j++){
            ans = min(ans,minpath(matrix,0,j));
        }
            
        return ans;
        
    }
};