class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        
        int n = nums.size(), ans = INT_MAX;
        
        int s = 0;
        int sum = 0;
       
        for(int i = 0 ; i < n ; i++){
            sum += nums[i];
            
            while(sum >= target){
                ans = min(i - s + 1, ans);
                sum -= nums[s];
                s++;
            }
        }
        if(ans != INT_MAX)
        return ans;
        
        return 0;
    }
};