class Solution {
public:
    
    
    int helper(vector<int>&nums, int k){
        unordered_map<int,int>mp;
        int ans = 0, s = 0;
        for(auto i : nums){
            mp[i]++;
            
            while(mp.size() > k){
                mp[nums[s]]--;
                
                if(mp[nums[s]] == 0)
                    mp.erase(nums[s]);
                
                ++s;
            }
            
            ans += (i - s + 1);
            
        }
        
        return ans;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums,k) - helper(nums,k - 1);
    }
};