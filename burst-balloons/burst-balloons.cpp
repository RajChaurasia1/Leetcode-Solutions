class Solution {
public:
    

    
    int maxCoins(vector<int>& nums) {
        
        int n = nums.size();
        
        int dp[n + 1][n + 1];
        
        memset(dp,-1,sizeof(dp));
        
        for(int g = 0 ; g < n ; g++){
            for(int i = 0 , j = g ; i < n && j < n ; i++,j++){
                
                int mx = INT_MIN;
                
                for(int k = i ; k <= j ; k++){
                    int left = (k == i ? 0 : dp[i][k - 1]);
                    int right = (k == j ? 0 : dp[k + 1][j]);
                    
                    int money = (i == 0 ? 1 : nums[i - 1])*nums[k]*(j == n - 1 ? 1 : nums[j + 1]);
                    
                    int total = left + money + right;
                    
                    if(mx < total)
                        mx = total;
                    
                }
                
                
                dp[i][j] = mx;
                
                
            }
        }
        
        return dp[0][n - 1];
        
    }
};