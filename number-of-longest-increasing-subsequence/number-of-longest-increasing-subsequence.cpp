class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = size(nums), mx = INT_MIN;
        vector<pair<int,int>>lis(n,{1,1});
        
        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                if(nums[i] > nums[j] && lis[i].first < lis[j].first + 1){
                    lis[i].first = lis[j].first + 1;
                    lis[i].second = lis[j].second;
                    
                }
                else if(nums[i] > nums[j]){
                    if(lis[i].first == lis[j].first + 1){
                         lis[i].second += lis[j].second;
                    }
                }
                
                
            }
            mx = max(lis[i].first,mx);
        }
        
        int ans = 0;
       // cout << mx << endl;
        for(int i = 0 ; i < n ; i++){
            //cout << lis[i].first << " " << lis[i].second << endl;
            ans += (lis[i].first == mx)?lis[i].second : 0;}
        if(!ans)
            return 1;
        return ans;
    }
};