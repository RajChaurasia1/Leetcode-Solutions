class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
         int n = nums1.size(), m = nums2.size();
        
         priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
         
        for(int i = 0 ; i < n ; i++)
            pq.push({nums1[i] + nums2[0],{i,0}});
        
        
        vector<vector<int>>ans;
        
        while(!pq.empty()){
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            ans.push_back({nums1[i],nums2[j]});
            
             if(ans.size() == k)
                 return ans;
            
            if(j + 1 < m)
                pq.push({nums1[i] + nums2[j + 1],{i, j + 1}});
            
        }
        
        return ans;
        
    }
};