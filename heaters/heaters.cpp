class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        
        long long int mxn = 2*1e9 + 1;
        int64_t ans = 0;
        vector<int>rheaters(heaters.size());
        sort(begin(heaters),end(heaters));
        for(int i = 0 ; i < heaters.size() ; i++){
            rheaters[heaters.size() - i - 1] = -1*heaters[i];
        }
        heaters.push_back(mxn);
        rheaters.push_back(mxn);
        
        for(int i = 0 ; i < houses.size() ; i++){
           int idx = lower_bound(begin(heaters),end(heaters),houses[i]) - begin(heaters);
            
            int64_t distf = abs(houses[i] - (int64_t)heaters[idx]);
            
            idx = lower_bound(begin(rheaters),end(rheaters),-houses[i]) - begin(rheaters);
            
            int64_t distb = abs(houses[i] + (int64_t)rheaters[idx]);
            
            
            ans = max(ans,min(distf,distb));
        }
        
        return ans;
    }
};