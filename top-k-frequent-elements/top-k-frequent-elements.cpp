class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        vector<int>ans;
        vector<pair<int,int>>v;
        for(auto i : nums){
            mp[i]++;
        }
        for(auto x : mp){
            v.push_back({x.second,x.first});
        }
        
        sort(begin(v),end(v),[](pair<int,int>&a,pair<int,int>&b){
            return a.first > b.first;
        });
        
        for(int i = 0 ; i < k; i++){
            ans.push_back(v[i].second);
        }
        return ans;
    }
};