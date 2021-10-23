class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i = 0 ; i < nums.size(); i++){
            mp[nums[i]]++;
            pq.push({nums[i],mp[nums[i]]});
            
            if(pq.size() > k)
                pq.pop();
        }
        
        return pq.top().first;
    }
};