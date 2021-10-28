class Solution {
public:
    int m, n;
    int dp[71][4901];
    
    int mindiff(int sum, int i, vector<vector<int>>&mat, int target){
        if(i >= m)
            return abs(sum - target);
        if(dp[i][sum] != -1)
            return dp[i][sum];
        int ans = INT_MAX;
        for(int j = 0 ; j < n ; j++){
            ans = min(ans, mindiff(sum + mat[i][j], i + 1, mat, target));
        }
        
        return dp[i][sum] = ans ;
    }
    
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        
        m = mat.size(), n = mat[0].size();
        
        memset(dp,-1,sizeof(dp));
        return mindiff(0, 0, mat, target);
        
        
    }
};