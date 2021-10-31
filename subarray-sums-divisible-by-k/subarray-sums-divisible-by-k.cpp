class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0, ans = 0;
        int mod[k];
        memset(mod,0,sizeof(mod));
        for(auto i : nums){
           
            sum += i;
            
            mod[((sum %k) + k) % k]++;
            
        }
        
        for(int i = 0 ; i < k ; i++){
            if(mod[i] > 1){
                ans += (mod[i]*(mod[i] - 1))/2;
            }
        }
        
        ans += mod[0];
        
        return ans;
        
    }
};