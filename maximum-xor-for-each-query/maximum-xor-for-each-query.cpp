class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
       
        int n = nums.size();
        vector<int>xr(n);
        int Xr = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            Xr^=nums[i];
            xr[i] = Xr;
            
        }
        vector<int>res;
        for(int i = 0 ; i < n ; i++){
            
            int bitid = maximumBit, ans = 0;
            bitid--;
            while(bitid >= 0){
               // cout << (1<<bitid) <<endl;
                int bit = (xr[i] & (1 << bitid));
                if(!bit)
                    ans|=(1<<bitid);
                
                bitid--;
            }
          
            
            res.push_back(ans);
        }
        
        reverse(begin(res),end(res));
        return res;
        
    }
};