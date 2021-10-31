class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int curr_sum = 0, ans = 0;
        for(auto i : nums){
            
            curr_sum += i;
            
            if(curr_sum == k)
                ++ans;
            
            if(mp.find(curr_sum - k) != mp.end())
                ans += mp[curr_sum - k];
            
            ++mp[curr_sum];
            
        }
        
        return ans;
    }
};