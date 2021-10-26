class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size(), mn = INT_MAX, ans = 0;
        
        
        for(int i = 0 ; i < n ; i++){
            mn = min(mn, nums[i]);
            
        }
        
        
        for(int i = 0 ; i < n ; i++){
            ans += abs(mn - nums[i]);
        }
        
        return ans;
        
        
        
    }
};