class Solution {
public:
    
    //VARIATION OF HOUSE ROBBER PROBLEM//
    int deleteAndEarn(vector<int>& nums) {
       if(nums.size() == 1)
            return nums[0];
        
        int n = *max_element(nums.begin(),nums.end());
        vector<int> count(n+1, 0);   // stores count of each number wrt that number
        vector<int> dp(n+1);   // ith element stores ans if max element is till that index number
        
        for(int i=0; i<nums.size();++i)
            count[nums[i]]+= nums[i];
        
        dp[0] = 0;
        dp[1] = count[1];
        
        for(int i = 2; i < count.size(); ++i)
            dp[i] = max(dp[i - 2] + count[i], dp[i - 1]);
        
        return dp[n];
            
    }
};