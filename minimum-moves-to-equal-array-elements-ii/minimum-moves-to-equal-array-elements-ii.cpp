class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        sort(begin(nums),end(nums));
        
        int mid = (nums.size())/2;
        long long ans = 0;
        
        
        for(int i = 0 ; i < nums.size() ; i++){
            ans += abs(nums[i] - nums[mid]);
        }
        
        return ans;
        
    }
};