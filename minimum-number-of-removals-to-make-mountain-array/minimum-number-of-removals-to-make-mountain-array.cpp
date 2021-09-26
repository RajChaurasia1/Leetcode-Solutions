class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        
        int n = size(nums);
        
        int lis[n],lds[n];
        
        for(int i = 0 ; i < n ; i++)
            lis[i] = 1, lds[i] = 1;
        
        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                if(nums[i] > nums[j] && lis[i] < lis[j] + 1){
                    lis[i] = lis[j] + 1;
                }
            }
        }
        
        for(int i = n - 2 ; i >= 0 ; i--){
            for(int j = n - 1 ; j > i ; j--){
                if(nums[i] > nums[j] && lds[i] < lds[j] + 1){
                    lds[i] = lds[j] + 1;
                }
            }
        }
        
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
          if(lis[i] > 1 && lds[i] > 1)
            ans = max(ans,lis[i] + lds[i] - 1);
          //    cout << " i " << i << " " << lis[i] << " " << lds[i] << " " << ans << endl;
        }
      //  cout << ans << endl;
        return n - ans;
        
    }
};