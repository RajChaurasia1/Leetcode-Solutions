class Solution {
public:
    bool canJump(vector<int>& nums) {
         int n = nums.size();
        if(n == 1)
            return true;
         int jumps = 0, farthest = 0, currEnd = 0;
    for(int i=0;i<= farthest;i++)
    {
        farthest = max(farthest, i + nums[i]);
        if(farthest >= n-1)
            return true;
        
        if(i == farthest)
            return false;
        
        if(i == currEnd)
        {
            jumps++;
            currEnd = farthest;
        }
    }
    return false;
    }
};