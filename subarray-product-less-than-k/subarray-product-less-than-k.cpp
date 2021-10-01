class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
int sizeArr= nums.size();
        
       
        int si = 0;
        int ei = 0;
        long long p = 1;
        int ans =0;
        
        while(si < sizeArr && ei < sizeArr ){
                
            p*=nums[ei];

            while(si <= ei && p >= k){
                p/=nums[si];
                si++;
            }
       
            if(p < k){
                ans += (ei - si + 1);
            }
            ei++;
            
        }
        return ans;
        
        
    }
};