class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
     
        int ans = INT_MIN;
        
        priority_queue<pair<int,int>>pq;
        
        for(auto point : points){
            while(!pq.empty() && point[0] - pq.top().second > k)
                pq.pop();
            if(!pq.empty())
                ans = max(ans, point[0] + point[1] + pq.top().first);
            pq.push({point[1] - point[0], point[0]});
        }
        
        return ans;
        
    }
};