class Solution {
public:
    int numSquares(int n) {
        vector<int>v;
        for(int i = 1 ; i*i <= n ; i++){
            v.push_back(i*i);
        }
        
        int m = v.size();
        int dp[m + 1][n + 1];
        
        for(int i = 0 ; i < m + 1 ; i++)
            dp[i][0] = 0;
        
        for(int i = 0 ; i < n + 1 ; i++)
            dp[0][i] = INT_MAX - 1;
        
        
        for(int i = 1 ; i < m + 1 ; i++){
            for(int j = 1 ; j < n + 1 ; j++){
                if(j >= v[i - 1])
                    dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - v[i - 1]]);
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        
        
        return dp[m][n];
        
    }
};