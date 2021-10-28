class Solution {
public:
    int partition = 0;
    bool part(int i, vector<bool>&vis, vector<int>&nums, int k, int curr_sum, int sum){
        
        if(k == 0)
            return true;
        if(sum == curr_sum)
            return part(0, vis, nums, k - 1, 0, sum);
        
        for(int j = i ; j < nums.size() ; j++){
            if(curr_sum + nums[j] > sum || vis[j])
                continue;
            vis[j] = true;
            if(part(j + 1, vis,nums,k, curr_sum + nums[j], sum))
                return true;
            vis[j] = false;
        }
            
        return false;
    }
    
    
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        
        for(int i = 0 ; i < nums.size() ; i++){
            sum += nums[i];
        }
        
        if(sum % k != 0)
            return false;
        
        sum/=k;
        
        vector<bool>vis(nums.size(),false);
        
        return part(0, vis, nums, k, 0, sum);
    }
};