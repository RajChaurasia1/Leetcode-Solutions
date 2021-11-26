class Solution {
public:
    int seg(vector<int>&nums){
        int j = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] <= 0)
                swap(nums[i],nums[j++]);
        }
        return j;
    }
    int firstMissingPositive(vector<int>& nums) {
        int shift = seg(nums);
        int sz = nums.size() - shift;
        nums = vector<int>(nums.begin() + shift, nums.end());
        
        for(int i = 0 ; i < sz ; i++){
            if(abs(nums[i]) - 1 < sz && nums[abs(nums[i]) - 1] > 0)
                nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
        }
        
        for(int i = 0 ; i < sz ; i++)
            if(nums[i] > 0)
                return i + 1;
        
        return sz + 1;
    }
};