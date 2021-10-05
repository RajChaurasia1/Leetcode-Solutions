class Solution {
public:
    int pos(vector<int>&nums, int mid){
        int sum = 0;
        
        for(int i = 0 ; i < nums.size() ; i++){
            sum += ((nums[i] + mid - 1)/mid);
        }
        
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = size(nums), ans;
        
        int l = 1, r = INT_MIN;
        
        for(int i = 0 ; i < n ; i++)
            if(r < nums[i])
                r = nums[i];
        
        ++r;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(pos(nums,mid) <= threshold){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
};