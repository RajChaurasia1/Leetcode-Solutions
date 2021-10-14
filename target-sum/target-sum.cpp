class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();
        int sum = 0;
        
        for(int i = 0 ; i < n ; i++)
            sum += nums[i];
        
        
        if((target + sum) % 2 != 0 || (target + sum) < 0)
            return 0;
        
        int s = (target + sum)/2;
        
        int dp[n + 1][s + 1];
        
        
        for(int i = 0 ; i < n + 1 ; i++)
            dp[i][0] = 1;
        
        for(int i = 1 ; i < s + 1 ; i++)
            dp[0][i] = 0;
        
        
        
        for(int i = 1 ; i < n + 1 ; i++){
            for(int j = 0 ; j < s + 1 ; j++){
 
                
                if(j >= nums[i - 1])
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i- 1][j];
            }
        }
        
        
        return dp[n][s];
        
        
    }
};