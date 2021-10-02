class Solution {
public:
    int n;
    bool isvalid(vector<int>&nums, int m, int mx){
        
        long long cnt = 1, sum = 0;
        
        for(int i = 0 ; i < n ; i++){
            sum += nums[i];
            if(sum > mx){
                sum = nums[i];
                cnt++;
            }
            if(cnt > m)
                return false;
        }
        return true;
        
    }
    int splitArray(vector<int>& nums, int m) {
        
        n = size(nums);
        long long int mx = INT_MIN, sum = 0;
        for(int i = 0 ; i < n ; i++){
            
            sum += nums[i];
            if(mx < nums[i])
                mx = nums[i];
            
            
        }
        
        long long start = mx , end = sum, ans = -1;
        
        while(start <= end){
            long long int mid = start + (end - start)/2;
            if(isvalid(nums,m,mid)){
                ans = mid;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return ans;
    }
};